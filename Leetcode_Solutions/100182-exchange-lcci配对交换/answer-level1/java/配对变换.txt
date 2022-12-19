### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int exchangeBits(int num) {
        String len="",len1="",sum="",sum1="";
        double count=0;
       while(num>0){
           len+=num%2;
           num/=2;
       }
       if(len.length()%2==1)
       len+="0";
       for(int i=len.length()-1;i>=0;i--){
           len1+=len.charAt(i);
       }
       int i=len1.length()-1;
       while(i>=1){
           sum+=len1.charAt(i-1);
           sum+=len1.charAt(i);
           i-=2;
       }
       for(int j=sum.length()-1;j>=0;j--){
           sum1+=sum.charAt(j);
       }
       for(int j=sum1.length()-1;j>=0;j--){
           if(sum1.charAt(j)=='1')
           count+=Math.pow(2,sum1.length()-j-1);
       }
       System.out.println(count);
       return (int)count;
    }
}
```