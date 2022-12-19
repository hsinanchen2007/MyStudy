```
public String reverseWords(String s) {
        // 切割字符串
        String[] words = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for (int i = words.length - 1; i >= 0; i--) {
            // 有连续" "存在时，words里存在空字符串，跳过
            if (words[i].length() == 0) continue;
            // 拼接
            sb.append(words[i]);
            sb.append(" ");
        }
        // 去除尾部多余" "
        if(sb.length()>0) return sb.toString().substring(0, sb.length()-1);
        else return sb.toString();
    }
```
