本题同[127. 单词接龙](https://leetcode-cn.com/problems/word-ladder/)实际一毛一样，几乎就是换个变量名的事情...
```java
class Solution {
    public int minMutation(String start, String end, String[] bank) {
        HashSet<String> bankSet = new HashSet<>(Arrays.asList(bank));
        if (!bankSet.contains(end)) return -1;

        char[] basic = {'A', 'C', 'G', 'T'};
        HashSet<String> startSet = new HashSet<>(Collections.singletonList(start));
        HashSet<String> endSet = new HashSet<>(Collections.singletonList(end));
        HashSet<String> visited = new HashSet<>();

        int count = 0;
        while (!startSet.isEmpty()) {
            HashSet<String> tempSet = new HashSet<>();
            for (String currGene : startSet) {
                char[] value = currGene.toCharArray();
                for (int i = 0; i < value.length; i++) {
                    char tmp = value[i];
                    for (char c : basic) {
                        if (tmp == c) continue;
                        value[i] = c;
                        String nextGene = new String(value);
                        if (endSet.contains(nextGene)) return count + 1;
                        if (!visited.contains(nextGene) && bankSet.contains(nextGene)) {
                            visited.add(nextGene);
                            tempSet.add(nextGene);
                        }
                    }
                    value[i] = tmp;
                }
            }
            count++;
            if (tempSet.size() > endSet.size()) {
                startSet = endSet;
                endSet = tempSet;
            } else {
                startSet = tempSet;
            }
        }
        return -1;
    }
}
```
