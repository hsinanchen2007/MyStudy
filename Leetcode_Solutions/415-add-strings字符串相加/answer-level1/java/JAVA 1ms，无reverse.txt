![image.png](https://pic.leetcode-cn.com/aafbbbfedaf978e1dc4875f4fc77af88cc03d556fe4285767cf3960f94ccd695-image.png)

### 解题思路
常规的思路模拟加法。
1. 参考了最佳写法，采用char数组的方式，避免了字符串的reverse
2. 空间换时间，转成array来提高charAt的速度。
3. 做了一次数组的交换，减少了分支和重复代码。
4. 把a和b的定义放到了循环外层，可以提高效率。

### 代码

```java
class Solution {
    public String addStrings(String num1, String num2) {
        char[] chArr1 = num1.toCharArray();
        char[] chArr2 = num2.toCharArray();

        if (num1.length() < num2.length()) {
            // 确保chArr1的长度大于等于chArr2
            char[] temp = chArr2;
            chArr2 = chArr1;
            chArr1 = temp;
        }

        int carry = 0;
        int a;
        int b;  
        
        for (int i = chArr1.length - 1, j = chArr2.length - 1; i >= 0; i--, j--) {
            a = chArr1[i] - '0';
            b = (j >= 0) ? chArr2[j] - '0' : 0;

            int tempResult = a + b + carry;
            chArr1[i] = (char)(tempResult % 10 + '0');
            carry = tempResult / 10;
        }

        if (carry != 1) {
            return String.valueOf(chArr1);
        }

        return "1" + String.valueOf(chArr1);
    }
}
```