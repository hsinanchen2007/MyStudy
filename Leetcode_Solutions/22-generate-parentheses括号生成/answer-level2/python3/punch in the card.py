### 解题思路

kick the card. 
Again, I will give you the code. 

### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        vector<vector<string>> tmp;
        vector<string>s1;
        s1.push_back("");
        tmp.push_back(s1);
        s1.pop_back();
        s1.push_back("()");
        tmp.push_back(s1);
        string s;
        for(unsigned long long i=2;i<(long long unsigned)(n+1);i++)
        {
            vector<string> test;
            for(unsigned long long j=0;j<i;j++)
            {
                for(unsigned long long k=0;k<tmp[j].size();k++)
                {
                    for(unsigned long long h=0;h<tmp[i-1-j].size();h++)
                    {
                        s="("+tmp[j][k]+")"+tmp[i-1-j][h];
                        test.push_back(s);
                    }
                }
                //for(unsigned long long k=0;i<tmp[j].size();k++)
                //{
                //    for(unsigned long long h=0;h<tmp[i-1-j].size();h++)
                //    {
                //        s=tmp[j][k]+"()";
                //        tmp[i-1].push_back(s);
                //}
            }
            tmp.push_back(test);
        }
        return tmp[n];
    }
};
```