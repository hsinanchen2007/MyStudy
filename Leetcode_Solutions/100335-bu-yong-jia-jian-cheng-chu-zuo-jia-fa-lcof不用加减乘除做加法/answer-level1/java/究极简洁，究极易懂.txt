因
a^b：表示a+b忽略进位后的结果;
(a&b)<<1：表示a+b的进位;
所以
a+b <==> (a^b)+((a&b)<<1);
可采用递归，且应当在进位为0时返回另一个参数;
```
class Solution {
    public int add(int a, int b) {
        if(b==0) return a;
        return add(a^b,(a&b)<<1);
    }
}
```