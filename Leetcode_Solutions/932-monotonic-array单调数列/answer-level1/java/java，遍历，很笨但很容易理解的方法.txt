### 解题思路
问题在于不知道是递增还是递减的，那这样好了，一直遍历，记录每一个数与后者的差值，标记数cnt，如果增则cnt+1，若减则cnt-1；
那么如果满足单调序列cnt的绝对值是递增的，如果出了问题那一定不是递增数列

### 代码

```java
class Solution 
{
    public boolean isMonotonic(int[] A)
    {
        if(A.length<3)
            return true;
        int cnt  =  0;
        for(int i=0;i<A.length-1;i++)
        {
            int cnt_temp=cnt;
            int temp = A[i+1]-A[i];
            if (temp==0)
                continue;
            if(temp>0)
            {
                cnt++;
                if(Math.abs(cnt_temp)-Math.abs(cnt)>0)
                    return false;
            }
            else if(temp<0)
            {
                cnt--;
                if(Math.abs(cnt_temp)-Math.abs(cnt)>0)
                    return false;
            }
        }
        return true;
    }
}
            
        
```