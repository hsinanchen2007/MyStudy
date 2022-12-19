```
class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        
       Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < reservedSeats.length; i++) {
            if (map.get(reservedSeats[i][0]) == null) {
                List<Integer> li = new ArrayList<>();
                li.add(reservedSeats[i][1]);
                map.put(reservedSeats[i][0], li);
            } else {
                List<Integer> li = map.get(reservedSeats[i][0]);
                li.add(reservedSeats[i][1]);
            }
        }
        int zw = 0;
        for (Integer t : map.keySet()) {
            List<Integer> li = map.get(t);
            int[] count = new int[3];
            for (int i = 0; i < li.size(); i++) {
                int zb = li.get(i);
                if (zb >= 2 && zb <= 5) {
                    count[0] = 1;
                }
                if (zb >= 4 && zb <= 7) {
                    count[1] = 1;
                }
                if (zb >= 6 && zb <= 9) {
                    count[2] = 1;
                }
            }
            int js = 0;
            for (int c : count) {
                if (c == 0) {
                    js++;
                }
            }
            if (js == 1 || js == 2) {
                zw++;
            }
            if (js == 3) {
                zw += 2;
            }
        }
        if (n > map.size()) {
            zw += (n - map.size()) * 2;
        }
        return zw;
    }
}
```
