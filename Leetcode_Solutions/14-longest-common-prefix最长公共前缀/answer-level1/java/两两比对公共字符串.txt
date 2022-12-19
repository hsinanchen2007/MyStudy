### 解题思路
1.首先将边界条件和判断的前提给写了，在本题中，数组为空、数组长度为0，元素的值为空或者元素的值是""都是判断之前的边界条件
2.核心的地方在于数组中所有字符串都不为空的情况的下进行求公共前缀
3.我的做法很粗暴，将字符串的字符进行两两比较，直到出现一个不一样的时候停止
4.因为所有的字符串公共前缀一定小于两个字符串的公共前缀，所以可以将比较的结果和后续的字符串进行比对

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs == null){
            return null;
        }else if(strs.length == 0){
            return "";
        }else if(strs.length == 1){
            return strs[0];
        }else{
            String commonPrefix = strs[0];
            if(commonPrefix == null || commonPrefix.equals("")){
                return commonPrefix;
            }
            for(int i = 1;i < strs.length;i++){
                if(strs[i] == null || strs.equals("")){
                    return strs[i];
                }else{
                    int scanLength = strs[i].length() > commonPrefix.length() ? commonPrefix.length() : strs[i].length();
                    int k = 0;
                    for(;k < scanLength;k++){
                        if(strs[i].charAt(k) != commonPrefix.charAt(k)){
                            break;
                        }
                    }
                    commonPrefix = commonPrefix.substring(0,k);
                }
            }
            return commonPrefix;
        }
    }
}
```