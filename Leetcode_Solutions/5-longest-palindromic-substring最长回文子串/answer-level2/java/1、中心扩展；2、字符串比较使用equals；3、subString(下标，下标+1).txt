### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   String maxStr ="";


    public String longestPalindrome(String s) {

        if(s.equals("") || s == null){
            return "";
        }
        String[] split = s.split("");
        for(int i=0;i<split.length;i++){
            centerExtendStr(s,split,i,i);
            centerExtendStr(s,split,i,i+1);
        }
        return maxStr;

    }

    private void centerExtendStr(String str,String[] strs,int i,int j){
        int length = strs.length;
        while(i>=0 && j < length ){
            if(strs[i].equals(strs[j])){
                if(maxStr.length() <= (j -i)){
                    maxStr = str.substring(i,j+1);
                }
                i--;
                j++;
            }else{
                break;
            }
        }
    }
}
```