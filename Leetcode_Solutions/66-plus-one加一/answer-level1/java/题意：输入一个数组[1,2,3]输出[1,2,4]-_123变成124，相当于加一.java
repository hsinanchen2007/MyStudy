### 解题思路
数组从后向前判断，如果是9，则该位 **置0**，否则加一返回digits(说明已经不需要再进位了) 例如129->130

当全部判断完还没返回，则遇到99或999..这样的情况，此时digits内已全为0；则需要建一个大小为digits.length+1的数组，存放结果100或1000...

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length; 
        for(int i = n -1;i>=0;i--){
           if(digits[i] == 9){
               digits[i] = 0;
           }else{
               digits[i]++;
               return digits;
           }
       }
        int[] a = new int [n+1];
        a[0]=1;
        return a;
    } 
}
```