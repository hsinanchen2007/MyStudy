### 解题思路
对于上一层的每一个'('，先找打和它配对的')'。
例如   xxxxx(xxxx)xxxx，可以在其里面和后面分别添加一对()，生产两种模式。
里面添加：xxxxx(xxxx)xxxx    ->    xxxxx([xxxx])xxxx
后面添加：xxxxx(xxxx)xxxx    ->    xxxxx(xxxx)[]xxxx
为了方便区分，我用[]表示我先添加的()。
然后从1层依次BFS到N层就可以了，最后利用set来去重。


### 代码

```java
class Solution {
    private int findPair(String str, int index) {
        int left = 1;
        int right = 0;
        for (int i = index + 1; i < str.length(); i++) {
            if (str.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                return i;
            }
        }
        return 0;
    }

    private Set<String> generateNext(String str) {
        Set<String> result = new HashSet<>();
        if (str.length() == 0) {
            result.add("()");
            return result;
        }
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '(') {
                int pairIndex = findPair(str, i);
                String newStr1 = str.substring(0, i + 1) +
                        "(" + str.substring(i + 1, pairIndex) + ")" +
                        str.substring(pairIndex, str.length());
                result.add(newStr1);
                String newStr2 = str.substring(0, pairIndex + 1) + "()" + str.substring(pairIndex + 1, str.length());
                result.add(newStr2);
            }
        }
        return result;
    }

    public List<String> generateParenthesis(int n) {
        if (n == 0) {
            return new ArrayList<>();
        }
        Set<String> set = new HashSet<>();
        set.add("");
        int depth = 0;
        while (depth < n) {
            Set<String> tmp = new HashSet<>();
            for (String sub : set) {
                Set<String> nextSet = generateNext(sub);
                //System.out.println("depth = " + depth + ", next = " + nextSet.toString());
                tmp.addAll(nextSet);
            }
            set = tmp;
            depth++;
        }
        return new ArrayList<>(set);
    }
}
```