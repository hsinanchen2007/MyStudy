查找规律题
既然是将sum加到某个位置，那么该位置一定是数组中的最大值
这样，每一轮寻找数组的最大值max和总和sum 那么数组最大值的位置改变为max-（sum-max)就是上一轮操作的数组
倒着往前操作，直到sum==n&&max==1 返回true 或者 max-(sum-max) 小于等于0 返回false;

```
class Solution {
    public boolean isPossible(int[] target) {
        int n=target.length;
        while(true){
            int index=0;
            long max=0;
            long sum=0;
            for(int i=0;i<target.length;i++){
                if(target[i]<=0) return false;
                sum+=target[i];
                if(target[i]>max){
                    index=i;
                    max=target[i];
                }
            }
            if(sum<0) break;
            if(max==1&&sum==n) return true;
            if(2*max-sum<=0) return false;
            target[index]=(int)(2*max-sum);
        }
        return false;
    }
}
```
