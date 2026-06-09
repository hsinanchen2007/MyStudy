### 解题思路
此处撰写解题思路
先假设最大的NUM就是nums[0];
然后直接在遍历里找到最大值的下标

再写一个遍历，去掉找到的最大值
再把2倍大于最大值的元素筛掉，直接返回-1

其他的就是符合条件的值，返回最大值的下标


### 代码

```java
class Solution {
    public int dominantIndex(int[] nums) {
        int maxNum = nums[0];
        int a = 0;

        for(int i=0;i<nums.length;i++){
            if(nums[i] >= maxNum){
                maxNum = nums[i];
                //把最大值的下标给拿过来
                a = i;
            }
        }

        for(int i=0;i<nums.length;i++){
            if(i!=a){
                if(nums[i]*2>nums[a]){
                    return -1;
                }
            }
        }
       return a;
    }
}
```