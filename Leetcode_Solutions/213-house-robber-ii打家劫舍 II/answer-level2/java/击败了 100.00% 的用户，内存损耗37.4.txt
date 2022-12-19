参考打家劫舍 III，每个房间都只能有两种情况，被偷和没被偷。记录两种情况的结果即可。内存损耗37.4。
```
class Solution {
    public int rob(int[] nums) {
        int[] res = solution(0,nums.length-1,nums);
        return Math.max(res[0],res[1]);
    }

    public int[] solution(int left,int right,int[] nums){
        int[] res = new int[2];
        if(left>right){
            return res;
        }
        int[] tmp;
        if(left!=right&&left==0&&right==nums.length-1){
            tmp = solution(left+1,right-1,nums);
            res[0] = nums[left] + tmp[1];
            tmp = solution(left+1,right,nums);
            res[1] = Math.max(tmp[0],tmp[1]);
        }else{
            tmp = solution(left+1,right,nums);
            res[0] = nums[left] + tmp[1];
            res[1] = Math.max(tmp[0],tmp[1]);
        }
        return res;
    }
}
```
