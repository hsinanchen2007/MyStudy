### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n%2!=0&&n!=1||n==0) return false;
        else if(n==2 || n==1) return true;
        else return 1*isPowerOfTwo(n/2);
    }
};
```