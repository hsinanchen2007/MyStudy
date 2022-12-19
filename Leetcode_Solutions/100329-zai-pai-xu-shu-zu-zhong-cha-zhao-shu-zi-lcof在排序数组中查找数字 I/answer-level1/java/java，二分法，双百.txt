**这道题其实是就是一个二分查找的题目：先找到target目标值在数组中的一个位置index，然后再往后和往前计target的总个数，代码如下：**
```
class Solution {
    public int search(int[] nums, int target) {
        int index = binarySearch(nums,target);
        if (index==-1) {return 0;}
        int count = 1;
        for (int i = index+1; i <= nums.length-1; i++) {
            if (nums[i]==target) {count++;}
            else {break;}
        }
        for (int i = index-1; i >=0 ; i--) {
            if (nums[i]==target) {count++;}
            else {break;}
        }
        return count;
    }

    public int binarySearch(int[] nums, int target) {
        int start = 0, end = nums.length-1;
        while (start<=end) {
            int mid = (start+end)>>1;
            if (nums[mid]<target) {start=mid+1;}
            else if (nums[mid]>target) {end=mid-1;}
            else {return mid;}
        }
        return -1;
    }
}
```
![image.png](https://pic.leetcode-cn.com/de1f8d99e5df1502e8e2bd5acab30f1f81aa6b556cd3af36f7f2b4212a45b169-image.png)
