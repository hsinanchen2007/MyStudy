尝试用了暴力算法 60/62的时候超时了 就不贴上来了
一开始用了BFS，因为题目问的是每个空房间到“最近”门的距离，感觉用BFS更好。
后来看了比较快的题解，发现前几名都是DFS，感觉可能是数据集对DFS更友好？ 目前我的水平还分析不出来为什么递归的DFS是表现最好的一个算法。
第一个DFS, 借鉴了排名前几的答案。
第二个DFS是后来散步的时候想着不用递归试试看，脑子里有了思路，回家就自己动手不用递归用栈实现了一遍。
上下左右的代码风格可能不如用数组做循环那样好看(int [] directions; foreach循环),用几行代码完成上下左右idx的获取和判断,但是就我个人习惯而言, 目前的风格是我写起来比较顺手的。
同时简单的写了一些英文注释。
```
class Solution {

    public void wallsAndGates(int[][] rooms) {
        if(rooms==null || rooms.length==0) return;
        
        Queue<int[]> q = new LinkedList<>();
        
        int rows = rooms.length;
        int cols = rooms[0].length;
        // method1, bfs1
        // for(int i =0; i<rows; i++){
        //     for(int j =0; j<cols; j++){
        //         if(rooms[i][j]==0)
        //             q.offer(new int[]{i, j});
        //     }
        // }
        // bfs(rooms, q);
        
        // method2 dfs 
        // for(int i =0; i<rows; i++){
        //     for(int j =0; j<cols; j++){
        //         if(rooms[i][j]==0)
        //             dfs(rooms, i, j, 0, true);
        //     }
        // }
        
        
        //method3 dfs2  with stack

        for(int i =0; i<rows; i++){
            for(int j =0; j<cols; j++){
                if(rooms[i][j]==0)
                    dfs2(rooms, i, j);
            }
        }
    }
    

    public void bfs(int[][] rooms, Queue<int[]> q){
        while(!q.isEmpty()){
            int [] idx = q.poll();
            
            //up, down, left, right cells(rooms)
            //we should check boundary for each cell and make sure it is an empty room。
            
            
            int []idxUp = new int[]{idx[0]-1, idx[1]};
            if(idxUp[0]>=0 && rooms[idxUp[0]][idxUp[1]]==2147483647){
                rooms[idxUp[0]][idxUp[1]] = rooms[idx[0]][idx[1]]+1;
                q.offer(idxUp);
            }
            
            int[] idxDown = new int[]{idx[0]+1, idx[1]};
            if(idxDown[0]<rooms.length && rooms[idxDown[0]][idxDown[1]]==2147483647){
                rooms[idxDown[0]][idxDown[1]] = rooms[idx[0]][idx[1]]+1;
                q.offer(idxDown);
            }
            
            int[] idxLeft = new int[]{idx[0], idx[1]-1};
            if(idxLeft[1]>=0 && rooms[idxLeft[0]][idxLeft[1]]==2147483647){
                rooms[idxLeft[0]][idxLeft[1]] = rooms[idx[0]][idx[1]]+1;
                q.offer(idxLeft);
            }
            
            int[] idxRight = new int[]{idx[0], idx[1]+1};
            if(idxRight[1]<rooms[0].length && rooms[idxRight[0]][idxRight[1]]==2147483647){
                rooms[idxRight[0]][idxRight[1]] = rooms[idx[0]][idx[1]]+1;
                q.offer(idxRight);
            }           
        }
        
    }
    
    public void dfs(int[][] rooms, int i, int j, int distance, boolean isRoot ){

        if(i<0 || i>=rooms.length || j<0 || j>=rooms[0].length) return;
        
        
        // check if not root or wall
        
        // if((!isRoot && rooms[i][j]==0) || rooms[i][j]==-1) return;   
        
        //actually in this question, we can omit the sentence above because when room[i][j]<distance, it must be -1, and it must be a wall,
        //The variable 'distance' must not be 0 unless it's a root room, the sentence below covered this case (check if an empty room is the root room) and will return.
        //if we omit this sentence, we can even get rid of the 'isRoot' parameter.
        
        
        // check if visited and closer
        if(rooms[i][j]<distance) return;
        // if not visited or it's closer to another door than rewrite the distance
        rooms[i][j] = distance;
        // do the rest of the rooms
        dfs(rooms, i-1, j,   distance+1, false); //left
        dfs(rooms, i+1, j,   distance+1, false); //right
        dfs(rooms, i,   j-1, distance+1, false); //up
        dfs(rooms, i,   j+1, distance+1, false); //down
    }
    
    
    public void dfs2(int [][] rooms, int i, int j){
        // Here I am using a regular DFS algorithm with Stack
        Stack<int []> s = new Stack<>();
        s.push(new int[]{i, j}); //push root node
        while(!s.isEmpty()){
            int [] idx = s.peek();
            
            //directions: up left, down, right
            int [] idxUp = new int[]{idx[0]-1, idx[1]};
            if(idxUp[0]>=0 && rooms[idxUp[0]][idxUp[1]]>rooms[idx[0]][idx[1]]+1){
                s.push(idxUp);
                rooms[idxUp[0]][idxUp[1]] = rooms[idx[0]][idx[1]]+1;
                continue;
            }
            
            int [] idxLeft = new int[]{idx[0], idx[1]-1};
            if(idxLeft[1]>=0 && rooms[idxLeft[0]][idxLeft[1]]>rooms[idx[0]][idx[1]]+1){
                s.push(idxLeft);
                rooms[idxLeft[0]][idxLeft[1]]=rooms[idx[0]][idx[1]]+1;
                continue;
            }
            
            int [] idxDown = new int[]{idx[0]+1, idx[1]};
            if(idxDown[0]<rooms.length && rooms[idxDown[0]][idxDown[1]]>rooms[idx[0]][idx[1]]+1){
                s.push(idxDown);
                rooms[idxDown[0]][idxDown[1]]=rooms[idx[0]][idx[1]]+1;
                continue;
            }
            
            int [] idxRight = new int[]{idx[0], idx[1]+1};
            if(idxRight[1]<rooms[0].length && rooms[idxRight[0]][idxRight[1]]>rooms[idx[0]][idx[1]]+1){
                s.push(idxRight);
                rooms[idxRight[0]][idxRight[1]]=rooms[idx[0]][idx[1]]+1;
                continue;
            }
            s.pop();
        }
    }  
}
```
