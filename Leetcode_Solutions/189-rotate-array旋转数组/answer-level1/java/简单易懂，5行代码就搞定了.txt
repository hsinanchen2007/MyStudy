### 解题思路
题目描述中是一步步移动数组中的元素，大家从整体来看，经过k步移动之后其实就是将数组中的最后k个元素放到数组最前面，而数组前nums.length-k个元素则往后移动k个位置
测试用例中有出现移动次数k比数组元素个数大的情况，将k减去数组元素个数即可，因为移动nums.length次其实就是本身
虽然运行时间快内存占用少，但是使用了额外空间
![image.png](https://pic.leetcode-cn.com/9c6e76fab0c47c74b32fe33af04fd6e6bd70bb3a56d527820e7c1640c12ae66f-image.png)

### 代码

```java
class Solution {
    public void rotate(int[] nums, int k) {
        if(k>nums.length) k-=nums.length;
        int[] res = new int[k];
        System.arraycopy(nums,nums.length-k,res,0,k);//将nums数组中需要移动的后k个元素复制到数组res中
        System.arraycopy(nums,0,nums,k,nums.length-k);//将nums数组中前nums.length-k元素向后移动k个位置
        System.arraycopy(res,0,nums,0,k);//将res数组中所有元素放到nums数组中的前k个位置
    }
}
```