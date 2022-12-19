### 解题思路
隐藏的大数问题， int反转后很有可能就溢出了，所以要加判断。

### 代码

```cpp
class Solution {
public:
    // 执行用时 :4 ms, 在所有 C++ 提交中击败了72.19% 的用户
    // 内存消耗 :6 MB, 在所有 C++ 提交中击败了100.00%的用户
    int reverse(int x) {
        int res = 0;
        while(x!=0){
            if(res>INT_MAX/10||(res==INT_MAX/10&&x>INT_MAX%10)) return 0;//隐藏的大数问题。
            if(res<INT_MIN/10||(res==INT_MIN/10&&x<INT_MIN%10)) return 0;
            res = res*10+x%10;
            x/=10;
        }
        return res;
    }
};
```