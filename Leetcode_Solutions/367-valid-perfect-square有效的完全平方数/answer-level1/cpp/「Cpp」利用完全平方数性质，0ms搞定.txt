![image.png](https://pic.leetcode-cn.com/ea733cff0e09740752ccd3a9e062c8bd61d4c77b1779e535943a6cd4f77824eb-image.png)

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        int num1 = 1;
        while (num > 0){
            num -= num1;
            num1 += 2;
        }
        return num == 0;

    }
};
```
