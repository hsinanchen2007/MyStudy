### 解题思路
首先按照vector中字符串长度的顺序给vector按照由短到长的顺序排序
然后vector中第一项一定是最短的
用第一项的每一位和vector中剩下的所有的字符串从开头开始逐字符对比
直到出现前缀不同的时候退出，返回s
PS：用s作前缀字符串的存储，用flag来标记循环结束的位置
### 代码

```cpp
class Solution {
public:
    static bool cmp(const string &a, const string &b)
    {
        return a.length()<b.length();
    }

    string longestCommonPrefix(vector<string>& strs) {
        int flag=0;
        if(strs.empty()) return "";
        sort(strs.begin(),strs.end(),cmp);
        string s ="";
        string first=strs[0];
        int min_l = strs[0].length();
        for(int i=0;i<min_l;i++)
        {
            for(int j=1;j<strs.size();j++)
            {
                //cout<<strs[j]<<" ";
                if(first[i]!=strs[j][i]) 
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)break;
            s+=first[i];
        }
        return s;
    }
};
```