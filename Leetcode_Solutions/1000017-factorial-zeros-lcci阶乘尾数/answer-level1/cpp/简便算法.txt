### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        while(n!=0){
            count+=n/5;
            n/=5;
        }
        return count;
    }
};
```