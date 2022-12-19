   假定一个为0的数组，将字符串每个字符在数组对应的位置标记为1，如果一个字符标记时这个位置已经是1，说明存在重复字符，否则不重复

```
class Solution {
    public boolean isUnique(String astr) {
        int[] temp = new int[256];
        for(int i=0;i<astr.length();i++){
            char s = astr.charAt(i);
            if(temp[s] == 1){
                return false;
            }
            temp[s] = 1;
        }
        return true;
    }
}
```



