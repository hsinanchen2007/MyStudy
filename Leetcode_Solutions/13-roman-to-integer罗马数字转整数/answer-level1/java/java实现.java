```Java
        int ans = 0;
        String[] strs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int[] ints = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < strs.length; i++) map.put(strs[i], ints[i]);
        for (int i = 0; i < s.length(); ) {
            if (i + 1 < s.length() && map.containsKey(s.substring(i, i + 2))) {
                ans = ans + map.get(s.substring(i, i + 2));
                i += 2;
            } else {
                ans += map.get(String.valueOf(s.charAt(i)));
                i += 1;
            }
        }
        return ans;
```