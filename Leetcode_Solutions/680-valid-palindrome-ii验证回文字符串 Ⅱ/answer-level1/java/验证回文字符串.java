### 解题思路
双指针，从两边遍历

### 代码

```java
class Solution {
    private  boolean ishuiwen(String s,int i,int j){
        while(i<j){//判断左右两边是否相等，然后再进行i++和j--
            if(s.charAt(i++)!=s.charAt(j--)){
                  return false;  
            }
        }
        return true;
    }
    public boolean validPalindrome(String s) {
       for(int i=0,j=s.length()-1;i<j;i++,j--){
           if(s.charAt(i)!=s.charAt(j)){
               return ishuiwen(s,i,j-1)||ishuiwen(s,i+1,j);//判断中间不相等的字符减去一个会不会相等，||是或;i是向前挪+1，j是-1
           }
       }
       return true;
    }

}
```