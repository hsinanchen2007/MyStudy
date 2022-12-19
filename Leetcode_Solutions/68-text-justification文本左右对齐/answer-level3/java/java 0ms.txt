```
class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        // 先找到每行单次的位置
        int index = 0;
        int size = words.length;
        List<String> res = new ArrayList<>();
        while(index < size) {
            // 每行单词
            StringBuilder sb = new StringBuilder();
            // 起始单词肯定在里面
            int curLen = words[index].length();
            int last = index + 1;
            // 找到每行单词的末尾
            while(last < size) {
                if(curLen + 1 + words[last].length() > maxWidth) break;
                curLen = curLen +  1 + words[last].length();
                last++;
            }
            // 每行有多少的间隔
            int gaps = last - index - 1;
            int remainLen = maxWidth - curLen;
            int space = gaps == 0 ? gaps : remainLen / gaps;
            //System.out.println(space);
            int rest = gaps == 0 ? gaps : remainLen % gaps;
            //System.out.println(rest);
            // 如果是最后一个单词或者一行中只有一个单词的时候，空格放到最右边
            if(last == size || gaps == 0) {
                for(int i = index; i < last; i++) {
                    sb.append(words[i]).append(" ");
                }
                sb.deleteCharAt(sb.length() - 1);
                while(sb.length() < maxWidth) {
                    sb.append(" ");
                }
            }else{ //中间的行
                for(int i = index; i <= last-2; i++) {
                    sb.append(words[i]);
                    for(int j = 0; j < space + 1; j++) {
                        sb.append(" ");
                    }
                    // 均摊空格
                    if(i - index < rest) {
                        sb.append(" ");
                    }
                }
                sb.append(words[last - 1]);
            }
            res.add(sb.toString());
            index = last;
        }
        return res;
    }
}
```
