### 解题思路
数字的逆序：
while(t){
            y=y*10+t%10;
            t/=10;
        }原来的个位，放到新数的十位

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long y=0;
        int t=x;//注意要和原来的比较，所以拷贝一下
        while(t){
            y=y*10+t%10;
            t/=10;
        }
        return y==x;
    }
};
```