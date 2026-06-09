### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        Set<List<Integer>>list=new HashSet<>();
        for(int i=0;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++){
                int l=j+1;
                int r=nums.length-1;
                while (l<r){
                    int temp=nums[i]+nums[j]+nums[l]+nums[r];
                    if(temp<target){
                        l++;
                    }else if(temp>target){
                        r--;
                    }else{
                        list.add(Arrays.asList(new Integer[]{nums[i],nums[j],nums[l],nums[r]}));
                        l++;
                        r--;
                    }
                }
            }

        }
        return new ArrayList<>(list);
    }
}
```