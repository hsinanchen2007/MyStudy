```
class Solution {
    public int[] plusOne(int[] digits) {
        //不需要进位的时候
        if(digits[digits.length - 1] != 9){
            digits[digits.length - 1] += 1;
            return digits;
        }
        //从后向前找到第一个不是9的位置
        int i = digits.length - 1;
        while(i >= 0 && digits[i] == 9){
            i--;
            }
        //数组全为9，数组长度需要发生变化
        if(i == -1){
            //建立新的数组，最高为置1，即为结果
            int[] res = new int[digits.length + 1];
            res[0] = 1;
            return res;
        }
        //需要进位但是数组长度不会增加
        digits[i]++;//进位
        for(int j = i+1; j < digits.length; j++){
            digits[j] = 0; //将进位的位置之后位置上的9置零
        }
        return digits;
        }
    }

```
