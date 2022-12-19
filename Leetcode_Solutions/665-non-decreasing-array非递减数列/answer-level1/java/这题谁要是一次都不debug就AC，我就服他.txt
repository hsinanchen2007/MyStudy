### 解题思路
![截屏2020-03-10下午6.47.42.png](https://pic.leetcode-cn.com/7317de3b9afd56426c2ac6cce9989ddc6d6e421f1810e9d75f2c4fde7134ccc6-%E6%88%AA%E5%B1%8F2020-03-10%E4%B8%8B%E5%8D%886.47.42.png)
我debug多次还是错了一次，太粗心了，这题没啥好说的，注意判断就好了

[前值，中值，后值]
看注释，这题不应该是简单题，起码判断条件就很多

### 代码

```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        int len = nums.length;
        // 长度小于3一定能成立
        if(len < 3) return true;
        // 是否可以使用一次改变机会
        boolean isChange = true;
        for (int i = 1; i < len - 1; i++) {
            if (nums[i] < nums[i - 1] && isChange) {
                // 前值 < 中值 < 后值[1,2,3]
                if (nums[i + 1] < nums[i]) return false;
                if (nums[i + 1] > nums[i - 1])
                    // 这里优先变掉中值[2,1,3]
                    nums[i] = nums[i - 1];
                else
                    // 这里只能变掉前值值[4,2,3]
                    nums[i - 1] = nums[i];
                isChange = false;
            } 
            else if (nums[i] >= nums[i - 1]) {
                // 这里不需要使用改变机会
                if (nums[i + 1] >= nums[i]) continue;
                if (nums[i + 1] < nums[i - 1]) 
                    //这里变掉后值[2,5,3]
                    nums[i + 1] = nums[i];
                if (nums[i + 1] < nums[i]) 
                    //这里优先变掉中值[-1,4,2,3]
                    nums[i] = nums[i + 1];
                // 如果之前已经改变过，没有机会改变
                if (!isChange)
                    return false;
                isChange = false;
            } 
            else 
                // 如果中值小于前值又没有机会只能失败
                return false;
        }
        return true;
    }
}
```
### 时间复杂度 O(N)