### 解题思路
思路：利用%2判断是1还是0，/2判断前一位数
### 代码

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n>0){
            if(n%2!=(n/2)%2)
                n=n/2;
            else
                return false;
        }
        return true;
    }
};
```