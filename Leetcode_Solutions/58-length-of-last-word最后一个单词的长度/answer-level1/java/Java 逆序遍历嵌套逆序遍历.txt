```
class Solution {
    public int lengthOfLastWord(String s) {
        for(int i = s.length()-1; i >= 0; i--){//逆序第一个非空格字符索引为单词结束
            if(s.charAt(i) != ' '){
                for(int j = i; j >= 0; j--){   //从第一个非空格字符继续逆序遍历
                    if(s.charAt(j) ==' ') return i-j; //前有空格得到单词起始
                    if(j == 0) return i-j+1;     //字符串开头仍然非空格得到单词起始
                }                
            }
        }
        return 0; //其余情况 null、""、" "、"   "等，均返回0
    }
}
```
终于有一题不用被各路大神的题解吊打了，第一次写题解好激动。