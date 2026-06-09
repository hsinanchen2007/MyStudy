从数组最后一位 做一个循环判断是否一直为9（形如3999和9999这种形式），如果一直为9，则将其直接设置为0.


区分3999和9999这两种，就是考虑数组下标是否为-1，-1的说明，数组所有的值都变为了0，需要进位。此时定义一个新的数组，长度加1。
下标不为-1的话，直接当前位加1.（456这种直接加1的也适合，因为while循环根本就不会进去）

代码如下：
```
class Solution {
    public int[] plusOne(int[] digits) {
        int i = digits.length -1;
        
        while(i>=0 && digits[i]==9){
            digits[i--] = 0;
        }
        if( i == -1){
            int[] new_digits = new int[digits.length + 1];
            new_digits[0] = 1;
            return new_digits;
        }else{
            digits[i] += 1;
            return digits;
        }
    }
}
```
