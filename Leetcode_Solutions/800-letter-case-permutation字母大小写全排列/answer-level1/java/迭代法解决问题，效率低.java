### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<String> results = new ArrayList<>();

    public List<String> letterCasePermutation(String S) {
        if (S == null || S.length() == 0) {
            return results;
        }
        char[] chars = S.toCharArray();

        for (int i = 0; i < chars.length; i++) {
            //如果是数字直接加在原来所有的后面即可
            if (Character.isDigit(chars[i])) {
                if (results.size() == 0) {
                    results.add(chars[i] + "");
                } else {
                    List<String> tmp = new ArrayList<>(results);
                    results.clear();
                    for (int j = 0; j < tmp.size(); j++) {
                        results.add(tmp.get(j) + chars[i]);
                    }
                }
            } else {
                //如果是字母，要考虑大小写，分别加在原来的后面，这样数据量加倍。
                if (results.size() == 0) {
                    //加两份，一个大写一个小写
                    results.add(Character.toLowerCase(chars[i]) + "");
                    results.add(Character.toUpperCase(chars[i]) + "");
                } else {
                    //拷贝两份
                    List<String> tmp1 = new ArrayList<>(results);
                    List<String> tmp2 = new ArrayList<>(results);
                    results.clear();
                    for (int j = 0; j < tmp1.size(); j++) {
                        results.add(tmp1.get(j) + Character.toLowerCase(chars[i]));
                        results.add(tmp2.get(j) + Character.toUpperCase(chars[i]));
                    }
                }
            }

        }
        return results;
    }
}
```