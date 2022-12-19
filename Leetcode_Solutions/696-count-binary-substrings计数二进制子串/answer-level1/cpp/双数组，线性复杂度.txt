### 解题思路
使用两个数组保存字符串的有关信息，
其中num[i]表示从下标i开始，和s[i]相等且连续的子串长度；
index[i]表示第一个和s[i]不同的字符下标。
于是，只需要判断**num[i]<=num[index[i]]**，即可知道下标为i是否存在满足题意的子串。
### 代码

```cpp
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0;
        int *num=new int[s.size()+1];
        int *index=new int[s.size()+1];
        h(s,0,num,index);
        for(int i=0;i<s.size();i++)
        {
            if(index[i]<s.size()&&num[i]<=num[index[i]])
            ans++;
        }
        return ans;
    }
    void h(string str,int s,int *num,int *index)
    {
        int i=s;
        while(i<str.size())
        {
            while(i<str.size()&&str[i]==str[s])
        {
            i++;
        }
        for(int j=s;j<i;j++)
        {
            num[j]=i-j;
            index[j]=i;
        }
        s=i;
        }
    }
};
```