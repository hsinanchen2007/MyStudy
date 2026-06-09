**双指针问题，多出一个C位，让双指针指向的数据和C为的数据相加**
```
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> lists = new ArrayList<>();
        int len = nums.length;
        if(len < 3 || nums == null) return lists;
        //先对数组进行排序
        Arrays.sort(nums);
        for(int i = 0;i<nums.length;i++){
            //如果当前数字大于0，则不可能存在等于0的情况了
            if( nums[i] > 0) break;
            //去除重复  注：：可借鉴这个写法
            if(i>0 && nums[i] == nums[i-1]) continue;
            //左指针
            int l = i+1;
            //右指针
            int r = len - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    lists.add(Arrays.asList(nums[i],nums[l],nums[r]));
                    //前后去重
                    while(l<r && nums[l] == nums[l+1]) l++;
                    while(l<r && nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
                }
                //如果数小于0 ，证明前面的数太小
                else if(sum < 0) l++;
                //如果数大于1，证明后面的数太大
                else if(sum > 0) r--;
            }
        }
        return lists;
    }
}
```
