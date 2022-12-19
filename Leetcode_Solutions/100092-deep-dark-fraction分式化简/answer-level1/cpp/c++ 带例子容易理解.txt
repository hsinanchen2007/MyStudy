记录上一次计算后的分子num，分母deo。按数组cont逆序进行计算，分子等于上一个数的分母（初值为1），分母等于num+deo*cont[i]。输出最后一次结果
例子{3,2,2,4} 
      分母      分子
1    4=4        1
2    1+4*2=9    4
3    4+9*2=22   9
4    9+22*3=75  22

输出{75,22}     




class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
	int deo = cont[cont.size()-1]; //分母
	int num = 1;                   //分子
	int temp;                      
	for (int i = cont.size()-1; i >= 1; i--)
	{
		temp = num;
		num = deo;
		deo = temp + num*cont[i-1];

	}
	return {deo,num};
    }
};