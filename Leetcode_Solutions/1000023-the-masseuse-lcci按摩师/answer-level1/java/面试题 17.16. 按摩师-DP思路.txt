### 解题思路
设请求序列为[A1,A2,A3...]
目标是找到最优时长，限制是两个预约不能相邻。
设f(x)为以x为最后下标的总预约时长，f(p)为以p为下标的总预约时长,x-p>1

**max{f(x)}=max{f(p)}+Ax,x-p>1**

f(1)=A1;
f(2)=max{A1,A2};
f(3)=max{f(3-2)}+A3=max{f(1)}+A3;
f(4)=max{f(4-3),f(4-2)}+A4=max{f(1),f(2)}+A4;
...
以此类推,所有f(x)中，最大值为最优时长

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        int length=nums.length;
        if(nums.length<1){
            return 0;
        }else if(nums.length==1){
            return nums[0];
        }else if(nums.length==2){
            return getMax(nums[0],nums[1]);
        }
        int[] f=new int[length];
        f[0]=nums[0];
        f[1]=getMax(nums[0],nums[1]);
        for(int i=2;i<length;i++){
            f[i]=getMax(f,i-1)+nums[i];
        }
        return getMax(f);
    }

    public int getMax(int[] nums,int length){
        int max=nums[0];
        for(int i=1;i<length;i++){
            max=getMax(max,nums[i]);
        }
        return max;
    }

    public int getMax(int[] nums){
        int max=nums[0];
        for(int i=1;i<nums.length;i++){
            max=getMax(max,nums[i]);
        }
        return max;
    }

    public int getMax(int a,int b){
        if(a>b){
            return a;
        }else{
            return b;
        }
    }
}
```