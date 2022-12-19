### 解题思路
1> 将木桩转换为hashMap,提高比较次数，便于判断是否撞墙;
2> 逐一按照命令移动，判断是否撞墙



### 代码

```java
class Solution {
   public boolean robot(String command, int[][] obstacles, int x, int y) {
        Map<Integer, Set<Integer>> map = new HashMap<>();
        if (obstacles != null) {
            for (int i = 0; i < obstacles.length; i++) {
                if (!map.containsKey(obstacles[i][0])) {
                    map.put(obstacles[i][0], new HashSet<>());
                }
                map.get(obstacles[i][0]).add(obstacles[i][1]);
            }
        }
        int lat = 0, lng = 0;
        for (int i = 0; i < command.length(); ) {
            char str = command.charAt(i);
            switch (str) {
                case 'U':
                    lng = lng + 1;
                    break;
                case 'R':
                    lat = lat + 1;
                    break;
                default:
                    break;
            }

            if (contains(lat, lng, map)) {
                return false;
            } else if (lng == y && lat == x) {
                return true;
            }

            if (lng > y || lat > x) {
                return false;
            }

            i = (i + 1) % command.length();
        }

        return x == lat && y == lng;
    }

    private boolean contains(int x, int y, Map<Integer, Set<Integer>> obstacles) {
        if (obstacles == null || obstacles.isEmpty()) {
            return false;
        }
        return obstacles.containsKey(x) && obstacles.get(x).contains(y);
    }
}
```