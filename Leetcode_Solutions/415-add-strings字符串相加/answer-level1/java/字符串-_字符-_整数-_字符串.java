![image.png](https://pic.leetcode-cn.com/c6634015a6e6b2249d8ab4a73f11cb8129fd19d696cb723f398908eaecc15b9d-image.png)

```
    public String addStrings(String num1, String num2) {    
        int carry = 0;
        StringBuilder sb = new StringBuilder();
        for(int i = num1.length() - 1, j = num2.length() - 1; i >= 0 || j >= 0; i--, j--) {
            int a = (i >= 0) ? num1.charAt(i) - '0' : 0;
            int b = (j >= 0) ? num2.charAt(j) - '0' : 0;
            int sum = a + b + carry;
            sb.append(sum % 10);
            carry = sum / 10;
        }
        if(carry > 0) {
            sb.append(1);
        }
        return sb.reverse().toString();
    }
```
