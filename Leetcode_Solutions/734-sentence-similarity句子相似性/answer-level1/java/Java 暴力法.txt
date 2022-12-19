```
class Solution {
    public boolean areSentencesSimilar(String[] words1, String[] words2, List<List<String>> pairs) {
        if (words1.length != words2.length) {
            return false;
        }
        for (int i = 0; i < words1.length; i++) {
            if (words1[i].equals(words2[i])) {
                continue;
            }
            boolean def = false;
            for (int j = 0; j < pairs.size(); j++) {
                String a = pairs.get(j).get(0);
                String b = pairs.get(j).get(1);
                if (words1[i].equals(a) && words2[i].equals(b)) {
                    def = true;
                }
                if (words1[i].equals(b) && words2[i].equals(a)) {
                    def = true;
                }
            }
            if (def) {
                continue;
            } else {
                return def;
            }
        }
        return true;
    }
}
```
