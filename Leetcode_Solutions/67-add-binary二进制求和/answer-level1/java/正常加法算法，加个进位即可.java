### 解题思路


### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
        if(a == null)
            return b;
        if(b == null)
            return a;
        StringBuilder sb = new StringBuilder();
        int carry = 0;
        int i = a.length() - 1, j = b.length() - 1; //100
        for(; i >= 0 || j>= 0; i--,j--){
            int x = 0;
            int y = 0;
            if(i >= 0){
                x = a.charAt(i) - '0';
            }
            if(j >= 0){
                y = b.charAt(j) - '0';
            }
            int sum = x + y + carry;
            if(sum >= 2){
                sum %= 2;
                carry = 1;
            } else
                carry = 0;
            sb.append(sum);
        }
        if(carry > 0)
            sb.append(carry);
        return sb.reverse().toString();
    }
}
```