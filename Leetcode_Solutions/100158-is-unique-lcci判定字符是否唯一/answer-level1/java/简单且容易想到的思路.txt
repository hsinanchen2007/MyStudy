###
最容易想到的思路，暴力双指针

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
      if(astr==null){
            return false;
        }else if(astr.length()==1){
            return true;
        }else {
            //双指针
            for (int i = 0; i <astr.length()-1 ; i++) {
                for (int j = i+1; j <astr.length(); j++) {
                    if(astr.charAt(i)==astr.charAt(j)){
                        return false;
                    }
                }
            }
            return true;
        }
    
    }
}
```