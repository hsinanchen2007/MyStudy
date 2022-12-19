
执行用时 :2 ms, 在所有 Java 提交中击败了97.50%的用户
内存消耗 :34.8 M, 在所有 Java 提交中击败了93.17%的用户

```
class Solution {
    public boolean detectCapitalUse(String word) {
        /*
        1.首字母大写
         1.1.所有字母大写返回true        
         1.2.其他所有字母都小写返回true
        2.所有字母小写返回true
        */
            char temp =word.charAt(0);
            int count =0;  
            boolean flag = false;
            for(int i=1;i<word.length();i++){
                 if(temp<='z'&&temp>='a'){ //首字母小写
                     if(word.charAt(i)<='Z'&&word.charAt(i)>='A'){
                         return false;
                     }
                
                 }else{ //首字母大写
                    if(word.charAt(i)<='Z'&&word.charAt(i)>='A'){                     
                        if(flag){
                             return false;
                        }
                     }else{
                        flag =true;
                         count++;
                    }
                    
                 }
            }
        if(flag&&count!=word.length()-1){
            return false;
        }
            return true;
    }
}
```


