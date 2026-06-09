### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String breakPalindrome(String palindrome) {
        if(palindrome.length()==1)return "";
        int flag=0,count=0;
        char[] sum=palindrome.toCharArray();
        for(int i=0;i<palindrome.length()/2;i++){
            if(sum[i]!='a'){
            sum[i]='a';
            flag=1;
            break;
            }
        }
        if(flag==1)return new String(sum);
        else{
            sum[sum.length-1]='b';
        return new String(sum); 
        }
    }
}
```