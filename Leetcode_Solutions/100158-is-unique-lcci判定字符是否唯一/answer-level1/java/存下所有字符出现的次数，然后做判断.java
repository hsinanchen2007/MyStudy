常见的字符有128个就设数组长度128了
这个也是双100precent
```
class Solution {
    public boolean isUnique(String astr) {
        int[] count = new int[128];
        for(char var : astr.toCharArray()){
            count[var]++;
        }
        for(int var : count){
            if(var > 1) return false;
        }
        return true;
    }
}
```
