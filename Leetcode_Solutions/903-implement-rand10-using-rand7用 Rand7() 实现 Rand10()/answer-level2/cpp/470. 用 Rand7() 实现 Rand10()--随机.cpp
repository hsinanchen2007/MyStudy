### 解题思路


### 代码

```cpp
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int x = 0;
        do{
            int row = rand7();
            int col = rand7();
            x = (row-1)*7 + col;
        }while(x > 40);
        return 1+(x-1)%10;
    }
};
```