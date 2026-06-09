就像是写公司业务代码一样。。
![微信截图_20200131100247.png](https://pic.leetcode-cn.com/84f7616587d8b5330589225fca8fd4b12430a2a70ea0187b12a17ad2ced3e31c-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200131100247.png)


```java
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> result = new ArrayList<>();
        if (words == null || words.length == 0 || maxWidth <= 0) {
            return result;
        }

        int startIndex = 0;
        int endIndex = 0;
        int curLength = 0;

        while (startIndex < words.length) {

            while (curLength < maxWidth && endIndex <= words.length - 1) {
                if (curLength + words[endIndex].length() > maxWidth) {
                    break;
                }

                curLength += words[endIndex].length() + 1;
                endIndex ++;
            }

            endIndex --;

            int leftSpaces = maxWidth;
            for (int i = startIndex; i <= endIndex; i ++) {
                leftSpaces -= words[i].length();
            }

            StringBuilder sb = new StringBuilder();
            if (endIndex == startIndex){
                sb.append(words[endIndex]);
                if (leftSpaces > 0) {
                    for (int i = 0; i < leftSpaces; i ++) {
                        sb.append(" ");
                    }
                }
            } else {
                if (endIndex == words.length - 1) { // 最后一行 左对齐
                    for (int i = startIndex; i < endIndex; i ++) {
                        sb.append(words[i]);
                        sb.append(" ");
                        leftSpaces --;
                    }

                    sb.append(words[endIndex]);

                    while (leftSpaces > 0) {
                        sb.append(" ");
                        leftSpaces --;
                    }
                } else {
                    int averSplit = leftSpaces / (endIndex - startIndex);
                    int left = leftSpaces % (endIndex - startIndex);

                    for (int i = startIndex; i < endIndex; i ++) {
                        sb.append(words[i]);

                        int l = averSplit;
                        if (left > 0) {
                            l ++;
                            left --;
                        }

                        for (int j = 0; j < l; j ++) {
                            sb.append(" ");
                        }
                    }

                    sb.append(words[endIndex]);
                }
            }

            result.add(sb.toString());

            startIndex = endIndex + 1;
            endIndex = startIndex;
            curLength = 0;
        }

        return result;
    }
```
