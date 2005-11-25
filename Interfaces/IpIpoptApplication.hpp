// Copyright (C) 2004, 2005 International Business Machines and others.
// All Rights Reserved.
// This code is published under the Common Public License.
//
// $Id$
//
// Authors:  Carl Laird, Andreas Waechter     IBM    2004-08-13

#ifndef __IPIPOPTAPPLICATION_HPP__
#define __IPIPOPTAPPLICATION_HPP__

#include "IpJournalist.hpp"
#include "IpTNLP.hpp"
#include "IpRegOptions.hpp"
#include "IpOptionsList.hpp"
#include "IpSolveStatistics.hpp"

namespace Ipopt
{
  /* Forward declaration */
  class NLP;

  /* Return codes for the Optimize call for an application */
#include "IpReturnCodes_inc.h"

  /** This is the main application class for making calls to Ipopt. */
  class IpoptApplication : public ReferencedObject
  {
  public:
    IpoptApplication(bool read_params_dat = true, bool create_console_out = true);

    virtual ~IpoptApplication();

    /**@name Solve methods */
    //@{
    /** Solve a problem that inherits from TNLP */
    ApplicationReturnStatus OptimizeTNLP(const SmartPtr<TNLP>& nlp);

    /** Solve a problem that inherits from NLP */
    ApplicationReturnStatus OptimizeNLP(const SmartPtr<NLP>& nlp);
    //@}

    /** Method for opening an output file with given print_level.
     *  Returns false if there was a problem. */
    bool OpenOutputFile(std::string file_name, EJournalLevel print_level);

    /**@name Accessor methods */
    //@{
    /** Get the Journalist for printing output */
    SmartPtr<Journalist> Jnlst()
    {
      return jnlst_;
    }

    /** Get the options list for setting options */
    SmartPtr<OptionsList> Options()
    {
      return options_;
    }

    /** Get the object with the statistics about the most recent
     *  optimization run. */
    SmartPtr<SolveStatistics> Statistics()
    {
      return statistics_;
    }
    //@}

    /** @name Methods for IpoptTypeInfo */
    //@{
    static void RegisterOptions(SmartPtr<RegisteredOptions> roptions);
    //@}

  private:
    /**@name Default Compiler Generated Methods
     * (Hidden to avoid implicit creation/calling).
     * These methods are not implemented and 
     * we do not want the compiler to implement
     * them for us, so we declare them private
     * and do not define them. This ensures that
     * they will not be implicitly created/called. */
    //@{
    /** Default Constructor */
    // IpoptApplication();

    /** Copy Constructor */
    IpoptApplication(const IpoptApplication&);

    /** Overloaded Equals Operator */
    void operator=(const IpoptApplication&);
    //@}

    /** Method to register all the options */
    void RegisterAllOptions(const SmartPtr<RegisteredOptions>& roptions);

    /**@name Variables that customize the application behavior */
    //@{
    /** Decide whether or not the PARAMS.DAT file should be read */
    bool read_params_dat_;
    //@}

    /** Journalist for reporting output */
    SmartPtr<Journalist> jnlst_;

    /** OptionsList used for the application */
    SmartPtr<OptionsList> options_;

    /** Object for storing statistics about the most recent
     *  optimization run. */
    SmartPtr<SolveStatistics> statistics_;
  };

} // namespace Ipopt

#endif