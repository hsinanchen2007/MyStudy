```
class Solution {
    static Integer[][] dirs = new Integer[][] {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };

    public int minPushBox(char[][] grid) {

        int m = grid.length;
        int n = grid[0].length;
        HashSet<Integer> visited = new HashSet<>();

        // Heap
        PriorityQueue<Integer[]> queue = new PriorityQueue<>(16, (a, b) -> a[0] - b[0]);

        Integer[] initialState = new Integer[5];
        initialState[0] = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 'S') {
                    initialState[1] = i;
                    initialState[2] = j;
                }
                else if(grid[i][j] == 'B') {
                    initialState[3] = i;
                    initialState[4] = j;
                }
            }
        }

        queue.add(initialState);

        while(queue.size() > 0) {
            Integer[] state = queue.poll();
            Integer px = state[1], py = state[2], bx = state[3], by = state[4];

            int hash = (px << 15) | (py << 10) | (bx << 5) | by;
            // System.out.println(px + "|" + py + "|" + bx + "|" + by + "|" + state[0]);
            if(visited.contains(hash)){
                continue;
            }
            visited.add(hash);

            Integer next_px, next_py, next_bx, next_by;
            for(Integer[] dir : dirs) {
                int d = state[0];
                next_px = dir[0] + px;
                next_py = dir[1] + py;

                if( !(
                    next_px >= 0 
                    && next_px < m 
                    && next_py >= 0 
                    && next_py < n 
                    && grid[next_px][next_py] != '#')) {
                    continue;
                }
                // System.out.println("pxpy:" + px + "," + py + "|next:" + next_px + "," + next_py);

                next_bx = bx;
                next_by = by;
                if(next_px == bx && next_py == by) {
                    next_bx = bx + dir[0];
                    next_by = by + dir[1];
                    if( !(
                        next_bx >= 0 &&
                        next_bx < m &&
                        next_by >= 0 &&
                        next_by < n &&
                        grid[next_bx][next_by] != '#'
                    )) {
                        continue;
                    }
                    d++;
                }
                // 到此：玩家和箱子的位置计算完毕
                if(grid[next_bx][next_by] == 'T') {
                    return d;
                }
                queue.add(new Integer[]{d, next_px, next_py, next_bx, next_by});
            } //
        } // end while
        return -1;

        
    }
}

```


解法2：箱子A*，玩家BestFirst
```
class Solution {
    
    static Vector[] dirs = new Vector[] {
        new Vector(new int[]{-1, 0}),
        new Vector(new int[]{0, 1}),
        new Vector(new int[]{1, 0}),
        new Vector(new int[]{0, -1}),
    };

    static final class Vector {
        int[] vec;
        public int priority;

        public Vector(int[] _vec){
            vec = _vec;
        }

        @Override
        public int hashCode(){
            int code = 0;
            for(int i = 0; i < vec.length; i++) {
                code = code | vec[i];
                code = code << 5;
            }
            return code;
        }

        public Vector bindPriority(int _priority){
            priority = _priority;
            return this;
        }

        public Vector slice(int from, int to) {
            int[] n = new int[to - from];
            for(int i = from; i < to; i++) {
                n[i - from] = vec[i];
            }
            return new Vector(n);
        }

        @Override
        public boolean equals(Object o) {
            Vector v = (Vector)o;
            for(int i = 0; i < vec.length; i++) {
                if(vec[i] != v.vec[i]) {
                    return false;
                } 
            }
            return true;
        }

        public static int distance(Vector v1, Vector v2) {
            int d = 0;
            for(int i = 0; i < v1.vec.length; i++) {
                d += Math.abs(v1.vec[i] - v2.vec[i]);
            }
            return d;
        }


        public Vector plus(Vector v) {
            int[] n = vec.clone();
            for(int i = 0; i < vec.length; i++) {
                n[i] += v.vec[i];
            }
            return new Vector(n);
        }

        public static Vector combine(Vector v1, Vector v2) {
            int j = 0;
            int[] n = new int[v1.vec.length + v2.vec.length];

            for(int i = 0; i < v1.vec.length; i++) {
                n[j++] = v1.vec[i];
            }
            for(int i = 0; i < v2.vec.length; i++) {
                n[j++] = v2.vec[i];
            }
            return new Vector(n);
        }

        public Vector minus(Vector v) {
            int[] n = vec.clone();
            for(int i = 0; i < vec.length; i++) {
                n[i] -= v.vec[i];
            }
            return new Vector(n);
        }

        @Override
        public String toString(){
            return Arrays.toString(vec);
        }
    }

    static final public class Map {

        Vector start_player, start_box, target;
        HashSet<Vector> floors = new HashSet<>();

        public Map(char[][] grid){
            for(int i = 0; i < grid.length; i++) {
                for(int j = 0; j < grid[0].length; j++) {
                    if(grid[i][j] == 'S') {
                        start_player = new Vector(new int[]{i, j});
                        grid[i][j] = '.';

                    }else if(grid[i][j] == 'B') {
                        start_box = new Vector(new int[]{i, j});
                        grid[i][j] = '.';

                    }else if(grid[i][j] == 'T') {
                        target = new Vector(new int[]{i, j});
                        grid[i][j] = '.';
                    }  

                    if(grid[i][j] == '.') {
                        floors.add(new Vector(new int[]{i, j}));
                    }
                }
            }

        }

        public boolean inFloor(Vector v) {
            return floors.contains(v);

        }

    }

    private int bestFirstPlayer(Map map, Vector start, Vector end, Vector box) {
        PriorityQueue<Vector> queue = new PriorityQueue<>((a, b) -> a.priority - b.priority);
        HashSet<Vector> visited = new HashSet();

        queue.add(start.bindPriority(Vector.distance(start, end)));

        while(queue.size() > 0) {
            Vector player = queue.poll();

            for(Vector dir:dirs) {
                Vector nextPlayer = player.plus(dir);
                if(!map.inFloor(nextPlayer)) {
                    continue;
                }
                if(nextPlayer.equals(box)) {
                    continue;
                }

                if(nextPlayer.equals(end)) {
                    return 1;
                }

                if(visited.contains(nextPlayer)) {
                    continue;
                }
                visited.add(nextPlayer);
                queue.add(nextPlayer.bindPriority(Vector.distance(nextPlayer, end)));
            }
        }
        return -1;

    }
    

    private int bfsPlayer(Map map, Vector start, Vector end, Vector box) {
        LinkedList<Vector> queue = new LinkedList<>();
        HashSet<Vector> visited = new HashSet();
        queue.add(start);

        while(queue.size() > 0) {
            Vector player = queue.poll();

            for(Vector dir:dirs) {
                Vector nextPlayer = player.plus(dir);
                if(!map.inFloor(nextPlayer)) {
                    continue;
                }
                if(nextPlayer.equals(box)) {
                    continue;
                }

                if(nextPlayer.equals(end)) {
                    return 1;
                }

                if(visited.contains(nextPlayer)) {
                    continue;
                }
                visited.add(nextPlayer);
                queue.add(nextPlayer);
            }
        }
        return -1;

    }

    public int minPushBox(char[][] grid) {
        Map map = new Map(grid);
        // HashSet<Vector> visited = new HashSet<>();
        PriorityQueue<Vector> queue = new PriorityQueue<>((a, b) -> a.priority - b.priority);
        Vector initialState = Vector.combine(map.start_player, map.start_box).bindPriority(Vector.distance(map.start_box, map.target));
        HashMap<Vector, Integer> gScores = new HashMap<>();
        queue.add(initialState);
        gScores.put(initialState, 0);
        // b: f = distance(s, b) + distance(b, c)
        //            g                h
        // d: f = distance(s, d) + distance(d, c)
        // s ~ a --- b  --- c
        // s ~ a --- d  --- c
        // A*

        while(queue.size() > 0) {
            Vector state = queue.poll();
            Vector player = state.slice(0, 2);
            Vector box = state.slice(2, 4);
            if(box.equals(map.target)){

                return state.priority;
            }

            for(Vector dir : dirs) {
                Vector nextBox = box.plus(dir);
                if(!map.inFloor(nextBox)){
                    continue;
                }
                Vector nextPlayer = box.minus(dir);
                if(!map.inFloor(nextPlayer)) {
                    continue;
                }

                if(bestFirstPlayer(map, player, nextPlayer, box) == -1) {
                    continue;
                }

                int next_g = gScores.get(state) + 1;
                
                Vector newState = Vector.combine(nextPlayer, nextBox);
                
                if(!gScores.containsKey(newState) || next_g < gScores.get(newState)){
                    newState.bindPriority(next_g + Vector.distance(nextBox, map.target));
                    queue.add(newState);
                    gScores.put(newState, next_g);
                }
                

                //queue.add(newState);
            }

        }

        return -1;
    }
}
```


解法3：箱子A*，人tarjan

```
class Solution {

    static Vector[] dirs = new Vector[] {
            new Vector(new int[]{-1, 0}),
            new Vector(new int[]{0, 1}),
            new Vector(new int[]{1, 0}),
            new Vector(new int[]{0, -1})
    };


    static final public class Map {
//        HashMap<Character, HashSet<Vector>> dict;
        public HashSet<Vector> floors = new HashSet<>();
        Vector start_player, start_box, target;

        char[][] _grid;
        public Map(char[][] grid) {
            _grid = grid;
            for(int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[0].length; j++) {
                    if(grid[i][j] == 'S') {
                        start_player = new Vector(new int[]{i,j});
                        grid[i][j] = '.';
                    }
                    else if(grid[i][j] == 'B') {
                        start_box = new Vector(new int[]{i,j});
                        grid[i][j] = '.';
                    }
                    else if(grid[i][j] == 'T') {
                        target = new Vector(new int[]{i, j});
                        grid[i][j] = '.';
                    }

                    if(grid[i][j] == '.') {

                        floors.add(new Vector(new int[]{i, j}));
                    }
                }
            }
        }

        public boolean inFloor(Vector v) {
            return floors.contains(v);
        }
    }

    static class Tarjan {

        int count = 1;
        HashMap<Vector, Integer> dfn = new HashMap<>();
        HashMap<Vector, Integer> low = new HashMap<>();
        HashMap<Integer, Vector> index = new HashMap<>();

        private void tarjan(Map map, Vector u, Vector parent) {
            index.put(count, u);
            low.put(u, count);
            dfn.put(u, count++);

            for(Vector dir : dirs) {
                Vector v = u.plus(dir);
                if(v.equals(parent)) {
                    continue;
                }
                if(!map.inFloor(v)) {
                    continue;
                }
                if(!low.containsKey(v)) {
                    tarjan(map, v, u);
                }
                low.put(u, Math.min(low.get(v), low.get(u)));
            }
        }


        public void init(Map map, Vector u, Vector parent) {
            tarjan(map, u, parent);
//            for(int i = 0; i < map._grid.length; i++) {
//                for(int j = 0; j < map._grid[0].length; j++) {
//                    if(map._grid[i][j] == '#') {
//                        System.out.print(" # ");
//                    } else {
//                        System.out.print(String.format("%2d ", low.get(new Vector(new int[]{i, j}))));
//                    }
//                }
//                System.out.println();
//            }
            for(Vector p : map.floors) {
                ArrayList<Vector> connect = new ArrayList<>();
                connect.add(p);

                Vector last = connect.get(connect.size() - 1);

                while(dfn.containsKey(last) && low.containsKey(last) && !dfn.get(last).equals(low.get(last))) {
                    connect.add(index.get(low.get(last)));
                    last = connect.get(connect.size() - 1);
                }
                for(int i = 0; i < connect.size() - 1; i++) {
                    low.put(connect.get(i), low.get(connect.get(connect.size() - 1)));
                }
            }

        }

        public boolean connect(Vector a, Vector b) {
            return low.get(a) == low.get(b);
        }


    }


    static final
    public class Vector {

        int [] vec;
        public int priority;
        final Integer hashValue;
        public Vector(int [] _vec) {
            vec = _vec;
            hashValue = _hash(_vec);
        }

        public static int distance(Vector v1, Vector v2) {
            return Math.abs(v1.vec[0] - v2.vec[0]) + Math.abs(v1.vec[1] - v2.vec[1]);
        }

        public Vector bindPriority(int _priority) {
            priority = _priority;
            return this;
        }

        @Override
        public int hashCode() {
            return hashValue;
        }

        public static int _hash(int[] vec) {
            int code = 0;
            for(int i = 0; i < vec.length; i++) {
                code = code | vec[i];
                code = code << 5;
            }
            return code;
        }

        @Override
        protected Object clone() {
            int[] value = vec.clone();
            Vector v = new Vector(value);
            return v;
        }

        public Vector plus(Vector v) {
            int[] n = this.vec.clone();
            for(int i = 0; i < vec.length; i++) {
                n[i] += v.vec[i];
            }
            return new Vector(n);
        }

        public Vector minus(Vector v) {
            int[] n = this.vec.clone();
            for(int i = 0; i < vec.length; i++) {
                n[i] -= v.vec[i];
            }
            return new Vector(n);
        }


        public Vector slice(int from, int to) {
            int[] v = new int[to - from];
            for(int i = from; i < to; i++) {
                v[i-from] = vec[i];
            }
            return new Vector(v);

        }

        public static Vector combine(Vector v1, Vector v2) {
            int[] v = new int[v1.vec.length + v2.vec.length];
            int k = 0;
            for(int i = 0; i < v1.vec.length;i++) {
                v[k++] = v1.vec[i];
            }
            for(int i = 0; i < v1.vec.length;i++) {
                v[k++] = v2.vec[i];
            }
            return new Vector(v);

        }

        @Override
        public boolean equals(Object o) {
            if(o == null) {return false;}
            if(o.getClass() != Vector.class) {return false;}
            return Vector.equals(this, (Vector)o);
        }

        public static boolean equals(Vector v1, Vector v2) {
            if(v1 == null || v2 == null) {return false;}
            return v1.hashCode() == v2.hashCode();
        }

        @Override
        public String toString() {
            return Arrays.toString(vec);
        }
    }



    public int minPushBox(char[][] grid) {
        PriorityQueue<Vector> queue = new PriorityQueue<>((a, b) -> a.priority - b.priority);
        HashSet<Vector> visited = new HashSet<>();
        Map map = new Map(grid);
        Tarjan tarjan = new Tarjan();
        tarjan.init(map, map.start_box, null);
        Vector initialState = Vector.combine(map.start_player, map.start_box)
                .bindPriority(Vector.distance(map.start_box, map.target));
        HashMap<Vector, Integer> gScores = new HashMap<>();

        gScores.put(initialState, 0);
        queue.add(initialState);

        while(queue.size() > 0) {
            Vector state = queue.poll();
            Vector player = state.slice(0,2);
            Vector box = state.slice(2, 4);


            for(Vector dir : dirs) {

                Vector nextBox = box.plus(dir);
                if(!map.inFloor(nextBox)) {
                    continue;
                }
                Vector nextPlayer = box.minus(dir);

                if(!map.inFloor(nextPlayer)) {
                    continue;
                }

                Vector nextState = Vector.combine(box, nextBox);

                if (visited.contains(nextState)) {
                    continue;
                }

                if(!tarjan.connect(player, nextPlayer)) {
                    continue;
                }

                if(nextBox.equals(map.target)) {
                    return state.priority;
                }
                int gScore = gScores.get(state) + 1;
                if(!gScores.containsKey(nextState) || gScore < gScores.get(nextState)) {
                    nextState.bindPriority(gScore + Vector.distance(nextBox, map.target));
                    gScores.put(nextState, gScore);
                    visited.add(nextState);
                    queue.add(nextState);
                }

            }

        }
        return -1;
    }

}
```