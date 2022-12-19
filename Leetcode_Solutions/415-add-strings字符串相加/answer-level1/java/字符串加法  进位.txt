### 解题思路
从尾部相加，记录进位

![image.png](https://pic.leetcode-cn.com/78066555369e5bda443ec7885c10c45b61395ebb0ec2faa9e568f78946d45325-image.png)


### 代码

```java
class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder sb = new StringBuilder();
        char[] arr1 = num1.toCharArray();
        char[] arr2 = num2.toCharArray();
        int length1 = arr1.length;
        int length2 = arr2.length;
        int i = length1 - 1;
        int j = length2 - 1;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int a = 0, b = 0;
            if (i >= 0) {
                a = arr1[i] - '0';
            }
            if (j >= 0) {
                b = arr2[j] - '0';
            }
            int sum = a + b + carry;
            carry = sum / 10;
            sb.append(sum % 10);
            i--;
            j--;
        }
        if (carry != 0) {
            sb.append(carry);
        }
        return sb.reverse().toString();
    }
}
```