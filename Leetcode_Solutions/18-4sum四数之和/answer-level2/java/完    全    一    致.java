此解法与三数之和解法几乎完全一致，由于问题为四数之和，故新加入一个指针l
l指针为末指针，用法与k指针相似
对k和l的遍历次数做了限制略微提高性能

```
public static List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        for(int k = 0;k < nums.length - 3;k++){
            if(k>0 && nums[k] == nums[k-1]) continue;
            for(int l = nums.length - 1; l > 2;l--){
                if(l<nums.length-1 && nums[l] == nums[l+1]) continue;
                int i = k + 1;
                int j = l - 1;
                while(i < j){
                    int sum = nums[k] + nums[i] + nums[j] + nums[l];
                    if(sum > target){
                        while(i < j && nums[j] == nums[--j]);
                    }else if(sum < target){
                        while(i < j && nums[i] == nums[++i]);
                    }else{
                        ans.add(new ArrayList<>(Arrays.asList(nums[k],nums[i],nums[j],nums[l])));
                        while(i < j && nums[i] == nums[++i]);
                        while(i < j && nums[j] == nums[--j]);
                    }
                }
            }
        }
        return ans;
    }
```
