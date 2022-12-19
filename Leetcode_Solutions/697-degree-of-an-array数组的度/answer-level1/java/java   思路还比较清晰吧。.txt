先算出原数组的度，然后知道这个数字之后算出第一次出现和最后一次出现之间的长度，因为数字不唯一所以得比较得出最小的。






class Solution {
    public int findShortestSubArray(int[] nums) {
        int[] b = new int[50000];
        for(int i :nums)
            b[i]++;
        int max = 0;
        int sum = 0;
        int c = 50000;
        int flag = 0;
        for(int i = 0;i<50000;i++){
            max = Math.max(max,b[i]);
            
        }
        for(int i = 0;i<50000;i++){
            if(b[i] == max){
                int n = 0;
                int m = nums.length-1;
                while(n<nums.length){
                    if(nums[n] == i){
                        sum -= n;
                        break;
                    }
                    else
                        n++;
                }
                while(m>=0){
                    if(nums[m] == i){
                        sum+=m;
                        break;
                    }
                    else
                        m--;
                }
                c = Math.min(c,sum+1);
                sum = 0;
            }
        }
        return c;
    }
}
