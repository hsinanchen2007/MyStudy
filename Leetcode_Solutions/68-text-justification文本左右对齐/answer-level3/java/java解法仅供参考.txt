```
public List<String> fullJustify(String[] words, int maxWidth) {
    List<String> result = new ArrayList<>();
    int len = words.length;
    int index = 0;
    while(index < len) {
        //记录除第一个字符以外可承接的字符数
        int num = 0;
        //剩余的长度
        int remainder = maxWidth - words[index++].length();
        //判断单词行是否能继续放置除第一个字符以外的字符（需在前面加空格故长度加一）
        while(index < len && 1 + words[index].length() <= remainder) {
            remainder -= 1 + words[index].length();
            num ++;
            index++;
        }
        //放置单词的第一个字符
        StringBuilder builder = new StringBuilder(words[index - num - 1]);
        int n = 0, n1 = 0;
        //判断字符数不为0以及数组内的字符没有遍历完的情况：将剩余的空格数平摊至单词行里
        if(num != 0 && index != len) {
            n = remainder % num;
            n1 = remainder / num;
        }
        for(int i = index - num; i < index; i++) {
            if(n-- > 0) builder.append(" ");
            for(int j = 0; j < n1; j++) builder.append(" ");
            builder.append(" ").append(words[i]);
        }
        //当字符数为0或者数组内的字符已遍历完的情况
        if(num == 0 || index == len) {
            for(int i = 0; i < remainder; i++) builder.append(" ");
        }
        result.add(builder.toString());
    }
    return result;
}
```
