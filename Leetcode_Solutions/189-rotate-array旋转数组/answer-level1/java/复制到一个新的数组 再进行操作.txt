### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void rotate(int[] nums, int k) {
        int[] tempNums = new int[nums.length];
        for(int i=0;i<nums.length;i++) {//复制出一个数组
        	tempNums[i]=nums[i];
        }
        for(int i=0;i<tempNums.length;i++) {
        	int j = (i+k)%nums.length;//向后移位
        	nums[j]=tempNums[i];
        }
    }
}
```