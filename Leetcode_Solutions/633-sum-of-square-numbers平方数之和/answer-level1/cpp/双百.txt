### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public: 
    bool judgeSquareSum(int c) {
        long b = pow(c, 0.5);
        long a = 0;
        while(a <= b) {
            long sum = a * a + b * b;
            if(sum == c) {
                return true;
            }
            else if(sum < c) {
                a ++;
            }
            else {
                b --;
            }
        }
        return false;
    }
};
```