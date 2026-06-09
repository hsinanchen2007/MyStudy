### 解题思路
这个没有什么算法可言，看个人对业务逻辑的理解。
解题的关键在于你如何控制每一行的字符长度。
有人从右到左控制，我是从左到右去控制的。
我是每次加下一个字符长度，如果同一行字符总长度+字符间距 > 最大值宽度，那么就生成一行字符串。如果有最后一行还要特殊处理。
详情见代码。

### 代码

```java
class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> result = new ArrayList<>();
        List<String> wordInSameLine = new ArrayList<>();
        int wordTotalLenInSameLen = 0;
        for(String word : words){
            wordTotalLenInSameLen += word.length();
            if(wordTotalLenInSameLen + wordInSameLine.size() > maxWidth){
                int rest = maxWidth - wordTotalLenInSameLen + word.length();
                int align = wordInSameLine.size() - 1 == 0?rest:rest / (wordInSameLine.size() - 1);
                int alignLeft = wordInSameLine.size() - 1 == 0?0:rest % (wordInSameLine.size() - 1);
                StringBuilder stringBuilder = new StringBuilder();
                for(String w : wordInSameLine){
                    stringBuilder.append(w);
                    if(stringBuilder.length() < maxWidth){
                        for (int i = 0; i < align; i++) {
                            stringBuilder.append(" ");
                        }
                        if(alignLeft > 0){
                            stringBuilder.append(" ");
                            alignLeft--;
                        }
                    }
                }
                result.add(stringBuilder.toString());
                wordInSameLine.clear();
                wordInSameLine.add(word);
                wordTotalLenInSameLen = word.length();
            } else {
                wordInSameLine.add(word);
            }
        }
        if(wordInSameLine.size() > 0){
            int rest = maxWidth - wordTotalLenInSameLen - wordInSameLine.size();
            StringBuilder stringBuilder = new StringBuilder();
            for(String word : wordInSameLine){
                stringBuilder.append(word);
                if(stringBuilder.length() < maxWidth){
                    stringBuilder.append(" ");
                }
            }
            for (int i = 0; i < rest; i++) {
                stringBuilder.append(" ");
            }
            result.add(stringBuilder.toString());
        }
        return result;
    }
}
```