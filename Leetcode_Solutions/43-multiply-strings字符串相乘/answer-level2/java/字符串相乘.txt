![image.png](https://pic.leetcode-cn.com/54ee3b547fe53c9f2e2e3eeea889cec8049c9d38e5a7a2a8759ad33990b29e21-image.png)

```
class Solution {
    public String multiply(String num1, String num2) {
        String[] products;
        String answer;
        int i, length;

        if(num1.length() == 0 || num2.length() == 0 || num1.equals("0") || num2.equals("0"))
            return "0";
        length = num2.length();
        products = new String[length];
        for(i = 0; i < length; i++){
            products[i] = multiplyHelper(num1, num2.charAt(length - 1 - i) - '0', i);
        }
        answer = "0";
        for(i = 0; i < length; i++){
            answer = add(products[i], answer);
        }
        return answer;
    }

    private String add(String num1, String num2){
        String answer;
        int i, carry, l1, l2, l, s;
        int[] n1, n2, sum;

        l1 = num1.length();
        l2 = num2.length();
        l = Math.max(l1, l2);
        n1 = new int[l];
        n2 = new int[l];
        sum = new int[l];
        for(i = 0; i < l1; i++)
            n1[i] = num1.charAt(l1 - 1- i) - '0';
        for(i = 0; i < l2; i++)
            n2[i] = num2.charAt(l2 - 1- i) - '0';
        carry = 0;
        for(i = 0; i < l; i++){
            s = n1[i] + n2[i] + carry;
            sum[i] = s % 10;
            carry = s / 10;
        }
        answer = "";
        if(carry == 1)
            answer += 1;
        for(i = l; i > 0; i--)
            answer += sum[i-1];
        return answer;
    }

    private String multiplyHelper(String num1, int num2, int k){
        String answer;
        int[] nums;
        int i, length, carry, product;

        if(num2 == 0)
            return "0";
        answer = "";
        length = num1.length();
        nums = new int[length];
        carry = 0;
        for(i = length; i > 0; i--){
            product = (num1.charAt(i - 1) - '0') * num2 + carry;
            nums[i-1] = product % 10;
            carry = product / 10;
        }
        if(carry != 0)
            answer += carry;
        for(i = 0; i < length; i++)
            answer += nums[i];
        for(i = 0; i < k; i++)
            answer += 0;
        return answer;
    }
}
```
