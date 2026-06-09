### 解题思路
此处撰写解题思路
因为负数肯定不是回文数.所以有了 if (x<0) return false;
定义一个变量(transfer)用来下面的while计算回文数
定义一个变量(xTransfer)用来保存x的值以作最后的比较
while循环的x!=0条件是因为 下面一段代码x/=10; 
举例121,(1=0*10+121%10),x/10变成了12(int类型不保存小数)
循环n次直到x被除尽,结束循环得出将x逆序计算后的transfer结果 与xTransfer进行判断是否相同true/false

小白一个,勿喷
### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if (x<0) return false;
        int transfer = 0;
        int xTransfer = x;
        while (x!=0){
            transfer = transfer*10+x%10;
            x/=10;
        }
        return transfer == xTransfer ? true :false;
    }
}
```