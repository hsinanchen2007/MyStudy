```
import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> ans = new ArrayList<>();
        int start = 0;
        while (start < words.length) {
            int end = fill(words,start,maxWidth);
            ans.add(stringMaker(words,start,end,maxWidth));
            start = end+1;
        }
        return ans;
    }

    public int fill(String[] words, int start, int maxWidth) {
        //尽量填充最多的单词
        int curLen = 0 ; int i=start;
        for(;i<words.length;i++) {
            curLen+=words[i].length();
            if(curLen>maxWidth) {
                return i-1;
            }
            if(curLen==maxWidth) {
                return i;
            }
            curLen++;
        }
        return i==words.length? words.length-1:i;
    }

    public String stringMaker(String[] words, int start, int end, int maxWidth) {
        StringBuilder ans = new StringBuilder();
        //如果只有一个单词
        if(start==end) {
            ans.append(words[start]);
            for(int i=words[start].length();i<maxWidth;i++) {
                ans.append(' ');
            }
        }
        //如果到了最后一行
        else if(end==words.length-1) {
            for(int i = start;i<=end;i++) {
                ans.append(words[i]);
                ans.append(' ');
            }
            ans.deleteCharAt(ans.length()-1);
            while (ans.length()<maxWidth) {
                ans.append(' ');
            }
        }
        //普通行
        else {
            int sumLen = 0;
            for(int i=start;i<=end;i++) {
                sumLen+=words[i].length();
            }
            int average = (maxWidth-sumLen)/(end-start);
            int adder = (maxWidth-sumLen)%(end-start);
            for(int i=start;i<end;i++) {
                ans.append(words[i]);
                for(int j=0;j<average;j++) {
                    ans.append(' ');
                }
                if(i-start<adder) {
                    ans.append(' ');
                }
            }
            ans.append(words[end]);
        }

        return ans.toString();
    }
}
```
