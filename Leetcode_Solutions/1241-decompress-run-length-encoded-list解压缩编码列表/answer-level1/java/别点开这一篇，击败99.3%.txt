### 解题思路
理解了题目就好做了

一个数组相隔的元素两两一组，第一个是次数，第二个是具体的数（题目有具体讲解）。

我们要确定的是返回的数组有多大，有些语言可以动态修改数组，就没这个问题了。

### 代码

```java

class Solution {
    public int[] decompressRLElist(int[] nums) {
        int len = 0;

        for(int i = 0; i < nums.length; i += 2)
            len += nums[i];

        int[] ans =  new int[len];

        for(int j = 1, index = 0; j < nums.length; j += 2){
                for(int k = nums[j - 1]; k > 0; k--, index++){
                    ans[index] = nums[j];
                }
        }

        return ans;
    }
}
```