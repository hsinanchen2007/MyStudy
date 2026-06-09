### 解题思路
重点在于溢出判断；
1.溢出后的结果是变成另一个32位内的数字
2.官方解法是在溢出发生之前判断/10跟Integer.MAXVALUE的大小
3.本代码用的是判断反转后再反转回来的数与原值是否相等

### 代码

```java
class Solution {
    public int reverse(int x) {
        int res = 0;
        while(x != 0){
            //逐位累加
            int temp = x % 10 + res * 10;
            if(res != (temp - x % 10)/10)
                return 0;
            res = temp;
            x /= 10;
        }
        return res;
    }
}
```