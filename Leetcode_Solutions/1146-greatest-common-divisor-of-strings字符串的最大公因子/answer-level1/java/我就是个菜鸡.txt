
今天也是仰望大佬的一天

纪念一下第一次思路通畅的解决题目(快落)
```
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int len1=str1.length(),len2=str2.length(),tar=0;
        if(len2>len1) return gcdOfStrings(str2,str1);
        if(!str2.equals(str1.substring(0,len2))) return "";
        for(int i=len2;i>0;i--)
            if(len1%i == 0 && len2%i == 0){tar=i;break;}
        String temp = str1.substring(0,tar);
        for(int j=len2;j<len1;j=j+tar){
            if(!temp.equals(str1.substring(j,j+tar)))return "";
        }
        return temp;
    }
}
```
