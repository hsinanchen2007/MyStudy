### 解题思路
本题使用**数学思维**判断，为了有效防止溢出问题

定义pop为每次取出的个位数，在判断溢出问题的时候可以作为最大值和最小值的临界数

通过每次取个位数，然后*10当作反转数字的高位，而原来的高位则被作为最后的pop数加到新的数的末尾即可。

### 代码

```java
class Solution {
    public int reverse(int x) {
        int ans = 0;//定义反转后的数
        while(x != 0){
            int pop = x % 10;//每次取个位数
            //判断溢出 ，既不能超最大值，也不能小于最小值
            if(ans > Integer.MAX_VALUE / 10 || (ans == Integer.MAX_VALUE / 10 && pop > 7)){
                return 0;
            }
            if(ans < Integer.MIN_VALUE / 10 || (ans == Integer.MIN_VALUE / 10 && pop < -8)){
                return 0;
            }
            ans = ans * 10 + pop;
            x /= 10;
        }
        return ans;
    }
}
```