### 解题思路
首先建立字符与整数对应的map，定义一个用来存储加数项正负的数组，先遍历一次字符串，比较相邻的两个字符，若左边的字符小于右边的字符，则左边字符的符号为负，右边字符的符号为正，否则两个字符的符号都为正。最后将所有加数项相加即可得出结论，时间复杂度为log(n).

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int outcome = 0;
    int a[100];
    for(int i=0;i<s.length()-1;i++)
    {
        if(mp[s[i]]<mp[s[i+1]])
        {
            a[i]=-1;
            a[i+1]=1;
        }
        else
        {
            a[i]=1;
            a[i+1]=1;
        }
    }
    for(int i=0;i<s.length();i++)
    {
        outcome +=mp[s[i]]*a[i];
    }
    return outcome;
        
    }
};
```