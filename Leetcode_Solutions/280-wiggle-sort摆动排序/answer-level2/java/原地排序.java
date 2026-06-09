### 解题思路
此处撰写解题思路
执行用时 :
1 ms
, 在所有 Java 提交中击败了
95.92%
的用户
内存消耗 :
40.5 MB
, 在所有 Java 提交中击败了
8.33%
的用户
### 代码

```java
class Solution {
    public void wiggleSort(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++){
            if (i % 2 == 0 && nums[i] > nums[i + 1]) swap(nums, i, i + 1);
            if (i % 2 == 1 && nums[i] < nums[i + 1]) swap(nums, i, i + 1);
        }
    }
    private void swap(int[] nums, int left, int right){
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }
}
```


然后好好看看你之前提交的错的。。。。。离谱
```
class Solution {
    public void wiggleSort(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++){
            if (nums[i] % 2 == 0 && nums[i] > nums[i + 1]) swap(nums[i], nums[i + 1]);
            if (nums[i] % 2 == 1 && nums[i] < nums[i + 1]) swap(nums[i], nums[i + 1]);
        }
    }
    private void swap(int left, int right){
        int tmp = left;
        left = right;
        right = tmp;
    }
}
```
