### 解题思路
C++,map，只能有一个字母出现奇数次，放在中间

### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char,int> m;
        for(auto c:s){
            m[c]++;
        }
        int count=0;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second%2==1) count++;
        }
        return count<=1;
    }
};
```