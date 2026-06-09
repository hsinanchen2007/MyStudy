### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        if(arr.length==0)
        return 0;
        int count=0,len=0,sum=0,number=k;
        while(k<=arr.length){
            count=0;
        for(int i=sum;i<k;i++)
        count+=arr[i];
        if(count/number>=threshold)
        len++;
        k++;
        sum++;
        }
        return len;
    }
}