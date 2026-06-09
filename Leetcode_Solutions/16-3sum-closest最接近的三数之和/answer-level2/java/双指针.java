前提：排除特殊情况，将数组排好序。

利用第一个 for 循环固定好第一个数 curr
利用第二个 while 循环，移动 left 指针和 right 指针。
    如果三个数相加
        = target，直接 return
        < target，说明小的数太小，left++
        > target，说明大的数太大，right--

```
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int len = nums.length;
        
        if (len < 3){ // 特殊情况
            return 0;
        }
        int ans = nums[0] + nums[1] + nums[2];

        Map<Integer, Integer> map = new HashMap<>();
        Arrays.sort(nums); // 排个序
        for (int i = 0; i < len; i++){
            int curr = nums[i];  // 固定好最左边的数
            int left = i + 1;   
            int right = len - 1;
            while (left < right){            
                int tmp = curr + nums[left] + nums[right];
                // 更新答案。
                ans = Math.abs(ans - target) <= Math.abs(tmp - target) ? ans : tmp;
                if (tmp == target){
                    return ans;
                } else if (tmp < target){
                    left++;
                } else{
                    right--;
                }
            }
        }        
        return ans;
    }
}
```
