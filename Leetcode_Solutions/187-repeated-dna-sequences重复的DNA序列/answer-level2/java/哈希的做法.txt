```
class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Set<String> hashset = new HashSet<>();
        Set<String> res = new HashSet<>();
        for (int i = 0; i <= s.length() - 10; i++) {
            String temp = s.substring(i, i + 10);
            if (hashset.contains(temp)) {
                res.add(temp);
            } else {
                hashset.add(temp);
            }
        }
        return new ArrayList<>(res);
    }
}
```
