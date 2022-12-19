### 解题思路
![image.png](https://pic.leetcode-cn.com/6b106c509311621e30aa0205e4764f43c7d8c63579e1eb735deaf62b66c1fda5-image.png)
思路还是统计每个数值达到要求的移动区间，求交叉区间最大值对应的移动次数

这里有一个技巧就是，存储区间的技巧，没必要对区间内每一个值进行计数
比如区间[1,3]，存储时可以存为nums[1]=1,nums[4]=**-1**,这样最后计算时计算前缀和就可以得到当前的总数
这样可以省很多时间
### 代码

```java
class Solution {
    public int bestRotation(int[] A) {
        int len = A.length;
        
        int[] nums = new int[len];
        
        for(int i=0 ; i<len ; i++){
            if(A[i]<=i){
                int start = 0;
                int end = i-A[i];
                nums[start] += 1;
                if(end<len-1){
                    nums[end1+1] -= 1;
                    if(i<len-1){
                        nums[i+1] += 1;
                    }
                }   
            } else{
                int start = i+1;
                int end = len-1-A[i] + start;
                nums[start] += 1;
                if(end<len-1){
                    nums[end+1] -= 1;
                }
            }
        }
        int max = 0;
        int res = 0;
        int sum = 0;
        for(int i=0 ; i<len ; i++){
            sum += nums[i];
            if(sum>max){
                max = sum;
                res = i;
            }
        }
        return res;
    }
}
```