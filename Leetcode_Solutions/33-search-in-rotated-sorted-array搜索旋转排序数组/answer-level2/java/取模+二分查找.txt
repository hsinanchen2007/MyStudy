### 解题思路
用取模让数组下标循环，二分找到pivot后， 搜索pivot+1到pivot+nums.length范围。
找到的下标再取模即可
### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int len = nums.length;
        if(len == 0)return -1;
        if(len == 1){
            if(nums[0]==target)return 0;
            return -1;
        }
        if(nums[0] < nums[len-1]){
            return binarySearch(nums, target, 0, len-1)%len;
        }

        //first find max_index

        int max_index = findMaxIndex(nums,0,len-1);
 
        return binarySearch(nums, target, max_index+1, max_index+len)%len;

    }


    public int findMaxIndex(int [] nums, int i, int j){
        int len = nums.length;
        int m = i+(j-i)/2;
        if(nums[m%len]>=nums[(m+1)%len])return m;
        if(nums[m%len]>=nums[0]){
            return findMaxIndex(nums, m+1, j);
        }
        return findMaxIndex(nums, i, m-1);


    }

    public int binarySearch(int [] nums, int target, int i, int j){
        int len = nums.length;
        if(j<i)return -1;
        int m = i+(j-i)/2;
        if(nums[m%len]==target)return m;

        int left = binarySearch(nums, target, i, m-1);
        if(left != -1) return left;

        int right = binarySearch(nums, target, m+1, j);
        if(right != -1) return right;

        return -1;

    }

}
```