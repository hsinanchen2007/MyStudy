### 解题思路
注意的点：
1.x可正可负，循环终止条件为x==0；
2.不要忘了ans每次乘10；
3.用INT_MAX 和 INT_MIN 代表最大，最小INT数，调了我好久。。。
### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        long ans=0;
        while(x!=0)
        {
            ans*=10;
            ans+=x%10;
            x/=10;
        }
        if(ans>INT_MAX || ans<INT_MIN) return 0;
        return ans;
    }
};
```