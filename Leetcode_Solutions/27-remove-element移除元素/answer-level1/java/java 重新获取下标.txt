### 解题思路
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
35.1 MB
, 在所有 Java 提交中击败了
72.80%
的用户

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int j=0; //重新定义下标
        for(int i =0; i<nums.length;i++) {
            if(nums[i] != val) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
}

```