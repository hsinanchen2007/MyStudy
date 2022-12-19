![1.png](https://pic.leetcode-cn.com/429646ca6afcdd8a512e4bf33605f8f75cc538251db5b45fca3dd734a220dd4b-1.png)

### 代码
```cpp
class Solution {
public:
    int findComplement(int num) {
        int tmp = 1;
        while(tmp < num){
            tmp <<= 1;
            tmp += 1;
        }
        return (num^tmp);
    }
};
```