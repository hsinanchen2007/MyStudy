### 解题思路
1.只需要比较当前最后面一个字母即可；
2.全部通过后再加一个字母，不通过即刻终止

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length==0){return "";}
        if(strs.length==1){return strs[0];}
        for(int i = 0;i<strs[0].length();i++){
            char b = strs[0].charAt(i);
            for(int j = 1;j<strs.length;j++){
                if(strs[j].length()<i+1){return strs[0].substring(0,i);}
                if(b!=strs[j].charAt(i)){return strs[0].substring(0,i);}
            }
        }
        return strs[0];
    }
}
```