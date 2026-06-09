```
class Solution {
    public int strStr(String base, String target) {
        if (base == null || target == null) {
            return -1;
        }
        if (0 == target.length()) {
            return 0;
        }
        if (target.length() > base.length()) {
            return -1;
        }
        if (target.length() == base.length()) {
            for (int i = 0; i < base.length(); i++) {
                if (base.charAt(i) != target.charAt(i)) {
                    return -1;
                }
            }
            return 0;
        }
        int[] table = getTable(target);
        for (int i = 0; i < base.length() - target.length() + 1; ) {
            for (int j = 0; j < target.length(); j++) {
                if (base.charAt(i + j) == target.charAt(j) && j == target.length() - 1) {
                    return i;
                }
                if (base.charAt(i + j) != target.charAt(j)) {
                    if (j == 0) {
                        i = i + 1;
                        break;
                    }
                    //已匹配的-匹配表
                    i = i + j - table[j - 1];
                    break;
                }
            }
        }
        return -1;
    }
        private int getHighestCommonLength(List<String> s1, List<String> s2) {
        int value = 0;
        for (String s : s1) {
            if (s2.contains(s) && s.length() > value) {
                value = s.length();
            }
        }

        return value;
    }

    private List<String> producePrefix(String string) {
        List<String> list = new ArrayList<>();
        for (int i = 1; i < string.length(); i++) {
            list.add(string.substring(0, i));
        }
        return list;
    }

    private List<String> produceSuffix(String string) {
        List<String> list = new ArrayList<>();
        for (int i = 1; i < string.length(); i++) {
            list.add(string.substring(i));
        }
        return list;
    }

    private List<String> produceTargetString(String string) {
        List<String> list = producePrefix(string);
        list.add(string);
        return list;
    }

    public int[] getTable(String string) {
        int[] table = new int[string.length()];
        List<String> list = produceTargetString(string);
        for (int i = 0; i < string.length(); i++) {
            String target = list.get(i);
            table[i] = getHighestCommonLength(producePrefix(target), produceSuffix(target));
        }
        return table;
    }
}
```
