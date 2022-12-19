### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Arrays.sort(arr);
        int len=0;
        int []num=new int[arr[arr.length-1]+1];
        if(arr[0]>0)
        len=arr[0];
        else len=-arr[0];
        int []sum=new int[len+1];
        int []fum=new int[arr[arr.length-1]+len+2];
        int x=0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]>=0)
            num[arr[i]]++;
            else sum[-arr[i]]++;
        }
        for(int i=0;i<num.length;i++){
            fum[x++]=num[i];
        }
        for(int i=0;i<sum.length;i++){
            fum[x++]=sum[i];
        }
        Arrays.sort(fum);
        for(int i=0;i<fum.length-1;i++){
            if(fum[i]==fum[i+1]&&fum[i]!=0&&fum[i+1]!=0)
            return false;
        }
        return true;
    }
}
```