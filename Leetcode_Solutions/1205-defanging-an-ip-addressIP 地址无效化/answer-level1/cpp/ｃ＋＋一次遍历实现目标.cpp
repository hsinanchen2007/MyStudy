
***利用string类的成员函数ｆｉｎｄ和ｉｎｓｅｒｔ只需遍历一遍字符串ａｄｄｒｅｓｓ即可完成任务；***
string defangIPaddr(string address)
	{
		int indx=0,i=0;
		string temp = address;
		while ((indx = temp.find('.',indx+i)) != temp.npos)
		{
			temp.insert(indx, "[");
			temp.insert(indx+2, "]");
			i += 2;
			
		}
		return temp;
	}
	
};