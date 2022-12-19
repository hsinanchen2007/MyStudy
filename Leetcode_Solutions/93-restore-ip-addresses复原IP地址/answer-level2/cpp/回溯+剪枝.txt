执行用时 :4 ms, 在所有 cpp 提交中击败了89.18%的用户
内存消耗 :8.9 MB, 在所有 cpp 提交中击败了18.39%的用户

*整体思路*
1. 先用回溯往字符串上加3个小数点
2. 在回溯中剪枝可以加快很多速度
3. 再对加了小数点后的字符串分析
4. 对每个字符串的每个段落(小数点之间的数字)进行分析即可

思路很简单，看代码就行
```
class Solution {
public:
vector<string> restoreIpAddresses(string s) 
{
	int s_size=s.size();
	if (s_size<4 || s_size>12 || s=="0.0.0.0")
		return {};
	vector<string> possible_answer;
	get_ip_adderss(possible_answer,s,0,1);
	int possible_ip_size,possible_ip_part_size;
	vector<string> answer;
	bool judge;
	for (string possible_ip:possible_answer)
	{
		judge=true;
		possible_ip_size=possible_ip.size();
		int i=0;
		for (int j=0;j<4;++j)
		{
			possible_ip_part_size=0;
			while (i<possible_ip_size && possible_ip.at(i)!='.')
			{
				++i;
				++possible_ip_part_size;
			}
			++i;
			if (possible_ip_part_size==1)
				continue;
			else if (possible_ip_part_size==2 && possible_ip.at(i-3)=='0')
			{
				judge=false;
				break;
			}
			else if (possible_ip_part_size==3)
			{
				if (possible_ip.at(i-4)=='0' || possible_ip.at(i-4)>'2')
				{
					judge=false;
					break;
				}
				int temporary=0;
				for (int k=0;k<3;++k)
					temporary=temporary+(possible_ip.at(i-k-2)-'0')*pow(10,k);
				if (temporary>255)
				{
					judge=false;
					break;
				}
			}
			else if (possible_ip_part_size>3)
			{
				judge=false;
				break;
			}
		}
		if (judge==true)
			answer.push_back(string(possible_ip));
	}
	return answer;
}
void get_ip_adderss(vector<string>& possible_answer,string s,int point_exist,int start_position)
{
	if (point_exist==3)
	{
		possible_answer.push_back(string(s));
		return;
	}	
	string temporary_s;
	for (int i=0;i<3;++i)
	{
		temporary_s=s;
		if (start_position+i>=s.size())
			return;
		temporary_s.insert(temporary_s.begin()+start_position+i,'.');
		get_ip_adderss(possible_answer,temporary_s,point_exist+1,start_position+i+2);
	}
}
};
```
