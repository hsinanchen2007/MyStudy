看注释:)
```
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int onenum = 0;//记录出现过的最大连续1数
        int tempnum = 0;//记录每一个新开始的连续1数
        for(int num:nums){
            if(num==1){//如果遍历到1就自动加一
                tempnum++;
                if(tempnum>onenum){//每次都比较临时计数器与最大计数器的值
                    onenum=tempnum;
                }
            }else{//遍历到0则把临时计数器置0
                tempnum = 0;
            }
        }
        return onenum;
    }
}
```
