### 解题思路
此处撰写解题思路
使用for遍历s1,s2 暴力解决
### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        boolean allfound = true;
        if(s1.length()!=s2.length()) return false;
        for(int i=0;i<s1.length();i++){
            boolean found = false;
            for(int j=0;j<s2.length();j++){
                if(s1.charAt(i)==s2.charAt(j)){
                    s2 = s2.substring(0,j)+s2.substring(j+1); 
                    found = true;
                    break;                 
                }   
            }
            if(found){
                continue;
            }else{
                allfound = false;
                break;
            }     
        }
        return allfound;

    }
}
```