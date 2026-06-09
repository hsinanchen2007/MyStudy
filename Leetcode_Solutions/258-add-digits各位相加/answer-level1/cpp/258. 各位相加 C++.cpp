### 解题思路
1.递归调用，若还不是个位数就继续调用。

### 代码

```cpp
class Solution {
public:
    int addDigits(int num) {
        if(num == 0){
            return 0;
        }
        
        int ans = 0;
        while(num != 0){
            ans += num % 10;
            num /= 10;
        }
        
        return ans < 10 ? ans : addDigits(ans);
    }
};
```