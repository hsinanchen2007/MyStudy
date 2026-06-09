### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int sumOfDigits(int[] A) {
        //注意：找最小值并不需要排序
        int min=Integer.MAX_VALUE;
        for(int i=0;i<A.length;i++)
            min=Math.min(min,A[i]);
        int sum=0;
        while(min>0){
            sum+=min%10;
            min=min/10;
        }
        return sum%2==0? 1:0;
    }
}
```