### 解题思路
此处撰写解题思路
先分析题目中所给例子，3，5，4；为了得到4，可以先把3加到5，5剩下2，再把三加到2，5满，3剩1，把5清空，1加到5，5剩4，再加入3，5剩1，于是此时的就是4；这个过程实际上类似于辗转相除求最大公因子的过程，而1就是和5的最大公因子，当z不大于8的时候都能通过操作得到z。
### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(z == 0)
            return true;
        if(x+y < z)
            return false;
        if(x > y){
            int temp = x;
            x = y;
            y = temp;
        }
        if(x == 0)
            return y == z;
        while(y % x != 0){
            y = y % x;
            int temp = y;
            y = x;
            x = temp;
        }
        return z%x==0;
    }
}
```