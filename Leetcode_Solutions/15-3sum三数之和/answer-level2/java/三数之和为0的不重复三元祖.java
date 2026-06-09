### 解题思路
去除重复项很关键，必须保证中间数小于最大数，如果三数之和等于0，同时减小最大数和增大中间数；如果三数之和大于0，就得减小最大数；如果三数之和小于0，就得增大中间数。

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);//先对数组进行排序
        List<List<Integer>> ls = new ArrayList<>();//创建一个两重动态数组，作为返回数组
        for(int i = 0; i < nums.length - 2; ++i){
            if(i == 0 || (i > 0 && nums[i] != nums[i - 1])){//跳过可能重复的答案
                int j = i + 1, k = nums.length - 1;
                while(j < k){//必须k的序号比j大
                    if(nums[j] + nums[k] == -nums[i]){
                        ls.add(Arrays.asList(nums[i], nums[j], nums[k]));
                        while(j < k && nums[j] == nums[j + 1]){
                            j++;
                        }
                        while(j < k && nums[k] == nums[k - 1]){
                            k--;
                        }
                        j++;
                        k--;
                    }else if(nums[j] + nums[k] < -nums[i]) {
                        while(j < k && nums[j] == nums[j + 1]){
                            j++;//跳过重复值
                        }
                        j++;
                    }else{
                        while(j < k && nums[k] == nums[k - 1]){
                            k--;
                        }
                        k--;
                    }
                }

            }
        }
        return ls;
    }
}
```