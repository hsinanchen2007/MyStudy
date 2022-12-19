class Solution {
    public int[] plusOne(int[] digits) {
        int i = digits.length-1;
        int j = (digits[i]+1)/10;
        while(j==1&&i>0) {                  //进位
            digits[i] = 0;                  //进位后当前位为0
            j = (digits[i-1]+1)/10;         //判断更高一位是否为9
            i--;
        }
        if(j == 1){                         //如果是因为i=0跳出循环，且j=1则说明最高位是9
            int [] res = new int[digits.length+1];      //生成一个比输入数组多一位的数组返回结果
            res[0] = 1;
            return res;
        }
        else{                               //否则当前位加1即为结果
            digits[i] += 1;
            return digits;
        }
    }
}