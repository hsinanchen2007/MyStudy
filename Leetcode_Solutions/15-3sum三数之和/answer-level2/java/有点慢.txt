### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        Set<List<Integer>>list=new HashSet<>();
        for(int i=0;i<nums.length;i++){
            if(nums[i]>0){
                break;
            }
            int l=i+1;
            int r=nums.length-1;
            while (l<r){
                int res=nums[i]+nums[l]+nums[r];
                if(res<0){
                    l++;
                }else if(res>0){
                    r--;
                }else{
                    list.add(Arrays.asList(new Integer[]{nums[i],nums[l],nums[r]}));
                    l++;
                    r--;
                }
            }
        }
        return new ArrayList<>(list);
    }
}
```