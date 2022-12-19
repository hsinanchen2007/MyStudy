### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        while (num != 0) {
            if (num % 2 == 0) {
                num /= 2;
            }
            else {
                num--;
            }
            steps++;
        }
        return steps;
    }
};
```