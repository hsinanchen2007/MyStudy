### 解题思路
方法1：递归二分查找
当nums[mid]==target时，不返回，而是更新左右边界
方法2：
1、首先利用二分查找找到等于target的位置；
2、然后从该位置开始，向两边扩散，直到找到边界位置


```java
/*
递归二分查找
*/
class Solution {
    //全局变量，记录两个边界；
    int start = -1;
    int end = -1;

    public int[] searchRange(int[] nums, int target) {
        binarySearch(nums, target, 0, nums.length - 1);
        return new int[]{start, end};
    }
    public void binarySearch(int[] nums, int target, int left, int right){
        if(left > right){return;}
        int mid = left + (right - left) / 2;
        if(nums[mid] == target){
            //更新左边界
            if(start == -1 || mid <= start){
                start = mid;
            }
            //更新右边界
            if(mid >= end){
                end = mid;
            }
            //继续向左查找
            binarySearch(nums, target, left, mid -1);
            //继续向右查找
            binarySearch(nums, target, mid + 1, right);
        }
        else if(nums[mid] < target){
            binarySearch(nums, target, mid + 1, right);
        }
        else if(nums[mid] > target){
            binarySearch(nums, target, left, mid - 1);
        }
    }
}
```
```java
//方法2
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = new int[2];
        //[]空数组直接返回[-1,-1]   [2]中查找5也返回[-1,-1]
        if(nums.length == 0 || (nums.length == 1 && nums[0] != target)){
            res[0] = -1;
            res[1] = -1;
            return res;
        }

        int L = 0;
        int R = nums.length - 1;
        while(L <= R){
            int mid = (L + R) / 2;
            if(nums[mid] > target){
                R = mid - 1;
            }
            else if(nums[mid] < target){
                L = mid + 1;
            }
            else if(nums[mid] == target){
                L = R = mid;
                break;
            }
        }
        //遍历数组没找到等于target的位置，返回[-1,-1]
        if(L != R){
            res[0] = -1;
            res[1] = -1;
        }
        else{
            while(nums[L] == target){
                L --;
                //防止越界
                if(L == -1){break;}
            }
            while(nums[R] == target){
                R ++;
                //防止越界
                if(R == nums.length){break;}
            }
            res[0] = L + 1;
            res[1] = R - 1;
        }
        return res;
    }
}
```