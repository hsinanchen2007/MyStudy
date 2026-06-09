```
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if (deck == null || deck.length <= 1) {
            return false;
        }
        Arrays.sort(deck);
        Map<Integer, Integer> map = new HashMap<>();
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < deck.length; i++) {
            if (map.containsKey(deck[i])) {
                map.put(deck[i], map.getOrDefault(deck[i], 0) + 1);
            } else {
                list.add(deck[i]);
                map.put(deck[i], map.getOrDefault(deck[i], 0) + 1);
            }
        }
        int size = list.size();
        for (int i = 1; i < size; i++) {
            int a = map.get(list.get(i));
            int b = map.get(list.get(i - 1));
            if (gcd(a, b) == 1) {
                return false;
            }
        }
        return true;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
