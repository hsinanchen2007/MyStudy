[Leetcode-Java(200+题解，持续更新、欢迎star&留言&交流)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_68_fullJustify.java)

```java
    /**
     * 解题思路：
     * 大致想法：先确定一行放几个单词，再跟根据条件对单词进行排序
     * 1、一行能放几个单词：
     * 1.1：一个单词放下去之后占的位置是length+1(单词和单词直接至少有一个空格)
     * 1.2：按照1.1的规则循环直到需要的长度>maxWidth
     * 2、跟根据条件对单词进行排序：
     * 2.1：对于只有一个单词的行，直接从左开始摆放
     * 2.2：对于只有2个单词的行，最左和最右摆放
     * 2.3：对于多余2个单词的行，先计算单词直接平均空格有多少个，剩余空格从左到右一个单词后逐个排布（肯定不会超过总单词数）
     * 2.4：如是最后一行，则直接从左开始排序
     * <p>
     * 存储结构：maxWidth长度的数组保存
     *
     * 执行用时 :1 ms, 在所有 java 提交中击败了99.05%的用户
     * 内存消耗 :34.9 MB, 在所有 java 提交中击败了40.26%的用户
     *
     * @param words
     * @param maxWidth
     * @return
     */
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> retList = new ArrayList<>();
        List<String> lineList = new ArrayList<>();
        int leftWidth = maxWidth;
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            int wordWidth = word.length();
            if (leftWidth - wordWidth - lineList.size()  < 0) {
                //超过了需要换行了
                retList.add(handleSort(lineList, leftWidth, false));
                //换行重置
                leftWidth = maxWidth;
                lineList.clear();
            }
            lineList.add(word);
            leftWidth -= wordWidth;
        }
        if (lineList.size()>0){
            retList.add(handleSort(lineList, leftWidth, true));
        }

        return retList;
    }

    /**
     * 2.1：对于只有一个单词的行，直接从左开始摆放
     * 2.2：对于只有2个单词的行，最左和最右摆放
     * 2.3：对于多余2个单词的行，先计算单词直接平均空格有多少个，剩余空格从左到右一个单词后逐个排布（肯定不会超过总单词数）
     * 2.4：如是最后一行，则直接从左开始排序
     *
     * @param lineList
     * @param leftWidth
     * @param isLastLine
     * @return
     */
    private String handleSort(List<String> lineList, int leftWidth, boolean isLastLine) {
        StringBuilder builder = new StringBuilder();
        if (isLastLine) {
            for (int i = 0; i < lineList.size(); i++) {
                builder.append(lineList.get(i));
                if (i != lineList.size() - 1) {
                    builder.append(" ");
                    leftWidth--;
                } else {
                    for (int j = 0; j < leftWidth; j++) {
                        builder.append(" ");
                    }
                }
            }
        } else {
            //剩余空格数
            int empty = leftWidth;
            //相等空格数
            int equalEmpty;
            //左侧多余空格数
            int leftEmpty;
            if (lineList.size() == 1) {
                equalEmpty = empty;
                leftEmpty = 0;
            } else {
                equalEmpty = empty / (lineList.size() - 1);
                leftEmpty = empty % (lineList.size() - 1);
            }
            for (int i = 0; i < lineList.size(); i++) {
                builder.append(lineList.get(i));
                if (i != lineList.size() - 1 || lineList.size() == 1) {
                    for (int j = 0; j < equalEmpty; j++) {
                        builder.append(" ");
                    }
                    if (leftEmpty-- > 0) {
                        builder.append(" ");
                    }
                }
            }
        }

        return builder.toString();
    }
```