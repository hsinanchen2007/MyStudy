### 解题思路
如果用暴力解法，会涉及到数据的大量移动，非常耗费时间
我的思路是根据index里的数据计算出最终的每个数字对应的下标，然后直接生成target，这样就不用频繁移动数据了

### 代码

```java
class Solution {

public int[] createTargetArray(int[] nums, int[] index) {
        for (int i = 0; i < nums.length; i++) {
            // 如果index[i] <= i+1，就意味着index[i]是已经出现了的下标
            if (index[i] <= i+1) {
                // 从0开始遍历index，找出index里大于或等于index[i]的元素，加一（即最终位置向后移动一位）
                for (int j = 0; j < i; j++) {
                    if (index[j] >= index[i]) {
                        index[j] += 1;
                    }
                }
            }
        }
        int[] result = new int[nums.length];
        for (int i=0;i<result.length;i++){
            result[index[i]] = nums[i]; 
        }
        return result;
    }
}
```