#ifndef SG_SAVEDATA_H
#define SG_SAVEDATA_H

#ifdef NEVER_EXIST

#include <stdio.h>
#include <map>
#include <string>
#include <vector>

using namespace std;

/*
���̺� ������ ������ ���� Ŭ����
*/
class CSaveData{
public:
	CSaveData();
	~CSaveData();

	/*
	������ ���Ͽ� ���� CSaveData Ŭ������ �����Ѵ�.
	*/
	static CSaveData *create(const char *);

	/*
	�ش� ������ ����.
	*/
	bool open(const char *file);
	/*
	������ �ݴ´�.
	*/
	void close();

	/*
	����� ���� �����´�.
	*/
	void *get(const char *name);
	/*
	���� �����Ѵ�.
	*/
	void set(const char *name,void *data,int len);

	/*
	�޸��� �����͸� ��ũ�� ����Ѵ�.
	*/
	void save();

	enum DataType {
		INT,
		FLOAT,
		STRING
	};

private:

	void parse();

private:
	struct Datum{
		void *data;
		int len;
	};

	map<string,Datum> data;
	FILE *fp;
};

#endif

#endif // SG_SAVEDATA_H
