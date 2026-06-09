# 方法1：双指针
创造一个慢指针，指向不重复的位置
快指针正常遍历

```java
public class Solution {
   public static int removeDuplicates(int[] nums) {
       if (nums.length==0)return 0;
       int slow=1;
       for (int i=1;i<nums.length;i++){
           if (nums[i]!=nums[i-1]){
               nums[slow++]=nums[i];
           }
       }
       return slow;
   }
}
```
**复杂度分析：**
    时间复杂度O（n）
    空间复杂度O（1）

# 方法2：新建数组
新建一个数组，读到不重复的就放入
最后把新数组的值放入原数组

```java
public class Solution {
   public static int removeDuplicates(int[] nums) {
       if (nums.length==0)return 0;
       int arr[]=new int[nums.length];
       arr[0]=nums[0];
       int count=1;
       for (int i=1;i<nums.length;i++){
           if (nums[i]!=nums[i-1]){
               arr[count++]=nums[i];
           }
       }
       for (int i=1;i<arr.length;i++){
           nums[i]=arr[i];
       }
       return count;
   }
}
```
**复杂度分析：**
    时间复杂度O（n）
    空间复杂度O（n）


