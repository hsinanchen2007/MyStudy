### 解题思路
首先，x<0时直接返回假。
如果x>=0，则将该数从低位开始分解，并将分解出来的数作为高位存于另一个数中，以此来达到将该数反转的目的，最后，只需判断反转后的数与原数是否相同即可。


### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if(x<0)return false;
        int n=x,sum=0;
        while(n!=0){
            sum=sum*10+n%10;
            n/=10;
        }
        return x==sum;
    }
}
```