好样的~


```java
class Solution {
    public String[] permutation(String S) {
        List<String> list = new ArrayList<>();
        list.add(S);
        for (int i = 0; i < S.length() - 1; i++) {
            int size = list.size();
            for (int j = i + 1; j < S.length(); j++) {
                for (int index = 0; index < size; index++) {
                    list.add(swap(list.get(index), i, j));
                }
            }
        }
        return list.toArray(new String[list.size()]);
    }
    //交换位置
    private String swap(String s, int pos1, int pos2) {
        char[] chars = s.toCharArray();
        chars[pos1] ^= chars[pos2];
        chars[pos2] ^= chars[pos1];
        chars[pos1] ^= chars[pos2];
        return new String(chars);
    }
}
```

很多人不理解这个交换法，我来说明下
假如是
abcd
那么第一轮，index 0以上的，跟0做交换，得到：
bacd
cbad
dbca
第二轮，index 1以上的，跟1做交换，（包括第一轮添加的）：
acbd
bcad
cabd
dcba
adcb
bdca
cdab
dacb
第三轮，index 2以上的，跟2做交换，（包括第1,2伦添加的）
abdc
badc
cbda
dbac
acdb
bcda
cadb
dcab
adbc
bdac
cdba
dabc
加起来一共是24种