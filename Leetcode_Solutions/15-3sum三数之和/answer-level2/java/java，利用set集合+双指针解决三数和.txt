### 解题思路
**如何解决重复？**  
利用了排序和set集合来解决重复问题。  


### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        if (nums.length<3 || nums==null){
            return Collections.emptyList();
        }
        Set<List<Integer>> lists = new LinkedHashSet<>();
        Arrays.sort(nums);
        for (int i=0;i<nums.length-2;i++){
            int l=i+1;
            int r=nums.length-1;
            if (i>0&&nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]>0){
                return new ArrayList<>(lists) ;
            }
            while(l<r){
                if (nums[i]+nums[l]+nums[r]==0){
                    List<Integer> list= Arrays.asList(nums[i],nums[l],nums[r]);//list是有序的
                    lists.add(list);
                    l++;
                    r--;
                    while(l<r&&nums[l]==nums[l-1]){
                            l++;
                    }
                    while(l<r&&nums[r]==nums[r+1]){
                            r--;
                    }
                }else if (nums[i]+nums[l]+nums[r]>0){
                    r--;
                }else if (nums[i]+nums[l]+nums[r]<0){
                    l++;
                }
            }
        }
        return  new ArrayList<>(lists) ;
    }
}
```