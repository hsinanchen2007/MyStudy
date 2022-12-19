用sum记录当前最大连续K数组的和，用temp记录当前连续K数组的和，逐个比较就OK了。<br>
注意当前K个连续元素和如此计算：temp = temp+nums[i+k-1]-nums[i-1];<br>
比如 [1,2,3,4,5,6] k=4<br>
temp1 = 1+2+3+4<br>
temp2 = temp1+5-1<br>

```
class Solution {
    //连续子数组  
    public double findMaxAverage(int[] nums, int k) {
        int sum = 0;
        for(int i=0;i<k;++i){
            sum+=nums[i];
        }
        
        //记录第一个i  和  i+k   sum+nums[i+k-1]-nums[i-1];
        int temp=sum;
        for(int i=1;i+k-1<nums.length;++i){
            temp = temp+nums[i+k-1]-nums[i-1];
            if(temp>sum) sum = temp;
        }
        
        return sum/(double)k;
    }
}
```
