### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1)return 1;
        if(n>0&&!(n%3))return isPowerOfThree(n/3);
        else return 0;
    }
};
```