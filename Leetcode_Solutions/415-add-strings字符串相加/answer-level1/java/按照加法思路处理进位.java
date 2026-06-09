```
class Solution {
    public String addStrings(String num1, String num2) {
        String num1R = new StringBuilder(num1).reverse().toString();
        String num2R = new StringBuilder(num2).reverse().toString();
        StringBuilder sb = new StringBuilder();
        int carry = 0;
        for (int i = 0; i < num1R.length(); i++){
            if(i < num2R.length()){
                int sum = (num1R.charAt(i)-'0') + (num2R.charAt(i) - '0')+ carry;
                if (sum >= 10){
                    carry = 1;
                    sb.append(sum%10);
                }else{
                    sb.append(sum);
                    carry = 0;
                }
            }else{
                int sum = (num1R.charAt(i) - '0') + carry;
                if (sum >= 10){
                    carry = 1;
                    sb.append(sum%10);
                }else{
                    sb.append(sum);
                    carry = 0;
                }
            }
        }
        if(num2R.length() > num1R.length()){
            for(int i = num1R.length(); i < num2R.length(); i++){
                int sum = (num2R.charAt(i) - '0') + carry;
                if (sum >= 10){
                    carry = 1;
                    sb.append(sum%10);
                }else{
                    sb.append(sum);
                    carry = 0;
                }
            }
        }
        if (carry == 1){
            sb.append("1");
        }
        return new StringBuilder(sb).reverse().toString();
    }
}
```
