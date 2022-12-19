执行用时 :38 ms, 中击败了37.22%的用户。
内存消耗 :35.2 MB, 击败了89.04%的用户。
```
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = 0;
        int max = 0;
        for(int j : nums){
            sum+=j;
            if(max < j){
                max = j;
            }
        }
        //总和不能被子集数整除，肯定不存在
        if(sum%k!=0){
            return false;
        }
        int z = sum/k;
        //子集平均和小于最大值，肯定不存在
        if(z < max){
            return false;
        }
        Arrays.sort(nums);
        List<Integer> list = new ArrayList();
        for(int i = nums.length-1; i>=0; i--){
            list.add(nums[i]);
        }
        return check(list,0,k,z);
    }
    
    private boolean check(List<Integer> list,int sum, int count, int target){
        if(count == 0){
            return true;
        }
        for(int i = 0; i < list.size();i++){
            if(sum+list.get(i) == target){
                int temp = list.remove(i);
                if(check(list,0,count-1,target)){
                    return true;
                }else{
                    list.add(i, temp);
                }
            }else if(sum+list.get(i) < target){
                int temp =  list.remove(i);
                if(check(list,sum+temp,count,target)){
                    return true;
                }else{
                    list.add(i, temp);
                }
            }
        }
        return false;
    }
}
```