### 解题思路
n长度的数组中包含0-n-1的不重复数字，取出一个数字以当前数字作为下一个数字的下标，可以看出按此逻辑取出的数字最终会构成一个圆环，剩下的数字也如此能构成圆环，找最长的序列，就是找最大的圆环。
因此，题目可以转换为，一个图中存在一个或多个圆环，求其中最大的圆环长度。
操作：
1.以原数组为集合A,B为空集合；
2.按题目逻辑取A中的数放入B中；
3.必然会发生，A中没有下一个要取的数（此数已在B中），此时B中数字构成一个圆环;
4,记录其size，清空集合B,继续从第2步开始，直到A中已经没有元素；
5.记录的size中的最大值，即为题目所求


### 代码

```java
class Solution {
    public int arrayNesting(int[] nums) {
        int maxSize = 0;
        // 取数组中为使用的元素开始寻找环
        for(int i=0;i<nums.length;i++){
            // 被使用过的元素直接忽略
            if(nums[i]==-1){
                continue;
            }
            int index = i;
            int size = 0;
            // 取的下一数字已为-1，即A中已经没当前环的下继，可以结束寻找下一环
            while(nums[index]!=-1){
                // 集合B的size记录
                size++;
                // 取出当前数字
                int tmp = nums[index];
                // 取出的数字标记为-1
                nums[index] = -1;
                // 下一数字下标为当前数字值
                index = tmp;
            }
            // 记录最大环
            maxSize = Math.max(size,maxSize);
        }
        return maxSize;
    }
}
```