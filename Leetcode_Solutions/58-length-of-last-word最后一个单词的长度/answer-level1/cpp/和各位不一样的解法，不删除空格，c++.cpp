
方法1：
从头遍历，遇到空格则存储刚结束的单词的长度，若遇到新单词则重新开始算长度，否则返回存储的单词长度

```

int lengthOfLastWord(string s){
        int length    = 0;     // 当前单词长度
        int preLength = 0;     // 上一个单词长度
        bool isBlank  = false; // 用于记录前一个字符是否为空格
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' ' && isBlank == false ){
                isBlank   = true;
                preLength = length;
                length    = 0;
            }else if( s[i] != ' ' ){
                isBlank = false;
                length++;
            }
        }
        // 若结尾是空格，返回preLength， 若不是空格，返回length
        if( isBlank ){
            return preLength;
        }else{
            return length;
        }
    }

```

更简单的方法2：

从字符串最后开始遍历，计算完第一个单词后遇到空格返回单词长度

耗费 0 ms ， 打败100%

```
    // 方法2：从后遍历
    int lengthOfLastWord(string s){
        int length  = 0;      // 当前单词长度
        bool isWord = false;  // 是否遇到了单词

        for(int i = s.length() - 1; i >= 0; i--){
            if( s[i] != ' ' ){
                isWord = true;
                length++;
            }else if( s[i] == ' '  && isWord ){
                return length;
            }
        }
        return length;
    }
```


