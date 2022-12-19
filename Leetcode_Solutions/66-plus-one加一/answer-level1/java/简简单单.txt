```
class Solution {
   public int[] plusOne(int[] digits) {
        return helper(digits,digits.length-1);
    }

    private int[] helper(int[] digits, int i) {
        if (i==0){
           if (digits[0]==9){
               digits = new int[digits.length + 1];
               digits[0]=1;
                return digits;
           }else {
               digits[0]=digits[0]+1;
               return digits;
           }
        }else{
            int num=digits[i];
            if (num==9){
                digits[i]=0;
                return helper(digits,i-1);
            }else{
                digits[i]=digits[i]+1;
                return digits;
            }
        }
    }
}
```
