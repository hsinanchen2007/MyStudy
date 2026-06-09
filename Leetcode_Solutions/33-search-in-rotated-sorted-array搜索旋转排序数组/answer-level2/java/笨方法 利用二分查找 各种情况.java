### 解题思路
二分查找 各种情况 主要有以下几种情况
1，区间数组是非旋转数组
2，第一个节点与目标值的比较
3，中间节点与目标值的比较
4，中间节点处于第一个排序还是第二个排序

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
         //数组为空
         if (nums.length < 1) {
             return -1;
         }
         
         //数组只有一个值
         if (nums.length == 1) {
             if (nums[0] == target) {
                 return 0;
             } else {
                 return -1;
             }
         }

         //二分查找找目标
         int L = 0;//左指针
         int R = nums.length-1;//右指针
         int mid = L + (R-L)/2;

         while (L < R) {
             //判断边界条件 返回相应的脚标
             if (target == nums[L]) {
                 return L;
             } else if (target == nums[mid]) {
                 return mid;
             } else if (target == nums[R]) {
                 return R;
             }
             
             //区间内是旋转数组
             if (nums[L] > nums[R]) {
                 if (nums[L] > target) {
                    if (nums[mid] > nums[L]) {//mid在第一个生序中
                        L = mid + 1;
                    } else if (nums[mid] < target){
                        L = mid + 1;    
                    }  else {
                        R = mid - 1;
                    }
                 } else if (nums[L] < target) {
                     if (nums[mid] > nums[L]) {//判断是否在第一个生序中
                            if (nums[mid] < target) {//右区间
                               L = mid + 1;
                            } else {
                               R = mid - 1;
                            }
                     } else {
                        R = mid - 1;
                     }
                 }
             } else {//不是旋转数组
                if (nums[L] > target || nums[R] < target) {
                    return -1;
                } else if (nums[mid] > target) {//左区间
                    R = mid - 1;   
                } else {//右区间
                    L = mid + 1;
                }
             }
             mid = L + (R-L)/2;
         }

         //没找到
         return -1;

    }
}
```