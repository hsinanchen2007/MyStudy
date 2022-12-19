### 解题思路
1. 先将数据从小到大排序
2. 进行第一重遍历，依次取出nums[i],然后定义两个变量lo，hi分别指向k+1和数组最后一个元素
3. 计算s = nums[lo]+nums[hi]+nums[i]的值,可分为以下3种情况
   - s = 0;即找到一个目标解
   - s > 0;说明大了，需要取小一点的元素，即取nums[--hi]
   - s < 0;说明小了，需要取大一点的元素，即取nums[++lo]
4. 以上3种情况都需要进行去重处理，即nums[lo],nums[hi],nums[i] 都不能取与已有解相同的元素  
 

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList();
        for(int i = 0; i < nums.length - 2; i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int lo = i + 1,hi = nums.length - 1,target = -nums[i];
            while(lo < hi){
                if(nums[lo] + nums[hi] == target){
                    ans.add(Arrays.asList(nums[i],nums[lo],nums[hi]));
                    lo++;hi--;
                    while(lo < hi && nums[lo] == nums[lo - 1]) lo++;
                    while(lo < hi && nums[hi] == nums[hi + 1]) hi--;
                }else if(nums[lo] + nums[hi] > target){
                    hi--;
                }else{
                    lo++;
                } 
            }
        }
        return ans;
    }
}
```
### 时间复杂度

双重循环，总的时间复杂度为O(n^2)