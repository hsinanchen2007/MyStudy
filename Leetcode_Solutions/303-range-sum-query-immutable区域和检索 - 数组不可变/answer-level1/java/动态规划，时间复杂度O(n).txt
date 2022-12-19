### 解题思路
在第一次循环的时候，记录从0到上限的和
在求【i，j】的和的时候，只需要将上限的和减去以（i-1）为上限的和，即为所求。
### 代码

```java
class NumArray {
    int[] sum;
    int len;
    public  NumArray(int[] nums) {
        len=nums.length;
        if(len>0){
            sum=new int[len];
            sum[0]=nums[0];
            for(int x=1;x<len;x++){
            sum[x]=sum[x-1]+nums[x];
            }
        }
    }
    public int sumRange(int i, int j) {
        if(i==0){
            return sum[j];
        }else{
            return sum[j]-sum[i-1];
        }
    }
}
```