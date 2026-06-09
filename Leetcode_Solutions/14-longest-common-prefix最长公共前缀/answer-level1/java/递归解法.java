### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length==0) return "";
        return re(strs,0,strs.length-1);
    }

    public String  re (String[] strs,int l,int r){
        if(l==r) return  strs[l];
        String  ret = re(strs,l+1,r);
        int path =0;
        while (path<ret.length()&&path<strs[l].length()){
            if(ret.charAt(path)!=strs[l].charAt(path)) break;
            path++;
        }
        return  ret.substring(0,path);
    }
}
```