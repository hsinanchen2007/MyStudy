### 解题思路
我是一位新手, 各位大佬跳过就好
我是先把两个字符串倒序 
例如 : 1010 -> 0101; 11001 -> 10011
然后就大概是这个样子, 一个从左开始算的二进制加法(①表示进位)
![ee2825e2ece6f7e49fa02b54beb5974.png](https://pic.leetcode-cn.com/ffee3b53787e5e2074d6b1c61ae92f3beed9aa3b625be90697ac77b402399f21-ee2825e2ece6f7e49fa02b54beb5974.png)

然后再将这个110001字符串倒序成 100011 就成了
### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
        // 返回结果
        StringBuilder result = new StringBuilder();
        // 先将两个字符串倒序
        String str1 = new StringBuilder(a).reverse().toString();
        String str2 = new StringBuilder(b).reverse().toString();
        // 转成数组
        char[] arr1 = str1.toCharArray();
        char[] arr2 = str2.toCharArray();
        // 取最大的长度
        int length = Math.max(arr1.length, arr2.length);
        // 进位
        int carry = 0;
        for (int i = 0;i < length;i++){
            int num1 = 0;
            int num2 = 0;
            int answer = 0;
            if (i < arr1.length){
                num1 = arr1[i] - 48;
            }
            if (i < arr2.length){
                num2 = arr2[i] - 48;
            }
            answer = num1 + num2 + carry;
            if (answer >= 2){
                carry = 1;
                answer = answer - 2;
            } else {
                carry = 0;
            }
            result.append(answer);
        }
        if (!result.equals("0") && carry > 0){
            result.append(carry);
        }
        return result.reverse().toString();
    }
}
```