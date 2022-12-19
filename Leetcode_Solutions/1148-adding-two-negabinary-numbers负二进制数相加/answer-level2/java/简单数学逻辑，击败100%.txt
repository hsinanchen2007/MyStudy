从最后一位开始相加，若1+1进位，则当前位置0，前一位-1；若当前位小于0，则在小于等于-2的情况下，当前位每-2，前面一位对应+1。以此规则遍历。最后记录数组里第一次出现1的位置，最后返回数组。
```
class Solution {
    public int[] addNegabinary(int[] arr1, int[] arr2) {
        if(arr1[0]==0) return arr2;
        if(arr2[0]==0) return arr1;
        int len1=arr1.length;
        int len2=arr2.length;
        int len=Math.max(len1,len2)+2;
        int[] ans=new int[len];
        int cur=len;
        int temp=len-1;
        while(len1>=1||len2>=1||cur>=1){
            if(len1>=1){
                ans[cur-1]+=arr1[len1-1];
                len1--;
            }
            if(len2>=1){
                ans[cur-1]+=arr2[len2-1];
                len2--;
            } 
            while(ans[cur-1]<0){
                ans[cur-1]=ans[cur-1]+2;
                ans[cur-2]++;
            }
            while(ans[cur-1]>1){
                ans[cur-1]-=2;
                ans[cur-2]--;
            }
            cur--;
        }
        for(int i=0;i<len;i++){
            if(ans[i]==1){
                temp=i;
                break;
            }
        }
        int[] res=new int[len-temp];
        for(int i=0,j=temp;j<len;j++,i++){
            res[i]=ans[j];
        }
        return res;
    }
}
```
