```
class Solution {
    public String addStrings(String num1, String num2) {
        int carry = 0;
        StringBuilder sb = new StringBuilder("");
        for(int i = num1.length() - 1, j = num2.length() - 1; i >= 0 || j >= 0; i--,j--){
            int num1c = 0;
            if(i >= 0){
               num1c = num1.charAt(i) - '0';
            }
            int num2c = 0; 
            if(j >= 0){
               num2c = num2.charAt(j) - '0';
            }
            int sum = num1c + num2c + carry;
            carry = sum / 10;
            sb.append(sum % 10);
        }
        if(carry > 0){
            sb.append(carry);
        }
        return sb.reverse().toString();
    }
}
```