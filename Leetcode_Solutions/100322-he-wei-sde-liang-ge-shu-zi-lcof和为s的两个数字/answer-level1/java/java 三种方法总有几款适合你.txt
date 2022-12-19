**这道题我想了三个方案：
1. 第一个是通过二分折半查找，时间复杂度O(nlogn)，空间复杂度O(1)，代码如下：
```
class Solution {
    public int[] twoSum(int[] nums, int target) {
        if (nums.length<=1) {return new int[0];}
        for (int i = 0; i < nums.length; i++) {
            int index = binaryFindNum(nums,i,target);
            if (index!=-1) {return new int[]{nums[i],nums[index]};}
        }
        return new int[0];
    }

    public int binaryFindNum(int[] nums, int i, int target) {
        int num = target - nums[i];
        int start = i+1, end = nums.length-1;
        while (start<=end) {
            int mid = (start+end)>>1;
            if (num<nums[mid]) {end=mid-1;}
            else if (num>nums[mid]) {start=mid+1;}
            else {return mid;}
        }
        return -1;
    }
}
```
2. 第二个方法是通过set集合来存放已经add的元素，可以实现O(1)找到targe-num，时间复杂度O(n)，空间复杂度O(n)，代码如下：
```
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            if (set.contains(target-num)) {return new int[]{num,target-num};}
            else {set.add(num);}
        }
        return new int[0];
    }
}
```
3. 第三个方法是通过双指针，p指向头，q指向尾，如果nums[p]+nums[q]比target大，需要向前移动q，反之向后移动p，如果相等就是找到正确答案了。时间复杂度O(n)，空间复杂度O(1)，代码如下：
```
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int p = 0, q = nums.length-1;
        while (p<q) {
            if (nums[p]+nums[q]<target) {p++;}
            else if (nums[p]+nums[q]>target) {q--;}
            else {return new int[]{nums[p],nums[q]};}
        }
        return new int[0];
    }
}
```
![image.png](https://pic.leetcode-cn.com/e0f86d1f1b2956732f8b6ee78b0b9d4c1d9280bea1e41910a80305504d81e7f9-image.png)



**