```
class Solution {
    public int strStr(String haystack, String needle) {
        if(!haystack.contains(needle)){
            return -1;
        }
        if(needle.equals("")) return 0;
        for(int i=0;i<haystack.length();i++){
            if((i+needle.length()-1)<haystack.length()){
                if((haystack.substring(0,needle.length()+i)).contains(needle)){
                    return i;
                }
            }else{
                break;
            }
        }
        return -1;
    }
}
```
如果haystack字符串里面没有needle，则直接返回-1.然后遍历字符串，判断小字符串里是否包含指定字符串，如果包含，则直接返回i值，非常简单的解法，很容易理解。