```
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] day = new int[T.length];
        for(int i=0;i<T.length;i++)
        {
            int j=i+1;
            while(j<T.length && T[i]>=T[j])
            {
                j++;
            }
            if(j!=T.length)
            {
                day[i]=j-i;
            }
            else{
                day[i]=0;
            }

        }
        return day;
    }
}
```
