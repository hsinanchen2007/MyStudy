class Solution {
    public:
```
代码块
```
        int lengthOfLongestSubstring(string s) {
            string a="";
            int count=0;
            vector<int> b;
            for(int i=0; i<=s.size(); i++)
            {     
                int c =a.find(s[i]);
                if(c!=-1)
                {
                    b.push_back(count);
                    a.erase(a.begin(),a.begin()+c+1);
                    count=a.size();
                }
                else if(i==s.size())//没有重复字符的情况下，输出count
                    b.push_back(count);
                a.append(1,s[i]);
                count++;
            }  
            return *max_element(b.begin(),b.end());//使用<algorithm>中的函数
        }
};