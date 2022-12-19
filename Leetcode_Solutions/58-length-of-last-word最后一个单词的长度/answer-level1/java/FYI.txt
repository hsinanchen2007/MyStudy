```
class Solution {
    public int lengthOfLastWord(String s) {
        int len = 0;
        boolean flag = false;
        for (int i = 0; i< s.length(); i++){
            if(s.charAt(i) != ' ') {
                if (flag) {
                    len = 0;
                    flag = false;
                }
                len++;
            }
            else {
                flag = true;
            }
        }
        return len;
    }
}
```
设个标志位，有空格就重新计数