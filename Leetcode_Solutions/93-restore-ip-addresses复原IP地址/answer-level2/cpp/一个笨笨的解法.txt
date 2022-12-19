
```
class Solution{

public:
	vector<string> restoreIpAddresses(string s) {
		string ip="";
		vector<string> result;
		backtrack(s,0,0,ip,result);
		return result;
	}

	void backtrack(string s,int start,int step,string ip,vector<string> &res)
	{
		if(start==s.size() && step==4)
		{
			ip.erase(ip.end()-1);
			res.push_back(ip);
			return;
		}
		
		if(s.size()-start>(4-step)*3) return;
		if(s.size()-start<(4-step)) return;
		int num=0;
		for(int i=start;i<start+3;i++)
		{
			num =num*10+(s[i]-'0');
			if(num<=255)
			{
				ip+=s[i];
				backtrack(s,i+1,step+1,ip+'.',res);
			}
			if (num==0) break;
		}
	}
};
```
