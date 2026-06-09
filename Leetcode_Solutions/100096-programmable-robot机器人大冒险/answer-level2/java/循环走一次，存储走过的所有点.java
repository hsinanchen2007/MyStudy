```
class Solution {
    public boolean robot(String command, int[][] obstacles, int dx, int dy) {
        int x = 0, y = 0;
        Set<Integer> path = new HashSet<>();
        path.add(0);
        for (char c: command.toCharArray()) {
            if (c == 'U')
                y++;
            else x++;
            path.add(x * 1000 + y);
        }
        int[] d = transfer(dx, dy, x, y);
        if (!path.contains(d[0] * 1000 + d[1])) return false;
        for (int[] ob: obstacles) {
            if (ob[0] > dx || ob[1] > dy) continue;
            int[] tr = transfer(ob[0], ob[1], x, y);
            if (path.contains(tr[0] * 1000 + tr[1])) return false;
        }
        return true;
    }

    private int[] transfer(int dx, int dy, int x, int y) {
        int min = Math.min(dx / x, dy / y);
        return new int[] {dx - min*x, dy-min*y};
    }
}
```