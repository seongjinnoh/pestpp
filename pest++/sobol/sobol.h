#ifndef SOBOL_H_
#define SOBOL_H_

#include <vector>
#include <string>
#include <Eigen/Dense>
#include "Transformable.h"
using Eigen::MatrixXd;
using Eigen::VectorXd;

class ParamTransformSeq;
class RunManagerAbstract;
class ModelRun;

class Sobol
{
public:
	Sobol(RunManagerAbstract *run_manager_ptr, const std::vector<std::string> &_adj_par_name_vec, const Parameters &_fixed__ctl_pars,
		const Parameters &_lower_bnd, const Parameters &_upper_bnd, ParamTransformSeq *base_partran_seq, int n_sample);
	void assemble_runs();
	void calc_sen();
private:
	VectorXd gen_uniform_rand_vec(long nsample, double min, double max);
    void gen_m1_m2();
	MatrixXd gen_N_matrix(const MatrixXd &m1, const MatrixXd &m2, const vector<int> &idx_vec);
	void add_model_runs(const MatrixXd &n);
	VectorXd Sobol::get_exp_val(int run_set);
	int n_sample;
	std::vector<std::string> adj_par_name_vec;
	Parameters fixed_ctl_pars;
    Parameters lower_bnd;
    Parameters upper_bnd;
	RunManagerAbstract *run_manager_ptr;
	ParamTransformSeq *base_partran_seq;
    Eigen::MatrixXd m1;
    Eigen::MatrixXd m2;
};
#endif SOBOL_H_