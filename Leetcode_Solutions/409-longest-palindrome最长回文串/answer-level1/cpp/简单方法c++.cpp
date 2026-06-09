### 解题思路
计算每个字母的数量，如果个数大于一而且是2的倍数就加上这个数，如果大于一，但不是2的倍数，加上这个数减1，然后根据情况看看还要不要加一
### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()<=1)
        return s.size();
        map<char,int> test;
        for(auto a:s){
          ++test[a];
        }
        int count=0;
        map<char,int>::iterator it;
        bool flag=false;
        for(it=test.begin();it!=test.end();++it){
            if(it->second>=2&&(it->second)%2==0)
            count+=it->second;
            if(it->second>=2&&(it->second)%2==1){
                     count+=(it->second-1);
                     flag=true;
            }
            if(it->second==1)
            flag=true;
        }
        if(flag)
        ++count;
        return count;
    }
};
```