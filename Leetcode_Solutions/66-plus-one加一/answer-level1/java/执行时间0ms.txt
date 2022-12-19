思路

这道题只有两种情况 
1.所有数都是9,此情况必须新建一个大于当前数组一位的新数组,来处理溢出.例如[9,9]  [9]  [9,9,9,9,]这样的
2.除了第一种情况以外都不需要新建数组.对于这种情况只需要找数组中第一个不为9的数,找到后把这个数加一.在找的过程中只要它是9就置为0.例如[1,3,9,9,1,0]
如果上述两种情况都不是,说明一个9都没有,那么末尾那个数加一即可.

方法是我自己推敲出来的.重点就是找9.建议大家每个题都自己想,哪怕暂时想不出来先放一放接着想.我都是这么做题的.我感觉收获很大,目前提交的题都是自己独立思考出来的.

class Solution {
    public int[] plusOne(int[] digits) {
        
        int count = 0;
        for(int i = 0; i < digits.length; i++){
            if(digits[i] == 9){
                count++;
            }
        }
        if(count == digits.length){
            int[] newArray = new int[digits.length+1];
            for(int i = 1; i < newArray.length; i++){
               newArray[i]=0;
            }
            newArray[0] = 1;
            return newArray;
        }
        
       int index = digits.length-1;

        
        while (digits[index] == 9 && index > 0){
            digits[index] = 0;
            index--;
        }

        digits[index] += 1;
        
        return digits;
    }
}