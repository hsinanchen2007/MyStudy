### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0;i<nums.length - 2;i++){
            int l = i + 1,r = nums.length - 1;
            if (nums[i] > 0){
                break;
            }
            if (i != 0 && nums[i] == nums[i -1]){
                continue;
            }
            while (l < r){
                if (nums[i] + nums[i + 1] > 0 ){
                    break;
                }
                int flag = nums[i] + nums[l] + nums[r];
                if (flag == 0){
                    List<Integer> list = new ArrayList<>();
                    list.add(nums[i]);
                    list.add(nums[l]);
                    list.add(nums[r]);
                    result.add(list);
                    while (l < r && nums[l] == nums[l+1]){
                        l++;
                    }

                    while (l < r && nums[r] == nums[r - 1]){
                        r -- ;
                    }
                    l--;r--;
                }else if (flag < 0 && l<r){
                    l++;
                }else if (flag > 0 && l <r){
                    r --;
                }
            }
        }
        return result;
    }
}
```