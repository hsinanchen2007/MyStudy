### 解题思路
题解参考
[https://leetcode-cn.com/problems/linked-list-random-node/solution/xu-shui-chi-chou-yang-by-ccdmw/](类似的题目)

### 代码

```java
class Solution {

    private final int[] data;

    public Solution(int[] nums) {
        data = nums;
    }

    public int pick(int target) {
        int len = 1;
        int current = -1;
        for (int i = 0; i < data.length; i++) {
            if (data[i] == target){
                //以 1 / len 的概率选中该元素
                int temp = 1 + (int) (Math.random() * len);
                if (temp == len)
                    current = i;
                len++;
            }
        }
        return current;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
```