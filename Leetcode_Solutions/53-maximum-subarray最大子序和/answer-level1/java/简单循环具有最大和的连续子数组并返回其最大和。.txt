### 解题思路
1. 从第一个元素开始，逐渐向后加上一个后续元素，每加一次，并判断确定这一个循环最大的连续子数组和
2. 从第二个元素开始，逐渐向后加上一个后续元素，每加一次，并判断确定这一个循环最大的连续子数组和
2. 从第三元素开始，逐渐向后加上一个后续元素，每加一次，并判断确定这一个循环最大的连续子数组和
3. ...
2. 第n个（最后一个）元素即为这个循环最大的元素和
4. 在所以循环的连续子数组和中找出最大的一个
### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int[] singleMax=new int[nums.length];

        for(int i=0;i<nums.length;++i){
            int first=nums[i];
            singleMax[i]=first;
            if(i!=nums.length-1){
                for(int j=i+1;j<nums.length;++j){
                    first+=nums[j];
                    if(first>singleMax[i])
                        singleMax[i]=first;
                }
            }
            else{
                singleMax[i]=first;
            }
        }
        int max=singleMax[0];
        for(int i:singleMax){
            if(i>max)
                max=i;
        }
        return max;
    }
}
```