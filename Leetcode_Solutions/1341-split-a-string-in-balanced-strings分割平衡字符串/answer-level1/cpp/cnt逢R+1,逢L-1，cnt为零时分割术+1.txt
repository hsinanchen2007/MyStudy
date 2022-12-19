### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int balancedStringSplit(string s) {
        int sum=0,cnt=0;
        for(auto a:s){
            if(a=='R') ++cnt;
            if(a=='L') --cnt;
            if(cnt==0) ++sum;
        }
        return sum;
    }
};
```