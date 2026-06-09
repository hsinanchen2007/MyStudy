只是O(n^2),算是给个参考吧
```
class Solution {
    public int cou***angeSum(int[] nums, int lower, int upper) {
        if(nums == null || nums.length == 0){
            return 0;
        }
        int count = 0;
        long[] res = new long[nums.length];
        long sum = 0;
        for(int i = 0; i < nums.length; i++){
            if(lower<= nums[i] && nums[i]<=upper){//单个数值在所给区间范围
                count++;
            }
            sum += nums[i];
            res[i] = sum;
        }
        for(int i = 1; i < nums.length; i++){
            if(lower<= res[i] && res[i]<=upper){//从第0个到第i个元素之和在所给区间范围
                count++;
            }
            for(int j = 0; j < i-1; j++){
                long z = res[i] - res[j];
                if(lower<= z && z<=upper){ //从第i(i>0)个到第j个元素之和在所给区间范围
                    count++;
                }
            }
        }
        return count;
    }
}
```
