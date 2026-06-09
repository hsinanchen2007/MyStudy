### 解题思路
常规manache算法是解决字符串中的最长回文子串问题，但是同时会生成每个位置为中心的最大回文串半径parr[i]，最小也是1（仅包含自己本身），对应其原始串的半径是parr[i]/2；将所有累加起来就是所求的个数

### 代码

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        if(s.size()<1)
            return 0;
        string cstr=manacherstr(s);
        vector<int> parr(cstr.size(),0);
        int index=-1;
        int pr=-1;
        int res=0;
        for(int i=0;i<cstr.size();i++)
        {
            parr[i]=pr>i?min(parr[2*index-i],pr-i):1;
            //if()
            while((i+parr[i]<cstr.size())&&(i-parr[i]>-1))
            {
                if(cstr[i+parr[i]]==cstr[i-parr[i]])
                    parr[i]++;
                else
                    break;
            }
            if(pr<i+parr[i])
            {
                pr=i+parr[i];
                index=i;
            }
        }
        for(int i=0;i<parr.size();i++)
        {
            res+=parr[i]/2;
        }
        return res;
    }
    string manacherstr(string s)
    {
        string res = "#";
		//res += '#';
		//res += '#';
		for (int i = 0; i<s.size(); i++)
		{
			res += s[i];
			res += '#';
		}
		//res += s[s.size() - 1];
		//res += '$';
		return res;
    }
};
```