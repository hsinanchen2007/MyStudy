```
class Solution {
    public char firstUniqChar(String s) {
        int[] dic = new int[128];
        char[] chars = s.toCharArray();
        for(int i=0;i<chars.length;i++){
            dic[chars[i]]++;
        }
        for(int i=0;i<chars.length;i++){
            if(dic[chars[i]]==1)
                return chars[i];
        }
        return ' ';
    }
}
```
