### 解题思路
1. 遍历words数组，
2. 求出单行单词个数numOfWords，
3. 根据题义，单行空格数为maxWidth - wordsLength
4. 拼接字符串

### 代码

```java
class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> list = new ArrayList<>();
        int N = words.length;

        int i = 0;
        while (i < N) {
            if (words[i].length() == maxWidth) {
                list.add(words[i]);
                i++;
            } else {
                //计算出单行单词个数

                //单行的长度（含空格）
                int wordsWidth = 0;
                //单行文字长度
                int wordsLength = 0;
                List<String> singleList = new ArrayList<>();

                while (i < N) {
                    if (wordsWidth + words[i].length() > maxWidth) {
                        break;
                    }
                    wordsWidth += words[i].length() + 1;
                    wordsLength += words[i].length();
                    singleList.add(words[i]);
                    i++;
                }

                boolean isLast = i >= N;

                //单词个数
                int numOfWords = singleList.size();
                //空格数
                int spaceCount = maxWidth - wordsLength;

                if (numOfWords == 1) {
                    StringBuilder sb = new StringBuilder();
                    sb.append(singleList.get(0));
                    sb.append(getSpaceOfCount(spaceCount));
                    list.add(sb.toString());
                } else {
                    if (isLast) {
                        StringBuilder sb = new StringBuilder();
                        for (int x = 0; x < singleList.size(); x++) {
                            sb.append(singleList.get(x));
                            if (x != singleList.size() - 1) {
                                sb.append(getSpaceOfCount(1));
                            }
                        }
                        if (sb.length() < maxWidth) {
                            sb.append(getSpaceOfCount(maxWidth - sb.length()));
                        }
                        list.add(sb.toString());
                    } else {
                        int[] array = new int[numOfWords - 1];
                        for (int n = 0; n < spaceCount; n++) {
                            array[n % (numOfWords - 1)]++;
                        }
                        StringBuilder sb = new StringBuilder();
                        for (int x = 0; x < singleList.size(); x++) {
                            sb.append(singleList.get(x));
                            if (x != singleList.size() - 1) {
                                sb.append(getSpaceOfCount(array[x]));
                            }
                        }
                        list.add(sb.toString());
                    }
                }

            }
        }

        return list;
    }

    private String getSpaceOfCount(int count) {
        String res = "";
        while (count > 0) {
            res += " ";
            count--;
        }
        return res;
    }
}
```