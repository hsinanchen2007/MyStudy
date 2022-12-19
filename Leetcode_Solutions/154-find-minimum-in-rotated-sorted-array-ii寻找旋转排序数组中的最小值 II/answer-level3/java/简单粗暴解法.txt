### 解题思路
简单粗暴，从头开始查找，如果遇到nums[i]>nums[i+1]就返回nums[i+1].
两个小细节：
1）假如初始数组就是递增排列的，就不会找到合适的i了，这时就通过判断a的值，来确定返回nums[0];
2）a的初始值设为-1，是针对[3,1]这个例子，if的结果是a=i=0,这时就不好判断是nums[0]还是nums[0+1]。

### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        int a=-1;
        for(int i=0; i<nums.length-1; i++){
            if(nums[i]>nums[i+1])
            {
                a=i;
                break;
            }
            //else
               //continue;
        }
        if(a>=0)
           return nums[a+1];
        else 
            return nums[0];
    }
}
```