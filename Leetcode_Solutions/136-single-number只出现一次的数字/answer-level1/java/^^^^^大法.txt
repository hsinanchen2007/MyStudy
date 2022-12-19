class Solution {
    public int singleNumber(int[] nums) {
        
        int skr =0;
        for(int skrskr:nums){
         skr =skr^skrskr;      
        }
        return skr;
    }
}
// 上面定义了变量skr下面运用skr不能加int skr。因为一个 变量只能有一次赋值，但是可以改变值