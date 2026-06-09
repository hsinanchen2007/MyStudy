### 解题思路
![image.png](https://pic.leetcode-cn.com/c0f318d153424bdb8fedea01d3710cc22fbef7f105a88bbe73b6e9e7c531245d-image.png)


### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for(auto c : s){
            if(c == ' ')
                res += "%20";
            else
                res += c;
        }
        return res;
    }
};
```