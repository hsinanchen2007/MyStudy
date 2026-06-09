### 解题思路
此处撰写解题思路
如果整数为负数，则不是回文数
否则，就计算整数反转后的数 是否与原整数值相等
相等即为回文数

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        int res=0;
        int temp=x;
        if(x<0) return false;
        while (x!=0){
            res=res*10+x%10;
            x=x/10;

        }
        //System.out.println(res==temp);
        if (res==temp) return true;
        else return false;
    }
}
```