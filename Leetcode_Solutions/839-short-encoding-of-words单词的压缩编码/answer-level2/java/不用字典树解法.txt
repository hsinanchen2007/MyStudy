### 解题思路
在输出为13956那一组数据卡住了，自己的输出一直是13950，后来才发现自己把abcd,bc这一种情况中bc也给整合进了abcd中。

思路：
将所有后缀子串做标记，最后统计集合中未做标记的各字符串的总长度（并加上未做标记的字符串的数量）。

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        int[] flags = new int[words.length];
        for (int i = 0; i < words.length; i++) {
            if (flags[i] == 0) {
                for (int j = i + 1; j < words.length; j++) {
                    int index1 = words[j].indexOf(words[i]);
                    //是否是子串，且是否是后缀子串（即abcd和bcd是，但abcd和bc不是）
                    if (index1 != -1 && index1 + words[i].length() == words[j].length()) {
                        flags[i] = 1;
                        break;
                    }
                    int index2 = words[i].indexOf(words[j]);
                    if (index2!=-1 && index2 + words[j].length() == words[i].length()) {
                        flags[j] = 1;
                    }
                }
            }
        }
        int res = 0;
        for (int i=0; i<words.length; i++) {
            if(flags[i]==0)
                res += words[i].length() + 1;
        }
        return res;
    }
}
```