做的时候其实其实可以考虑成任何进制来做，不易受干扰。
思路就是不断比较值来做。和取出任何正整数的各个位上的数求法一样

```java
class Solution {
    public boolean hasAlternatingBits(int n) {
        int n1;
        while(n>0){
            n1 = n %2;
            n = n/2;
            if(n1 == n%2)
                return false;
        }
        return true;
    }
}
```