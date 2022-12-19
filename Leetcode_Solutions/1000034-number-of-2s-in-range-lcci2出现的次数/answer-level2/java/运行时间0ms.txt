### 解题思路
找出规律,然后不断减小数字,比如n为1200,规律中0-1000是100+10*20个2,所以count加上这个数字,然后将n变为200,继续下去,直到n为个位数为止

### 代码

```java
class Solution {
    public int numberOf2sInRange(int n) {
        //0-10 1
        //0-100 10+10*1
        //0-1000 100+10*20
        //0-10000 1000+10*300
        if(n<2)return 0;
        int len = 0;
        int t=n;
        while(t>0){
            t/=10;len++;
        }
        if(len==1)return 1;
        int[] nums = new int[11];
        nums[0]=0;nums[1]=1;
        for(int i=2;i<=10;i++)nums[i]=nums[i-1]*10;
        t=n;
        int k;
        int count=0;
        while(t>1){
            if(len==1){
                if(t>1)
                    count=count+1;
                break;
            }
            k=t/nums[len];
            if (k==2) {
                count = count+t%nums[len]+1;
                count = count+(nums[len-1]+10*(len-2)*nums[len-2])*2;
            } else if(k<2) {
                count = count+nums[len-1]+10*(len-2)*nums[len-2];
            } else {
                count = count + nums[len]+(nums[len-1]+10*(len-2)*nums[len-2])*k;
            }
            t=t%nums[len];
            int c = t;len=0;
            while(c>0){
                c/=10;len++;
            }   
        }
        return count;
    }
}
```