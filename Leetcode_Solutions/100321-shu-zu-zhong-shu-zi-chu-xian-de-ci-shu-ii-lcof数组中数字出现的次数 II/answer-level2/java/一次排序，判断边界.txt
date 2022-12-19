### 解题思路
此处撰写解题思路
执行用时 :
7 ms
, 在所有 Java 提交中击败了
83.79%
的用户
内存消耗 :
40.5 MB
, 在所有 Java 提交中击败了
100.00%
的用户
### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        Arrays.sort(nums);
        int len = nums.length;
        if (nums[len-1] != nums[len-2]) return nums[len-1];
        int[] tmp = new int[3]; 
        for (int i = 0; i < len - 1; i+=3){
            if (nums[i] != nums[i+1] || nums[i+1] != nums[i+2]){
                tmp[0] = nums[i];
                tmp[1] = nums[i+1];
                tmp[2] = nums[i+2];
                break;
            }
        }
        if (tmp[0] == tmp[1]) return tmp[2];
        if (tmp[0] == tmp[2]) return tmp[1];
        return tmp[0];
    }
}
```