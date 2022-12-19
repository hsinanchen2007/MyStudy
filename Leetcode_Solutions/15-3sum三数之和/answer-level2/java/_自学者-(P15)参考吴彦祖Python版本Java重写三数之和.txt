### 思考
 回溯算法全排列，依旧可以探索出结果，唯一困难就是去重，但是如果用Set保存，再转换，去重也应该问题不大，最关键是回溯用的是递归算法，效率会比双指针低很多。
### 解题思路
* 对数组进行排序，为剔除重复计算做准备。
* 遍历排序后数组：
  * 若 nums[i]>0：因为已经排序好，num[left] = num[i+1]，所以num[left]也大于零，因为right永远大于left所以num[right]一定也大于零，所以后面不可能有三个数加和等于0，直接返回结果。
  * 对于重复元素：跳过，避免出现重复解
  * 令左指针 left=i+1，右指针 right = n-1，当 left < right 时，执行循环：
     当 nums[i]+nums[L]+nums[R]==0，执行循环，判断左界和右界是否和下一位置重复，去除重复解。并同时将 L,R 移到下一位置，寻找新的,若和大于0，说明 nums[right] 太大，right左移;若和小于0，说明 nums[left]太小，left右移

### 代码

```java []
// 笨小孩的仿造品
class Solution {
    private List<List<Integer>> result;    
    Solution() {
        result = new ArrayList<>();
    }

    public List<List<Integer>> threeSum(int[] nums) {        
        if(nums==null || nums.length < 3) {
            return result;
        }
        int n= nums.length;
        Arrays.sort(nums);
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                //因为排过序，所以第i个元素大于0时,left = i+1 必然大于0，剩余两个数相加不会等于零
                return result;
            }

            if(i > 0 && nums[i] == nums[i-1]) {
                //重复元素不做计算，直接判断下一个元素
                continue;
            }
            // 左指针
            int left = i + 1;
            // 右指针
            int right = n - 1;
            while(left < right) {
                if(nums[i] + nums[left] + nums[right] == 0) {
                    int[] three = {nums[i], nums[left], nums[right]};
                    List<Integer> threeList = Arrays.stream(three).boxed().collect(Collectors.toList());
                    result.add(threeList);
                    
                    // 过滤左侧相同元素
                     while(left < right && nums[left] == nums[left + 1]) {
                        left = left + 1;
                     }
                    // 过滤右侧相同元素
                    while(left < right && nums[right] == nums[right - 1]) {
                        right = right-1;
                    }
                    
                    left = left + 1;
                    right = right - 1;
                }else if(nums[i] + nums[left] + nums[right] > 0) {
                    // 若和大于 0，说明 nums[R]太大，right左移
                   right = right - 1;
                } else {
                    // 若和小于 0，说明 nums[L]太小，left右移
                    left = left + 1;
                }
            }            
        }
        return result;
    }
}
```
```python []
// 吴彦祖的python代码
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        n=len(nums)
        res=[]
        if(not nums or n<3):
            return []
        nums.sort()
        res=[]
        for i in range(n):
            if(nums[i]>0):
                return res
            if(i>0 and nums[i]==nums[i-1]):
                continue
            L=i+1
            R=n-1
            while(L<R):
                if(nums[i]+nums[L]+nums[R]==0):
                    res.append([nums[i],nums[L],nums[R]])
                    while(L<R and nums[L]==nums[L+1]):
                        L=L+1
                    while(L<R and nums[R]==nums[R-1]):
                        R=R-1
                    L=L+1
                    R=R-1
                elif(nums[i]+nums[L]+nums[R]>0):
                    R=R-1
                else:
                    L=L+1
        return res
```