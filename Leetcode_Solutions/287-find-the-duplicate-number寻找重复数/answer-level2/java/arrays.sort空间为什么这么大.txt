### 解题思路
此处撰写解题思路
我明白了。因为是只读数组。所以我要先复制一遍，这样的空间是O(N)
执行用时 :
3 ms
, 在所有 Java 提交中击败了
58.93%
的用户
内存消耗 :
39.7 MB
, 在所有 Java 提交中击败了
5.32%
的用户
### 代码

```java
class Solution {
    public int findDuplicate(int[] nums) {
        Arrays.sort(nums);
        int res = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length - 1; i++){
            if (nums[i] == nums[i + 1]) return res = nums[i];
        }
        return -1;
    }
}
```