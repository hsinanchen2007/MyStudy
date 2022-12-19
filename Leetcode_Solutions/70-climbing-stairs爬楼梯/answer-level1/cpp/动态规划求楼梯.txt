### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int step[10000];
        step [0] = 1;
        step [1] = 2;
        if (n == 1){
            return step[0];
        }
        else if (n == 2){
            return step[1];
        }else{
            int i = 2;
            for (; i < n; i++) 
                 step[i] = step[i-1] + step [i-2];
            return step[i-1];
        }
        
    }
};
```