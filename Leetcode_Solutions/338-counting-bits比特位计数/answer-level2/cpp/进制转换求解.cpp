#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//transfer函数
void transfer(int a,vector<int> &temp)
{
	int k = 0;
	int t = 0;
		k = (a / 2);
		t = a % 2;
		temp.push_back(t);
		while (k != 0)
		{
			transfer(k,temp);
			break;
		}
}

//进制转换
int main()
{
	vector<int> ans;
	int num=5;
	/*
	int i = 0;
	do{
		copy(ans.begin(),ans.end(),ostream_iterator<int>{cout," "});
		i++;
	} while (i != 2);
	*/

	vector<int> temp;
	int sum = 0;
	for (int i = 0; i <= num; i++)
	{
		if (i == 0)
		{
			temp.push_back(0);
		}
		else
		{
			if (i==1)
				temp.push_back(1);
			else
				transfer(i,temp);
		}
		
		for (int j = 0; j < int(temp.size()); j++)
		{
			sum = sum+temp[j];
		}
		ans.push_back(sum);
		sum = 0;
		temp.clear();
	}



	system("pause");
	return 0;
}


