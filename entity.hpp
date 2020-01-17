#ifndef ENTITY
#define ENTITY

class Entity {
	int coef_size;
	double * coef;
public:
	double get_coef(int pos){if(pos < coef_size) return coef[pos];}
	double * get_coefs(){return coef;}
	int get_size(){return coef_size;}
	void set_coefs(double * coef_arg, int size){
		coef_size = size;

		delete coef;
		coef = new double[coef_size];
		
		for(int i = 0; i < size; i++)
		{
			coef[i] = coef_arg[i];
		}
	}

	void set_coef(int pos, double value)
	{
		if(coef && pos < coef_size)
		{
			coef[pos] = value;
		}
	}

	void allocate_coef(int size)
	{
		coef_size = size;
		coef = new double[size];
		for(int i = 0; i < size; i++)
		{
			coef[i] = 0;
		}
	}

	Entity * operator+(Entity * value)
	{
		Entity * new_entity = new Entity;
		double * new_coefs = new double[coef_size];
		for(int i = 0; i < coef_size; i++)
		{
			new_coefs[i] = coef[i] + value -> get_coef(i); 
		}
		new_entity.set_coefs(new_coefs, coef_size);
		return new_entity;		
	}

	Entity * operator*(Entity * value)
	{
		Entity * new_entity = new Entity;
		double * new_coefs = new double[coef_size];
		for(int i = 0; i < coef_size; i++)
		{
			new_coefs[i] = coef[i] * value -> get_coef(i); 
		}
		new_entity.set_coefs(new_coefs, coef_size);
		return new_entity;
	}

	Entity * operator-(Entity * value)
	{
		Entity * new_entity = new Entity;
		double * new_coefs = new double[coef_size];
		for(int i = 0; i < coef_size; i++)
		{
			new_coefs[i] = coef[i] - value -> get_coef(i); 
		}
		new_entity.set_coefs(new_coefs, coef_size);
		return new_entity;
	}
};

#endif