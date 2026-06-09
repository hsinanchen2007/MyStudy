### 解题思路
此处撰写解题思路
因为第一个非0减0会干扰res<5的判断，所以让nums[i+1] - nums[i],并且遇见0continue
执行用时 :
1 ms
, 在所有 Java 提交中击败了
85.63%
的用户
内存消耗 :
37 MB
, 在所有 Java 提交中击败了
100.00%
的用户
### 代码

```java
class Solution {
    public boolean isStraight(int[] nums) {
        Arrays.sort(nums);
        int res = 0;
        for (int i = 0; i < 4;i++){
            if (nums[i] == 0) continue;
            if (nums[i] == nums[i+1] ) return false;
            res += (nums[i+1] - nums[i]);
        }
        return res < 5;
    }
}
```