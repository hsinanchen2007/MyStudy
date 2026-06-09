```
public int lengthOfLastWord(String s) {
        int count = 0;
        int index = s.length() - 1;
        //过滤空格
        while (index >= 0 && s.charAt(index) == ' ') {
            index--;
        }
        //计算最后一个单词的长度
        for (int i = index; i >= 0; i--) {
            if (s.charAt(i) == ' ') {
                break;
            }
            count++;
        }
        return count;
    }
```
