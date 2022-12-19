通常，双指针需要定义两个数组下标，分别为快指针和慢指针。
若利用`foreach`方法，可写出简洁的双指针代码。具体实现如下：
```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 0;
        for(int n : nums)
            if(i < 2 || n > nums[i-2])
                nums[i++] = n;
        return i;
    }
}
```
这里，`foreach`循环中的`n`充当了快指针的角色，而`i`则为慢指针。其思路是，若当前元素比`i`前面两个位置所在元素大，说明出现了新元素（题目已说明数组是排序的），则将新元素复制到`i`所在位置。
由此，可通过同样的思路简化 [26. 删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/) 中的代码，如下：
```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 0;
        for(int n : nums)
            if(n != nums[i])
                nums[++i] = n;
        return i+1;
    }
}
```
同样，可简化 [27. 移除元素](https://leetcode-cn.com/problems/remove-element/) 的代码，如下：
```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0;
        for(int n :nums)
            if(n != val)
                nums[i++] = n;
        return i;
    }
}
```
同时，提供另一种思路。在进行双指针交换前，先判定该元素出现次数。具体实现如下：
```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int j = 0, count = 1;
        for(int i = 1; i < nums.length; i++){
            if(nums[i-1] != nums[i])
                count = 1;
            else
                count++;
            if(count <= 2){
                j++;
                nums[j] = nums[i];
                // 或者将这两句合并为nums[++j] = nums[i];
            }
        }
        return j+1;
    }
}
```

