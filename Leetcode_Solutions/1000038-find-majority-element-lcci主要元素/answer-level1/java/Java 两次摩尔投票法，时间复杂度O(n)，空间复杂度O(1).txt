```
class Solution {
    public int majorityElement(int[] nums) {
        int res = nums[0];
        int votes = 0;
        // 第一遍投票，找出主要元素
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == res)
                votes++;
            else 
                votes--;
            // 主要元素可能不存在，所以要对i+1进行边界判定
            if (votes == 0 && i + 1 < nums.length)
                res = nums[i + 1];
        }
        // 票数为0，主要元素不存在
        if (votes == 0)
            return -1;
        
        // 再次投票，检测主要元素是否正确
        votes = 0;
        for (int num : nums)
            if (num == res)
                votes++;
            else    
                votes--;
        
        return votes > 0 ? res : -1;
    }
}
```
运行结果：
![image.png](https://pic.leetcode-cn.com/72e1e3c43b78d11d6fdc8dc88a3174b9dfeaa2fb0b7900a89c08a3241e3445d7-image.png)
