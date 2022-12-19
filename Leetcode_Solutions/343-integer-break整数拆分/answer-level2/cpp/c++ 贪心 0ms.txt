### 解题思路
贪心算法

### 代码

```cpp
class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3) return n - 1;  //必须切一刀
        //n >= 5 2*(n-2) > n   3*(n-3) > n  且3*(n-3) >= 2*(n-2)
        //n = 4 2 * 2 > 1 * 3
        //2和3不能再分了  分了就变小了 且3优于2
        int a = n / 3;
        int b = n % 3;
        if(b == 0){
            //全部分成3
            return pow(3, a);
        }
        if(b == 1){
            //n = 10 3 * 3 * 3 * 1 ==> 3 * 3 * 2 * 2
            //4   1 和 3 要变成2 * 2
            return pow(3, a-1) * 4;
        }
        //b == 2  2不能再分了
        return pow(3, a) * 2;
    }
};
```