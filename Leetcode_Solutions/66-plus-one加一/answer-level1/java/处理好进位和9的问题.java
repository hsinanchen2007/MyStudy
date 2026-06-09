//直接给最后一位数+1

//处理两个问题，第一是进位的情况，第二是9，99这种需要再添加一位数的情况
```
class Solution {
    public int[] plusOne(int[] digits) {
        int i = digits.length - 1;
        while(++digits[i] == 10){
            digits[i] = 0;
            i--;
            if(i < 0){
                break;
            }
        }
        if(digits[0] == 0){
            int[] result = new int[digits.length+1];
            result[0] = 1;
            return result;
        }else{
            return digits;
        }
    }
}
```
