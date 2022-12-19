 string intToRoman(int num) {
	string result;
	map<int,string> Roman;
    Roman.insert(pair<int, string>(0, ""));
	Roman.insert(pair<int, string>(1, "I"));
	Roman.insert(pair<int, string>(2, "II"));
	Roman.insert(pair<int, string>(3, "III"));
	Roman.insert(pair<int, string>(4, "IV"));
	Roman.insert(pair<int, string>(5, "V"));
	Roman.insert(pair<int, string>(6, "VI"));
	Roman.insert(pair<int, string>(7, "VII"));
	Roman.insert(pair<int, string>(8, "VIII"));
	Roman.insert(pair<int, string>(9, "IX"));
	Roman.insert(pair<int, string>(10, "X"));
	Roman.insert(pair<int, string>(20, "XX"));
	Roman.insert(pair<int, string>(30, "XXX"));
	Roman.insert(pair<int, string>(40, "XL"));
	Roman.insert(pair<int, string>(50, "L"));
	Roman.insert(pair<int, string>(60, "LX"));
	Roman.insert(pair<int, string>(70, "LXX"));
	Roman.insert(pair<int, string>(80, "LXXX"));
	Roman.insert(pair<int, string>(90, "XC"));
	Roman.insert(pair<int, string>(100, "C"));
	Roman.insert(pair<int, string>(200, "CC"));
	Roman.insert(pair<int, string>(300, "CCC"));
	Roman.insert(pair<int, string>(400, "CD"));
	Roman.insert(pair<int, string>(500, "D"));
	Roman.insert(pair<int, string>(600, "DC"));
	Roman.insert(pair<int, string>(700, "DCC"));
	Roman.insert(pair<int, string>(800, "DCCC"));
	Roman.insert(pair<int, string>(900, "CM"));
	Roman.insert(pair<int, string>(1000, "M"));
	Roman.insert(pair<int, string>(2000, "MM"));
	Roman.insert(pair<int, string>(3000, "MMM"));
	
	int i=0;
	int x=num;
	while(x>10)
	{
		x/=10;
		i++;
	}
	//i是最高位数，//从高位往低位循环
	while(i>=0)
	{
		//先取得最高位数字
		int a=pow(double(10),double(i));//a=100
        if(num%a==0)
		{
			return result.insert(result.size(),Roman.at(num));
			break;
		}
		int temp=num-num%a;
		//取得temp对应的字符
		result.insert(result.size(),Roman.at(temp));
		num-=temp;
		i--;
	
	}
	return result;
}