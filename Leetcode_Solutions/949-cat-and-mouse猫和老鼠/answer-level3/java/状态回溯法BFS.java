这题采用状态回溯法，难点就是查找状态之间的转移关系，看以下代码配合注释应该就可以理解
```
// time complexity O(n * n * 2)
class Solution {
    public int catMouseGame(int[][] adj) {
        int n = adj.length;

        // 1. initial
        // status[i][j][k] 表示老鼠在i位置， 猫在j位置，k表示该由谁移动(0表示鼠移动， 1表示猫移动)
        // 结果为0，1，2(1表示鼠胜，2表示猫胜，0表示平局)
        int[][][] status = new int[n][n][2];
        Deque<int[]> queue = new ArrayDeque<>();
        // status[i][i][k] 表示鼠猫同位置，猫胜；
        // status[0][i][k] 表示鼠进洞，鼠胜；
        for(int i = 1; i < n; i++){
            status[i][i][0] = 2;
            status[i][i][1] = 2;
            status[0][i][0] = 1;
            status[0][i][1] = 1;
            queue.add(new int[]{i, i, 0});
            queue.add(new int[]{i, i, 1});
            queue.add(new int[]{0, i, 0});
            queue.add(new int[]{0, i, 1});
        }

        // 2. BFS 搜索
        while(!queue.isEmpty()){
            int[] cur = queue.poll();
            int i = cur[0], j = cur[1], k = cur[2];
            if(k == 0){ // 鼠行动，说明上一次是猫行动
                // 在倒推上一步的猫状态时需要确保满足题意，猫不会在0位置处
                if(status[i][j][0] == 2){ // 猫胜利，那么根据最优玩法，上次的猫行动可以直接选择胜利的玩法
                    for(int pre: adj[j]){
                        if(pre != 0 && status[i][pre][1] == 0){
                            status[i][pre][1] = 2;
                            queue.add(new int[]{i, pre, 1});
                        }
                    }
                } else { // 鼠胜利，那么只有当上次猫的所有行动下都是鼠胜利，猫才稳输
                    for(int pre:adj[j]){
                        if(pre != 0 && status[i][pre][1] == 0){
                            boolean canMouseWin = true;
                            for(int next: adj[pre]){
                                if(next != 0 && status[i][next][0] != 1){
                                    canMouseWin = false;
                                    break;
                                }
                            }
                            if(canMouseWin){
                                status[i][pre][1] = 1;
                                queue.add(new int[]{i, pre, 1});
                            }
                        }
                    }
                }
            } else { // 猫行动，说明上次是鼠行动
                if(status[i][j][1] == 1){ // 鼠胜利，那么上次的鼠直接通过这次的选择即可确保胜利
                    for(int pre: adj[i]){
                        if(status[pre][j][0] == 0){
                            status[pre][j][0] = 1;
                            queue.add(new int[]{pre, j, 0});
                        }
                    }
                } else { //猫胜利，那么当且仅当上次的鼠的所有行动都为猫胜利，鼠才稳输
                    for(int pre: adj[i]){
                        if(status[pre][j][0] == 0){
                            boolean canCatWin = true;
                            for(int next: adj[pre]){
                                if(status[next][j][1] != 2){
                                    canCatWin = false;
                                    break;
                                }
                            }
                            if(canCatWin){
                                status[pre][j][0] = 2;
                                queue.add(new int[]{pre, j, 0});
                            }
                        }
                    }
                }
            }
        }
        return status[1][2][0];
    }
}
```