**方法一：快慢双指针 - 当要删除的元素很多时**
```java
public int removeElement(int[] nums, int val) {
    int current = -1;   // 慢指针
    int index = 0;      // 快指针
    int length = nums.length;
    
    for(; index < length; index++){、
        // 把不等于 val 的值移到数组的前面
        if(nums[i] != val){
            nums[++current] = nums[i];
        }
    }
    return current + 1;
}
```
![27移除元素1.gif](https://pic.leetcode-cn.com/495a2ba4abd0333aa91dafc49aaa91c133e8f418b437f51d16a3ae976e9a4241-27%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A01.gif)




**方法二：左右双指针 - 当要删除的元素很少时**
```java
public int removeElement(int[] nums, int val) {
    int current = nums.length;   // 右指针
    int index = 0;               // 左指针
    
    while(index < current){
        // 把等于 val 的值移到数组的后面
        if(nums[index] == val){
            nums[index] = nums[--current];
        }else{
            index++;
        }
    }
    
    return current;
}
```
![27移除元素2.gif](https://pic.leetcode-cn.com/d04c14cbf0754e8ec3752cdfb52d9f71951480deafaaa7ee1ef7fd8450c937a5-27%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A02.gif)

博客：www.lxiaocode.com
