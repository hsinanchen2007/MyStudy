```
class Solution {
    int max_ans = 10000;

    Stack<Integer> stack_min =new Stack<>();

    public int shortestDistance(int[][] maze, int[] start, int[] destination) {
        Stack<Integer> stack =new Stack<>();
        stack.push(0);
        int[][] visited = new int[maze.length][maze[0].length];
        dfs(maze,start,destination,visited,stack);
        return max_ans==10000? -1:max_ans;

    }
    public void dfs(int[][] maze, int[] start, int[] destination, int[][] visited, Stack<Integer> stack) {
        int temp = 0;

        if(stack.size()!=0)   temp = stack.peek();

        if (visited[start[0]][start[1]]<= temp && visited[start[0]][start[1]]!=0)
            return;
        visited[start[0]][start[1]] = temp;

        if (start[0] == destination[0] && start[1] == destination[1])
        {
            max_ans = temp;
            return;
        }


        int r = start[1] + 1, l = start[1] - 1, u = start[0] - 1, d = start[0] + 1;

        while (r < maze[0].length && maze[start[0]][r] == 0) // right
            r++;  //若右可行，则一直向右到底, r = 最后一个可行空间 + 1
        if(r!=start[1] + 1){
            stack.push(r-start[1]-1+temp);
            dfs(maze, new int[] {start[0], r - 1}, destination, visited,stack);//从r指向墙壁处，向左回退一个，使r指向的到右手的最后一个空格。
            stack.pop();
        }


        while (l >= 0 && maze[start[0]][l] == 0) //left
            l--;
        if(l!=start[1] - 1) {
            stack.push(Math.abs(l - start[1]) - 1 + temp);
            dfs(maze, new int[]{start[0], l + 1}, destination, visited, stack);
            stack.pop();
        }


        while (u >= 0 && maze[u][start[1]] == 0) //up
            u--;
        if(u != start[0] - 1) {
            stack.push(Math.abs(u - start[0]) - 1 + temp);
            dfs(maze, new int[]{u + 1, start[1]}, destination, visited, stack);
            stack.pop();
        }


        while (d < maze.length && maze[d][start[1]] == 0) //down
            d++;
        if(d != start[0] + 1) {
            stack.push(Math.abs(d - start[0]) - 1 + temp);
            dfs(maze, new int[]{d - 1, start[1]}, destination, visited, stack);
            stack.pop();
        }
//        return;
    }

}
```
