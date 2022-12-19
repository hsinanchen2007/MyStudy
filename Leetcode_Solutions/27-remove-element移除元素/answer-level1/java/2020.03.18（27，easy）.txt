### 解题思路
本题和283题很像，只是这个索引**k是从0开始**，用while循环依次遍历数组，将满足题意的元素赋值给k索引所在位置即可

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int n = nums.length;
        int k = 0;
        int i = 0;
        while(i < n){
            if(nums[i] != val){
                nums[k++] = nums[i];
            }
            i++;
        }
        return k;
    }
}
```