### 解题思路
可以理解为26进制的数转10进制的数

### 代码

```java
class Solution {
    public int titleToNumber(String s) {
        String reverse_s = new StringBuffer(s).reverse().toString();
        int sum = 0;
        int mul = 1;
        for(int i=0;i<reverse_s.length();i++){
            int add = (int)(reverse_s.charAt(i)-'A'+1);
            add=add*mul;
            sum=sum+add;
            mul=mul*26;
        }

        return sum;
    }
}
```