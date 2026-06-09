### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int count=0,max=Integer.MIN_VALUE,sum=0,number=k;
        while(k<=nums.length){
            count=0;
        for(int i=sum;i<k;i++){
            count+=nums[i];
        }
        if(count>max)
        max=count;
        sum++;
        k++;
        }
        return (double)max/number;
    }
}
```