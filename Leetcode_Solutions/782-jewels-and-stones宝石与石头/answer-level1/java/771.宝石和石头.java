```java []
class Solution {
    public int numJewelsInStones(String J, String S) {
        List<String> list = new ArrayList<>();
        for (int i = 0; i < J.length(); i++) {
            list.add(J.substring(i,i+1));
        }
        int count = 0;
        for (int i = 0; i < S.length(); i++) {
            if (list.contains(S.substring(i,i+1))) {
                count ++;
            }
        }
        return count;
    }
}
```
