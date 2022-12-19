1.计算包含单词的个数
2.计算空格的个数，并和单词组合
3.在最后一行，单独处理
Talk is cheap,so please see the code.
```
class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> res = new ArrayList<>();
        int i = 0;
        int wordCnt = 0;// 记录字符串的长度，以判断是否越界
        int len = 0; //记录下一个字符串中包含单词的数量
        int start = 0; //记录下一个字符串的开始位置(在words中的下标)
        while (i < words.length) {
            wordCnt += words[i].length(); //加上当前的单词长度
            if (wordCnt <= maxWidth) { //可以带上这个单词
                i++;
                len++;
                wordCnt++; //每个不是最后一个单词后要算一个空格
            } else {
                if (i == words.length) {//如果是最后一个单词
                    res.add(addLastString(words, start, len, maxWidth));//最后一行特殊处理
                } else {
                    res.add(addString(words, start, len, maxWidth));//用从start开始，共len个单词进行进行拼接
                }
                len = 0; //重置各个变量，进行下一个字符串的计算
                wordCnt = 0;
                start = i;
            }
        }
        if (len != 0)   //如果还有单词没有加入，就把剩下单词放入最后一行
            res.add(addLastString(words, start, len, maxWidth));
        return res;
    }

    //计算最后一行
    private String addLastString(String[] words, int start, int len, int maxWidth) {
        StringBuilder sb = new StringBuilder();
        int spaceCnt = maxWidth;
        //计算除每个单词后那个空格的剩余空格数
        for (int i = 0; i < len; i++) {
            spaceCnt -= (words[start + i].length() + 1);
        }
        if(spaceCnt>=0){
            for (int i = 0; i < len; i++) {
                sb.append(words[start + i] + " ");
            }
            sb.append(nSpace(spaceCnt));
        }
        // <0这种情况即最后一个单词是没有空格的
        else{
            for (int i = 0; i < len-1; i++) {
                sb.append(words[start + i] + " ");
            }
            sb.append(words[start + len-1]);
        }

        return sb.toString();
    }

    //计算除最后一行的其余行
    private String addString(String[] words, int start, int len, int maxWidth) {
        StringBuilder sb = new StringBuilder();
        int spaceCnt = maxWidth;
        // 计算空格数（包括单词后面的空格）
        for (int i = 0; i < len; i++) {
            spaceCnt -= words[start + i].length();
        }
        if (len > 1) {
            for (int i = 0; i < len; i++) {
                sb.append(words[start + i]);
                int numSpace = (int) Math.ceil(1.0 * spaceCnt / (len - 1 - i));//因为左空格>=右空格所以上取整
                sb.append(nSpace(numSpace));
                spaceCnt -= numSpace;
            }
        // len==1的情况下计算，用上面的方法计算空格会/0,所以单独计算
        } else {
            sb.append(words[start]);
            sb.append(nSpace(spaceCnt));
        }
        return sb.toString();
    }

    //返回n个空格的字符串
    private String nSpace(int numSpace) {
        String res = "";
        for (int i = 0; i < numSpace; i++) {
            res += " ";
        }
        return res;
    }
}
```
