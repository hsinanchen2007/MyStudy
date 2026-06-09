就是个数学题- -
计算1 - n中间包含多少个5。。。



class Solution {
    public int trailingZeroes(int n) {
        
        int num = 0;
        while(n > 0){
            num = num + n / 5;
            n = n/5;
        }
        
        
        return num;
    }
}