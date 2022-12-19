代码有点乱，一点都不妙=-=

```
class Solution {
    public int[] masterMind(String solution, String guess) {
        int len = solution.length();
        int ok = 0;
        int maybe = 0;

        HashMap<Character, Integer> hashMap = new HashMap<>();
        hashMap.put('R', 0);
        hashMap.put('Y', 0);
        hashMap.put('G', 0);
        hashMap.put('B', 0);

        for (int i = 0; i < len; i++) {
            char s = solution.charAt(i);
            char g = guess.charAt(i);
            if (s == g) ok++;
            hashMap.put(s, hashMap.get(s) + 1);
        }

        for (int i = 0; i < len; i++) {
            char g = guess.charAt(i);
            if (hashMap.get(g) > 0) {
                hashMap.put(g, hashMap.get(g) - 1);
                maybe++;
            }
        }

        return new int[]{ok, maybe - ok};
    }
}
```