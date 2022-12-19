### 解题思路
0的产生是因为2和5相乘，2的个数肯定比5多，所以找5的个数

### 代码

```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        while(n>=5){
            count+=n/5;
            n/=5;
        }
        return count;
    }
};
```