从后向前，找到的第一个单词的长度
```
    class Solution {
    public int lengthOfLastWord(String s){
            int last = 0;
            for(int i = s.length()-1; i >= 0; i--){
                if(s.charAt(i) == ' ' && last != 0)
                    break;
                else if(s.charAt(i) != ' ')
                    last++;
            }
            return last;
        } 
    }
```



 从前向后找，记录每个空格分隔的字母个数，返回最后一个不为零的字母个数 
```  
    class Solution {
        public int lengthOfLastWord(String s) {
            int last = 0;
            int tmp = 0;
            for(int i = 0; i < s.length(); i++){
                if(s.charAt(i) == ' '){
                    last = (tmp == 0 ? last : tmp); 
                    tmp = 0;
                }
                else
                    tmp++;
            }
            
            last = (tmp == 0 ? last : tmp);
            return last;
        }
    }
```    

