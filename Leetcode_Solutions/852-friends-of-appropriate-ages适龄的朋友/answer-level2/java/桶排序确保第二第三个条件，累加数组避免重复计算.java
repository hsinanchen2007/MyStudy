```
class Solution {
    public int numFriendRequests(int[] ages) {
        int[] bucket=new int[121];
        for (int i=0;i<ages.length;i++){
            bucket[ages[i]]++;
        }
        int[] sum=new int[121];
        for (int i=1;i<121;i++){
            sum[i]=sum[i-1]+bucket[i];
        }
        int ans=0;
        for (int i=1;i<121;i++){
            if (i>14&&bucket[i]>0){
                ans+=bucket[i]*(bucket[i]-1);
                int t=i/2+7;
                if (i>t){
                    int n1=sum[i-1]-sum[t];
                    ans+=bucket[i]*n1;
                }
            }
        }
        return ans;
    }
}
```
