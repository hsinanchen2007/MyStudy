```
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * interface Robot {
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     public boolean move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     public void turnLeft();
 *     public void turnRight();
 *
 *     // Clean the current cell.
 *     public void clean();
 * }
 */
class Solution {
    class P {
        int x;
        int y;
    }

    private String getKey(P p) {
        return Integer.toString(p.x) + "," + Integer.toString(p.y);
    }

    private void nextDir(P dir, Robot r) {
        r.turnRight();
        // up to right
        if(dir.x == -1 && dir.y == 0) {
            dir.x = 0; 
            dir.y = 1;
            return;
        }


        // down to left
        if(dir.x == 1 && dir.y == 0) {
            dir.x = 0;
            dir.y = -1;
            return;
        }


        // left to up
        if(dir.x == 0 && dir.y == -1) {
            dir.x = -1;
            dir.y = 0;
            return;
        }

        // right to down
        if(dir.x == 0 && dir.y == 1) {
            dir.x = 1;
            dir.y = 0;
            return;
        }
    }

    public void cleanRoom(Robot robot) {
        // 如何从一个点绕过障碍物到另外一个点
        // dfs, 每次都从原点到现在的点，记录下路径，然后回到原点，然后再到新的点
        // 每一个点都包括了原点到当前点的路径和当前点的坐标
        // 不用记录路径，只要当前点还有未被探索的邻居，我们就不把它从stack pop出来，
        // 从stack pop出来的条件是：1. 所有方向都visited，2.   
        // 直接用recursion模拟stack，传入上一个点
        // 不用记录路径了
        P p = new P();
        P dir = new P();
        dir.x = -1;
        dir.y = 0;
        h(robot, p, dir);
    }
    Set<String> v = new HashSet<>();
    private void h(Robot r, P p, P dir) {
        System.out.println("cur position is " + p.x + ", " + p.y);

        P nd = new P();
        nd.x = dir.x;
        nd.y = dir.y;

        r.clean();
        v.add(getKey(p));
        P np = new P();
        np.x = p.x + nd.x;
        np.y = p.y + nd.y;
        System.out.println("cur dir is " + nd.x + ", " + nd.y);
        if(!v.contains(getKey(np)) && r.move()) {
            h(r, np, nd);
        }

        nextDir(nd, r);
        np.x = p.x + nd.x;
        np.y = p.y + nd.y;
        System.out.println("cur dir is " + nd.x + ", " + nd.y);
        if(!v.contains(getKey(np)) && r.move()) {
            h(r, np, nd);
        }

        // 跳过原来的方向
        nextDir(nd, r);
        np.x = p.x + nd.x;
        np.y = p.y + nd.y;
        System.out.println("cur dir is " + nd.x + ", " + nd.y);
        if(!v.contains(getKey(np)) && r.move()) {
            h(r, np, nd);
        }

        nextDir(nd, r);
        np.x = p.x + nd.x;
        np.y = p.y + nd.y;
        System.out.println("cur dir is " + nd.x + ", " + nd.y);
        if(!v.contains(getKey(np)) && r.move()) {
            h(r, np, nd);
        }

        // return to origin direction
        r.turnRight();

        // return to backward direction
        r.turnRight();
        r.turnRight();
        r.move();// return to the last cell

        // return to coming direction
        r.turnRight();
        r.turnRight();
    }
}
```
