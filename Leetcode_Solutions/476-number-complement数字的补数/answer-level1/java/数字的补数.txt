### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findComplement(int num) {
        String sum="",fum="";
        int count=0,btu=0,len=0;
        while(num>0){
         sum+=num%2;
         num/=2;
        }
        for(int i=sum.length()-1;i>=0;i--){
            fum+=sum.charAt(i);
        }
        for(int i=0;i<fum.length();i++){
            if(fum.charAt(i)=='1')
            btu=0;
            else btu=1;
            len=fum.length()-i-1;
            if(btu==1)
            count+=Math.pow(2,len);
        }
        return count;
    }
}
```