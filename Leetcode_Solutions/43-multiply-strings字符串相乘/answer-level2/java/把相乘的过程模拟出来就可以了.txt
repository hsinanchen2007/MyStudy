### 解题思路
1. 首先写出两个字符串相加的方法，要注意最高位可能有进位。
2. 接着写出一个字符和字符串相乘的方法，同样也要注意最高位可能有进位。
3. 将上述方法合理运用就可以了。
。
### 代码

```java
class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0"))
            return "0";
        String ans = "";
        int i = num1.length() - 1;
        int k = 0;
        while (i >=  0) {
            char c = num1.charAt(i);
            String multiply = multiply(c, num2, k);
            ans = add(ans, multiply);
            k++;
            i--;
        }
        return ans;
    }

    public String add(String num1,String num2){
        StringBuilder ans = new StringBuilder();
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0){
            int left = 0;
            int right = 0;
            if (i >= 0)
                left = num1.charAt(i) - '0';
            if (j >= 0)
                right = num2.charAt(j) - '0';
            int all = left + right + carry;
            carry = all / 10;
            int real = all % 10;
            ans.insert(0, real + "");
            i--;
            j--;
        }
        if (carry == 1)
            ans.insert(0,"1");
        return ans.toString();
    }

    public String multiply(char c,String nums,int times){
        int left = c - '0';
        StringBuilder ans = new StringBuilder();
        int i = nums.length() - 1;
        int carry = 0;
        while (i >= 0){
            int right = nums.charAt(i) - '0';
            int all = left * right + carry;
            carry = all / 10;
            int real = all % 10;
            ans.insert(0,real + "");
            i--;
        }
        if (carry != 0)
            ans.insert(0,carry + "");
        StringBuilder tail = new StringBuilder();
        while (times-- != 0)
            tail.append("0");
        return ans.toString() + tail.toString();
    }
}
```