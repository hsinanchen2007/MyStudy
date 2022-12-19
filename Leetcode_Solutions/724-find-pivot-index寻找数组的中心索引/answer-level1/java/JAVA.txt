### 解题思路
执行用时 : 1 ms , 在所有 Java 提交中击败了 100.00% 的用户 内存消耗 : 36.8 MB , 在所有 Java 提交中击败了 99.66% 的用户
[-1,-1,-1,0,1,1]这组测试用例考虑到0号位置的判断，因此先算出右边和，判断，再求左边的和。

### 代码

```java
class Solution {
    public int pivotIndex(int[] nums) {
    int leftSum=0,rightSum=0;
        for(int num:nums){
            rightSum+=num;
        }
        for(int i=0;i<nums.length;i++){
            rightSum=rightSum-nums[i];
            if(rightSum==leftSum)
                return i;
            leftSum+=nums[i];
        }
        return -1;
    }
}
```