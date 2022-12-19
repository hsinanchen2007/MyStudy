### 解题思路
核心是找出 [1,数组长度] 中第一个没在原数组中出现的值。
这里初始化一个boolean辅助数组进行实现。

### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        if (nums.length <= 0) {
            return 1;
        }
        // init
        boolean[] temp = new boolean[nums.length];
        int t = 0;
        for (int i = 0; i < nums.length; i++) {
            if( nums[i] >= 1 && nums[i] <= nums.length) {
                temp[nums[i]-1] = true;
            }
        }
        // find
        int index = 0;
        while(index < temp.length) {
            if(temp[index]) {
                index++;
            } else {
                break;
            }
        }
        index++;
        return index;
    }
}
```