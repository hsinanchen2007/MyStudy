### 解题思路
![image.png](https://pic.leetcode-cn.com/ecd0a9618952436dc1ee26688d96e98103bb337f119b0b17c3c2df677598e7e1-image.png)
进阶要求空间复杂度为 O(1) 考虑直接在原数组上修改


### 代码

```java
class Solution {
    public boolean circularArrayLoop(int[] nums) {
        int n = nums.length;
        
        for (int i = 0; i < n; ++i) {
            //修改索引值 保证其 < n
            nums[i] = nums[i] % n;
        }
        
        for (int i = 0; i < n; ++i) {
            int f = nums[i];
            //跳过之前尝试过的
            if (f >= n) continue;
            
            int j = i;
            int flag = n + i;
            int last = j;
            while (nums[j] < n) {
                //方向不一致 直接退出
                if (f * nums[j] < 0) break;
                int next = (j + nums[j] + n) % n;
                nums[j] = flag;
                last = j;
                j = next;
            }
            if (nums[j] == flag && j != last) return true;
        }
        
        return false;
    }
}
```