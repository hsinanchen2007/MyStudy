### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.length()!=s2.length())
        return false;
        map<char,int> t1,t2;
        for(int i=0;i<s1.length();i++)
        {
            t1[s1[i]]++;
            t2[s2[i]]++;
        }
        map<char,int>::iterator it1;
        for(it1=t1.begin();it1!=t1.end();it1++)
        {
            if(it1->second!=t2[it1->first])
                return false;
        }
        return true;
    }
};
```