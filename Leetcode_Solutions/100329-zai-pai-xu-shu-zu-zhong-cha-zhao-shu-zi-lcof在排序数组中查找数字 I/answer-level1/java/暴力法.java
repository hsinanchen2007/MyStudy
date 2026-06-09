### 遍历数组全部元素，同时计数，没有用到数组有序的特性，时间复杂度高了。
此处撰写解题思路

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        //遍历
        int times = 0;
        for(int number : nums){
            if(target == number){
                times ++;
            }
        }
        return times;

       
    }
   
}
```