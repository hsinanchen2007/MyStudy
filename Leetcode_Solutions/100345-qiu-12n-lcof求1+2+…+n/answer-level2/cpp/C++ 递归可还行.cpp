### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int sumNums(int n) {
        if(n==1)
            return 1;
        return n+sumNums(n-1);
    }
};
```