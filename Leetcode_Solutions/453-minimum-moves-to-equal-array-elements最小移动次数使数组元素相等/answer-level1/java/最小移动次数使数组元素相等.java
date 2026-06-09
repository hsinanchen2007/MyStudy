### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minMoves(int[] nums) {
        //有n-1个元素加一，则说明每次可以由1个元素减一
        int min=Integer.MAX_VALUE;
        for(int n:nums)
        {
            if(n<min)
                min=n;
        }
        int sum=0;
        for(int n:nums)
        {
            sum+=(n-min);
        }
        return sum;
    }
}
```