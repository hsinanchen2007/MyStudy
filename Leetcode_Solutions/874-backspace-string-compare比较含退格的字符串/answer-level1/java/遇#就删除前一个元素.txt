### 解题思路


### 代码

```java
class Solution {
    public boolean backspaceCompare(String S, String T) {
        String number="";
        String count="";
        int flag=0,sum=0;
        for(int i=0;i<S.length();i++){
            if(S.charAt(i)!='#')
            number+=S.charAt(i);
            else if(S.charAt(i)=='#'&&i!=0&&number.length()>=1){
             number = number.substring(0, number.length()-1);
            }
        }
         for(int i=0;i<T.length();i++){
            if(T.charAt(i)!='#')
            count+=T.charAt(i);
             else if(T.charAt(i)=='#'&&i!=0&&count.length()>=1){
             count = count.substring(0, count.length()-1);
            }
        }
         if(count.length()!=number.length())
         return false;
         else if(count.length()==0&&number.length()==0)
         return true;
         else sum=number.length();
        for(int i=0;i<sum;i++){
            if(count.charAt(i)!=number.charAt(i)){
                flag=1;
                break;
            }
        }
        for(int i=0;i<count.length();i++){
            System.out.println(count.charAt(i));
        }
        if(flag==0)
        return true;
        else return false;
    }
}
```