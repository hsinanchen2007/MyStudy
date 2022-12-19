### 解题思路
写的时候突然想到归并排序，因为归并排序先把数组分隔成一个一个的单个元素，然后再merge,既然都成一个一个的元素了，那么也就能跟目标值比较是否想等了呀，这就是主要思路。
![image.png](https://pic.leetcode-cn.com/2346ab9d54353744e88642a0594d1f635b06fc3cff4fa44f54658555eebc4cf9-image.png)


### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        if(nums.length<=0){
            return -1;
        }
        int index = recursion_search(nums,0,nums.length-1,target);
        return index;
    }

    private int recursion_search( int[] nums, int low, int high, int target ) {
        if(low>=high){
            if(nums[low]==target){
                return low;
            }else{
                return -1;
            }
        }
        int middle = low + ((high-low)>>1);
        int f1 = recursion_search( nums,low,middle,target );
        int f2 = recursion_search( nums,middle+1,high,target );
        if(f1!=-1){
            return f1;
        }
        if(f2 != -1){
            return f2;
        }
       return -1;
    }
}
```