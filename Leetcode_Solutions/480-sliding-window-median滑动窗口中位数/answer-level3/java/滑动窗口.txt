### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        double []sum=new double[k];
        double []num=new double[nums.length-k+1];
        int x=0,y=0;
        for(int i=0;i<nums.length-k+1;i++){
            x=0;
            for(int j=i;j<i+k;j++){
               sum[x++]=nums[j];
            }
            Arrays.sort(sum);
            if(sum.length%2==1)
            num[y++]=sum[k/2];
            else{
                num[y++]=(sum[k/2-1]+sum[k/2])/2;
            }
        }
        return num;
    }
}
```