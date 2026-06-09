### 解题思路
跟三数和差不多，有待改正。

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {

 if (nums.length<4 || nums==null){
            return Collections.emptyList();
        }
        Set<List<Integer>> lists = new LinkedHashSet<>();
        Arrays.sort(nums);
        for (int i=0;i<nums.length-2;i++){
            if ((nums[i]>target&&target>0)&&(nums[nums.length-1]<0&& nums[nums.length-1]<target)){
                return new ArrayList<>(lists);
            }

            for (int j=i+1;j<nums.length-2;j++){
                int l=j+1,r=nums.length-1;
                int tempt =target;
                tempt=tempt-nums[i]-nums[j];
                if ((j!=i+1)&&nums[j]==nums[j-1]){
                    continue;
                }
                if ((tempt<nums[j+1]&&tempt>0)||(tempt<0&&tempt>nums[r])){
                    break;
                }
                while(l<r){
                    if (nums[r]+nums[l]==tempt){
                        List<Integer> list= Arrays.asList(nums[i],nums[j],nums[l],nums[r]);//list是有序的
                        lists.add(list);
                        l++;
                        r--;
                        while (l<r&&nums[l]==nums[l-1]){
                                l++;
                        }
                        while (l<r&&nums[r]==nums[r+1]){
                                r--;
                        }
                    }else if (nums[l]+nums[r]>tempt){
                        r--;
                    }else if (nums[l]+nums[r]<tempt){
                        l++;
                    }
                }
            }
        }
        return new ArrayList<>(lists);


    }
}
```