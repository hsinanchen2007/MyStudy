### 解题思路
仿照三数之和的思路，并剪枝

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        int len = nums.length;
        Arrays.sort(nums);
        for(int i =0;i<len-3;++i){
            if(i>0&&nums[i]==nums[i-1])
                continue;
            if((nums[i]+nums[i+1]+nums[i+2]+nums[i+3])>target)
                break;//剪大枝，如果当前最小值都比target大，则没有等于target的结果了
            if((nums[i]+nums[len-1]+nums[len-2]+nums[len-3])<target)
                continue;//剪小枝，如果当前值的最大和都比target小，则此值所有结果都比target小，遍历下一个
            for(int j =i+1;j<len-2;++j){
                int cur = nums[i]+nums[j];
                if(j>i+1&&(nums[j-1]==nums[j]))
                    continue;
                int L = j+1;
                int R = len-1;
                while(L<R){
                    int sum = cur+nums[L]+nums[R];
                    if(sum==target){
                        res.add(Arrays.asList(nums[i],nums[j],nums[L],nums[R]));
                        while(L<R&&nums[L]==nums[L+1])L++;
                        while(L<R&&nums[R]==nums[R-1])R--;
                        ++L;
                        --R;
                    }
                    else if(sum<target)
                        ++L;
                    else
                        --R;
                }
            }
        }
        return res;
    }
}
```