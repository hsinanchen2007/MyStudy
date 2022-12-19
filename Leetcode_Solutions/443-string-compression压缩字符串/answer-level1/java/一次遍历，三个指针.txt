
//write:指示每次写入的位置
//read:每次向右读的位置
//windowLeft:与read之间形成一个窗口，如果这个窗口中的字母都相同，则read不断向右读
```
class Solution {
    public int compress(char[] chars) {
        int write = -1;
        int read = 0;
        int windowLeft = -1; 
        while(read < chars.length){
            if(read + 1 == chars.length || chars[read] != chars[read+1]){
                chars[++write] = chars[read];
                char[] cur = String.valueOf(read - windowLeft).toCharArray();
                if (read - windowLeft > 1){                                   //一个字符时不写入字符个数
                    for(int j = 0; j < cur.length; j++){
                        chars[++write] = cur[j];
                    }
                }
                windowLeft = read;
            }
            read++;
        }
        return write + 1;
    }   
}
```
