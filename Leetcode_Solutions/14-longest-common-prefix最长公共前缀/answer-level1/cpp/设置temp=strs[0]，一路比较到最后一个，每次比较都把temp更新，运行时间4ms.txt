### 解题思路
["flower","flow","flight"]
temp="flower"
temp="flo"
temp="fl"
输出"fl"
第一次写完之后直接提交就AC了
### 代码

```cpp
class Solution {
public:
    int place(string s1,string s2) //函数palce输出的值的前面，s1和s2都相等，输出0说明第一个字符就不相等
    {
        int i=0;
        int n=min(s1.size(),s2.size());
        for(;i<n;)
        {
            if(s1[i]==s2[i])
                i++;
            else
            break;
        }
        return i;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0)
        return "";
        if(n==1)
        return strs[0];   //预处理
        string tmp=strs[0];
        for(int i=1;i<n;i++)
        {
            int k=place(tmp,strs[i]);
            if(k==0)
            return "";
            string tmp1(tmp,0,k);   
            tmp=tmp1;    //更新tmp
        }
        return tmp;
    }
};
```