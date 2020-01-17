#ifndef ZNAK
#define ZNAK

class Znak {
	int type;
	/*
		0 - =
		1 - <=
		2 - >=
	*/
public:
	int type(){return type;}
	void set_type(int type_arg){type = type_arg;}
}

#endif