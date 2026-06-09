### 解题思路
![image.png](https://pic.leetcode-cn.com/8fd60f146613753876c06ed575a58b8646ab2b254e310a696efb56061804908b-image.png)

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for(auto ch:s){
            if(ch==' '){
                res+="%20";
            }else{
                res+=ch;
            }
        }
        return res;
    }
};
```