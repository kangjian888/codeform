#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include <iterator>
#include<regex>
#include<boost/regex.hpp>
#include <boost/lexical_cast.hpp>


int main(int argc, char* argv[])//两个系统参数，一个是读入的文件，另一个是输出的文件
{
	using namespace std;
	if (argc == 1)
	{
		cerr << "Usage:" << argv[0] << "filename[s]\n";
		exit(EXIT_FAILURE);
	}

	ifstream fin;
	long count;
	string text;//写一个字符串的对象
	string code;//将所有的字符拼在一起
	string line("\n");

	fin.open(argv[1]);
	if (!fin.is_open())
	{
		cerr << "could not open" << argv[1] << endl;
		fin.clear();
	}
	count = 0;
	getline(fin, text, '\n');
	text = text + line;
	while (fin)
	{
		if (text.size() != 0)
		{
			count++;
		}
		//cout << count << ":" << text << endl;
		code = code + text;//string对象重载了+和=
		getline(fin, text);
		text = text + line;
	}
	//cout << code << endl;
	cout << count << " line in" << argv[1] << endl;
	fin.clear();
	fin.close();
	/*中间就是对于输入文件的字符串的处理*/

	string s1("if");
	string s2(";");
	string s3("{");
	string s4("(");
	string s5(")");
	string s6("}");
	code = code + "\n{from kangjian}";
	int pos_if = 1;
	while (pos_if >= 1)
	{
		int pos_semicolon = 0;
		int pos_brace = 0;
		pos_if = code.find(s1, pos_if);
		pos_semicolon = code.find(s2, pos_if);
		pos_brace = code.find(s3, pos_if);
		if (pos_semicolon < pos_brace)
		{
			string sub_string = code.substr(pos_if, pos_semicolon - pos_if + 1);
			int num_Parenthesis = 0;
			int pos_Parenthesis = 0;
			int pos_temp1 = 0, pos_temp2 = 0;
			do
			{
				pos_temp1 = sub_string.find(s4, pos_Parenthesis);
				pos_temp2 = sub_string.find(s5, pos_Parenthesis);

				//cout <<pos_temp1 << endl;
				//cout << pos_temp2 << endl;

				if ((pos_temp1 < pos_temp2) && (pos_temp1 != -1))
				{
					num_Parenthesis += 1;
					pos_Parenthesis = pos_temp1 + 1;
				}
				if ((pos_temp2 < pos_temp1) || pos_temp1 == -1)
				{
					num_Parenthesis -= 1;
					pos_Parenthesis = pos_temp2 + 1;
				}
				//cout << num_Parenthesis << endl;

			} while (num_Parenthesis);
			code.insert(pos_if + pos_Parenthesis + 1, s3);
			code.insert(pos_semicolon + 2, s6);
		}
		//cout << pos_if << endl;
		pos_if = pos_if + 1;
	}
	string s7("while");
	int pos_while = 1;
	while (pos_while >= 1)
	{
		int pos_semicolon = 0;
		int pos_brace = 0;
		pos_while = code.find(s7, pos_while);
		pos_semicolon = code.find(s2, pos_while);
		pos_brace = code.find(s3, pos_while);
		if (pos_semicolon < pos_brace)
		{
			string sub_string = code.substr(pos_while, pos_semicolon - pos_while + 1);
			int num_Parenthesis = 0;
			int pos_Parenthesis = 0;
			int pos_temp1 = 0, pos_temp2 = 0;
			do
			{
				pos_temp1 = sub_string.find(s4, pos_Parenthesis);
				pos_temp2 = sub_string.find(s5, pos_Parenthesis);

				cout <<pos_temp1 << endl;
				cout << pos_temp2 << endl;

				if ((pos_temp1 < pos_temp2)&&(pos_temp1 != -1))
				{
					num_Parenthesis += 1;
					pos_Parenthesis = pos_temp1 + 1;
				}
				if ((pos_temp2 < pos_temp1)||(pos_temp1 == -1))
				{
					num_Parenthesis -= 1;
					pos_Parenthesis = pos_temp2 + 1;
				}
				//cout << num_Parenthesis << endl;

			} while (num_Parenthesis);
			code.insert(pos_while + pos_Parenthesis + 1, s3);
			code.insert(pos_semicolon + 2, s6);
		}
		//cout << pos_while << endl;
		pos_while = pos_while + 1;
	}


	string s8("else if");
	int pos_elseif = 1;
	while (pos_elseif >= 1)
	{
		int pos_semicolon = 0;
		int pos_brace = 0;
		pos_elseif = code.find(s1, pos_elseif);
		pos_semicolon = code.find(s2, pos_elseif);
		pos_brace = code.find(s3, pos_elseif);
		if ((pos_semicolon < pos_brace))
		{
			string sub_string = code.substr(pos_elseif, pos_semicolon - pos_elseif + 1);
			int num_Parenthesis = 0;
			int pos_Parenthesis = 0;
			int pos_temp1 = 0, pos_temp2 = 0;
			do
			{
				pos_temp1 = sub_string.find(s4, pos_Parenthesis);
				pos_temp2 = sub_string.find(s5, pos_Parenthesis);

				//cout <<pos_temp1 << endl;
				//cout << pos_temp2 << endl;

				if ((pos_temp1 < pos_temp2) && (pos_temp1 != -1))
				{
					num_Parenthesis += 1;
					pos_Parenthesis = pos_temp1 + 1;
				}
				if ((pos_temp2 < pos_temp1) || pos_temp1 == -1)
				{
					num_Parenthesis -= 1;
					pos_Parenthesis = pos_temp2 + 1;
				}
				//cout << num_Parenthesis << endl;

			} while (num_Parenthesis);
			code.insert(pos_elseif + pos_Parenthesis, s3);
			code.insert(pos_semicolon + 2, s6);
		}
		//cout << pos_elseif << endl;
		pos_elseif = pos_elseif + 1;
	}

	cout << code << endl;
	/*
	ofstream fout(argv[2]);
	if (!fout.is_open())
	{
	cerr << "can't open " << argv[2] << "file for output!\n";
	exit(EXIT_FAILURE);
	}
	fout << code << endl;
	fout.clear();
	fout.close();

	*/
	return 0;
}



