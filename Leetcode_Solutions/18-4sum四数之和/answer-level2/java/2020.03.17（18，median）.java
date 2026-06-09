### 解题思路
本题为加加加强版的四数之和

主要思想是利用**滑动窗口**，利用**两个索引指针** l 和 r 在 i 和 j 之间移动

一定要**先排序**，可以减少复杂度。然后判空，考虑边界值，去重。

剩下的思路和**三数之和**很像了，基本题型就是这样。

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);//先排序
        int n = nums.length;
        if(nums == null || nums.length < 4){//判空
            return ans;
        }
        //i为起点，j为终点，l与r构成滑动窗口
        for(int i = 0; i < n - 3; i++){
            if(nums[i] * 4 > target){//如果一开始就比target大，那么后面都比target大，就直接break掉
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]){//去重
                continue;
            }
            for(int j = n - 1; j - i > 2; j-- ){
                if(nums[j] * 4 < target){//如果最后一个数都比target小，那在他前面的会更小，就直接break掉
                    break;
                }
                if(j < n - 1 && nums[j] == nums[j + 1]){//去重
                    continue;
                }
                int l = i + 1;//i的右边
                int r = j - 1;//j的左边
                while(l < r){
                    int sum = nums[i] + nums[l] + nums[r] + nums[j];
                    if(sum == target){
                        ans.add(Arrays.asList(nums[i],nums[l],nums[r],nums[j]));
                        while(l < n - 2 && nums[l] == nums[l + 1]){//去重
                            l++;
                        }
                        while(r > 2 && nums[r] == nums[r - 1]){//去重
                            r--;
                        }
                        l++;
                        r--;
                    }else if(sum > target){
                        while(r > 2 && nums[r] == nums[r - 1]){//去重
                            r--;
                        }
                        r--;
                    }else if(sum < target){
                        while(l < n - 2 && nums[l] == nums[l + 1]){//去重
                            l++;
                        }
                        l++;
                    }
                }
            }
        }
        return ans;
    }
}
```