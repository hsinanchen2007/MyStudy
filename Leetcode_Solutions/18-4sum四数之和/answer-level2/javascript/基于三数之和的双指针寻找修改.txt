
![截屏2019-12-0417.03.46.png](https://pic.leetcode-cn.com/ea4b638ca679a3492acc3edf216afbb75daa1144856cbcb0099562a7c3885cd6-%E6%88%AA%E5%B1%8F2019-12-0417.03.46.png)

**代码**

```
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
    let ans = [];
    const len = nums.length;
    if(nums == null || len < 4) return ans;
    nums.sort((a, b) => a - b); // 排序
    for (let i = 0; i < len ; i++) {
        if(nums[i] == nums[i-1]) continue; // 去重
        for (let j = len - 1; j > i + 1; j--) {
            if(nums[j] == nums[j+1]) continue; // 去重
            let L = i + 1;
            let R = j - 1;
            while(L < R){
                const sum = nums[i] + nums[L] + nums[R] + nums[j];
                if(sum == target){
                    ans.push([nums[i],nums[L],nums[R],nums[j]]);
                    while (L<R && nums[L] == nums[L+1]) L++; // 去重
                    while (L<R && nums[R] == nums[R-1]) R--; // 去重
                    L++;
                    R--;
                }
                else if (sum < target) L++;
                else if (sum > target) R--;
            }
        }   
    }        
    return ans;
};
```
