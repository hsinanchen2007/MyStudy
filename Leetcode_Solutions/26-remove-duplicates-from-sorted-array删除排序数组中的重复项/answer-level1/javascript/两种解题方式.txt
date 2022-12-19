### 解题思路
官方题解的javascript实现思路。
实现的核心就在于：遍历整个数组，将存储每一个不一样的数，并放入这个数组中。
官方使用双指针。
这个双指针并不是从两边一同进行移动，而是从一边开始，用追逐的方法。
一根快，一根慢。慢的那个有两个作用，即用来存放快指针指到的最新不同元素 作为比较的一个条件  。与此同时还是输出数组的指针，每一个不同的数都会被分配到他指向的位置上，存储在其中。
### 代码
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
     if (nums.length == 0) return 0;
     var i=0;
     for(var j=1;j<nums.length;j++){
         if(nums[i]!=nums[j]){
             i++;
              nums[i]=nums[j];
            
         }
     }
     return i+1;
};
```
如下是我的**java**代码
其核心和官方题解的核心差不多，也是遍历整个数组，对不同的数进行存储。
但是明显，官方题解的算法要更加的简洁。只用数组中的内容进行比较。
```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int number = Integer.MAX_VALUE;
        int flag = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != number) {
                number = nums[i];
                nums[flag] = nums[i];
                flag++;
            }
        }
        return flag;
    }
}
```
