```
class Solution {
    public int[] plusOne(int[] digits) {
        //int[] res = new int [digits.length];
        boolean carryIn = false;
        // If we dont need to worry about the carry in
        if(digits[digits.length-1] < 9){
            digits[digits.length-1]++;
            return digits;
        }
        // last digit is 9
        for(int i = digits.length - 1; i >= 0; i--){
            if(digits[i] == 9 && carryIn == false){
                digits[i] = 0;
                carryIn = true;
            } else if(digits[i] == 9 && carryIn == true){
                digits[i] = 0;
                carryIn = true;
            } else if(digits[i] < 9 && carryIn == true){
                digits[i]++;
                carryIn = false;
                break;
            } else {
                digits[i]++;
                carryIn = false;
                break;
            }
        }
        if(carryIn){
                int[] newRes = new int[digits.length + 1];
                for(int i = 1; i <= digits.length; i++){
                    newRes[i] = digits[i-1];
                }
                newRes[0] = 1;
                return newRes;
            } else {
                return digits;
            }
    }
}
```
哈哈显然不是最好的答案啦，但是我选择发一个po纪念我以为学了毫无用处的x86 assembly language。。。感觉就是在玩弄register，当时32位的数字相加也差不多是这种感觉。果然学校安排的课还是要好好学的hhh。。。。