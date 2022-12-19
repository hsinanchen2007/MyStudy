### 解题思路
![微信截图_20200312213623.png](https://pic.leetcode-cn.com/cf309e862d8152104fd3d915c9b663fba90c1be974ea72021706c36bda608f53-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200312213623.png)


1. 若第一个元素值不等于0，说明缺失的数字为0；
2. 若是最后一个元素值与下标相等（n-1），则数组为完整的，缺失的数字为后续部分，所以返回数组长度（n）；
3. 递归，不断取“元素值不等于下标”那一半数组，直到得到开始不等的元素下标，即为缺失的数字。

```
∵   nums[i] == i; j = i + 1;
又有 nums[j] != j;       //除缺失数外，数组为连续递增
∴   nums[j] == j + 1;   //缺失的数字为j.
```


### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int maxIndex = nums.length - 1;
        if(nums[0] != 0)
            return 0;
        if(nums[maxIndex] == maxIndex)
            return maxIndex + 1;

        return recursive(nums, 0, maxIndex);
    }
    int recursive(int[] nums, int left, int right){
        if(left == right) return right;
        int mid = (left + right)/2;
        if(nums[mid] == mid){
            return recursive(nums, mid + 1, right);
        }else {
            return recursive(nums, left, mid);
        }
    }
}
```