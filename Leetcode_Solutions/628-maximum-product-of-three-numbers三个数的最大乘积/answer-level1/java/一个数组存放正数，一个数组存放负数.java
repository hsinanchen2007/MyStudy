### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maximumProduct(int[] nums) {
        if(nums.length==3)
        return nums[0]*nums[1]*nums[2];
        int []sum=new int[nums.length];
        int x=0,len,y=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]>0)
            sum[x++]=nums[i];
        }
        int []fum=new int[nums.length-x];
        for(int i=0;i<nums.length;i++){
            if(nums[i]<=0)
            fum[y++]=nums[i];
        }
        Arrays.sort(sum);Arrays.sort(fum);
        if(x>=3&&y<2){
            len=sum.length-1;
        return sum[len]*sum[len-1]*sum[len-2];
        }
        else if(x>=3&&y>=2){
        len=sum.length-1;
        return sum[len]*sum[len-1]*sum[len-2]>sum[len]*fum[0]*fum[1]?sum[len]*sum[len-1]*sum[len-2]:sum[len]*fum[0]*fum[1];
        }
        else if(x==2&&y<2){
             len=sum.length-1;
        return sum[len]*fum[fum.length-2]*fum[fum.length-1];
        }
        else if(x==2&&y>=2){
          len=sum.length-1;
        return sum[len]*fum[fum.length-2]*fum[fum.length-1]>sum[len]*fum[0]*fum[1]?sum[len]*fum[fum.length-2]*fum[fum.length-1]:sum[len]*fum[0]*fum[1];  
        }
        else if(x==1){
            len=sum.length-1;
        return sum[len]*fum[0]*fum[1];
        }
        else if(x==0){
            len=fum.length-1;
            return fum[len]*fum[len-1]*fum[len-2];
        }
        return 0;
    }
}
```