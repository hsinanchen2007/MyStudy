### 解题思路
本题最开始独自构思的时候，想过将较短的二进制字符串补0，达到等长，从而方便计算，但一直不知道该怎么实现比较好，一直往先“修改字符串”的方向想。
1. 后来看了题解后发现其实这是可以动态“补0”则通过下标判断，若越界则当作0即可，我觉得这个动态的思路应该比较有用。
2. 然后还有StringBuilder的运用（初学Java，会的不多），和利用ASCII码中'1' 和 '0'相差1，从而先化为int数，这个思想应该也比较有用，例如出个十六进制求和？字母求和什么的？
3. 还有除法和取余运算的应用，用于数字类题目十分有用。可以将除法看成除去低位数，将取余看成取余下低位数。再进一步，如果是十六进制，八进制，则除以对应基数（底数）；在《深入理解计算机系统》第二章中也有类似知识点，二进制的截断！！一个w>3位的数，想要保留最后3位，只需要进行取余运算 %2^3即可，想除去最后3位则可以除法运算 /2^3即可。同理可进一步推广。
### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
        int carry = 0;
        StringBuilder ans = new StringBuilder();
        for(int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; i--, j--) {
            int sum = carry;
            sum += i >= 0 ? a.charAt(i) - '0' : 0;//判断是否超出二进制数长度，没超出则加上，超出则加上0
            sum += j >= 0 ? b.charAt(j) - '0' : 0;
            carry = sum / 2;//取进位
            ans.append(sum % 2);
        }
        ans.append(carry == 1?carry:"");
        return ans.reverse().toString(); 
    }
}
```