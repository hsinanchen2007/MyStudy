### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maximumSwap(int num) {
        int k=(num+"").length();
        int x=k-1,t,count=0,number=0,h=k-1,f=0,flag=0;
        int []sum=new int[k];
        for(int i=0;i<k;i++){
        sum[x--]=num%10;
        num/=10;
        }
        int []fum=new int[k];
        for(int i=0;i<k;i++)
        fum[i]=sum[i];
        Arrays.sort(fum);
        for(int i=0;i<k;i++){
           if(sum[i]!=fum[h--]){
               number=fum[h+1];
               f=i;
               flag=1;
               break;
           }
        }
        if(flag==1)
        for(int i=k-1;i>=f;i--){
            if(sum[i]==number){
                t=sum[i];
                sum[i]=sum[f];
                sum[f]=t;
                break;
            }
        }
        for(int i=0;i<k;i++){
            count*=10; 
            count+=sum[i];
        }
        return count;
    }
}
```