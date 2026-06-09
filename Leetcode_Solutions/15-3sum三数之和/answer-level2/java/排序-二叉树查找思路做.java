### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {

        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if(nums ==null || nums.length <3){
                return result;
        }
        Arrays.sort(nums);
        int length = nums.length;
        for(int i =0; i < length-2;i++){
                if(nums[i]>0){break;}
                if(i>0 && nums[i] ==nums[i-1] ){continue;}
                int twoSum = 0-nums[i];
                int l = i+1;
                int r = length-1;
                while(l < r){
                     int sum = nums[l]+nums[r];
                     if(sum > twoSum){
                         r--;
                     }
                    if(sum < twoSum){
                         l++;
                     }
                     if(sum == twoSum){
                         List<Integer> tmp = new ArrayList<Integer>();
                         tmp.add(nums[i]);
                         tmp.add(nums[l]);
                         tmp.add(nums[r]); 
                         result.add(tmp);
                         while(l < r){
                                if(nums[l] == nums[l+1]){
                                    l++;
                                }else if(nums[r] == nums[r-1]){
                                    r--;
                                }else{
                                    break;
                                }
                         }  
                         l++;
                         r--;
                     }
                    

                }
                



        }

        return result;

    }
}
```