### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String convertToBase7(int num) {
        int []sum=new int[10];
        int x=0;
        String len="";
        if(num<0){
        num=-num;
        len+="-";
        }
        else if(num==0)
        return "0";
        while(num>0){
            sum[x++]=num%7;
            num/=7;
        }
        for(int i=x-1;i>=0;i--){
            len+=""+sum[i];
        }
        return len;
    }
}
```