### 解题思路
此处撰写解题思路
计算二进制中1的个数
### 代码

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count=0;
        while(n!=0){
            if(n%2==1){
                count++;
            }
            n /= 2;
        }
        return count==1;
    }
};
```