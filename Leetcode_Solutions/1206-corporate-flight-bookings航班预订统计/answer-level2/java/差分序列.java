### 解题思路
差分序列
### 代码

```java
class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int dif[] = new int[n];
        int src[] = new int[n];
        for(int i=0;i<n;i++){
            dif[i]=0;
            src[i]=0;
        }
        
        for(int i=0;i<bookings.length;i++)
        {
            int start = bookings[i][0];
            int end = bookings[i][1];
            int k = bookings[i][2];
            //
            int start_cur = start-1;
            int end_cur = end;
            dif[start_cur]+=k;
            if(end_cur<n)
                dif[end_cur]-=k;
        }
        src[0]=dif[0];    
        for(int i=1;i<n;i++)
           src[i] = src[i-1]+dif[i];
                
        return src;
                
                
                
                
    }
}
```