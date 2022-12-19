### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0;
        long j = sqrt(c);
        while(i <= j) {
            int sum = i*i + j*j;
            if(sum == c) {
                return true;
            }

            if(sum < c) {
                i++;
            }

            if(sum > c) {
                j--;
            }
        }

        return false;
    }
};
```