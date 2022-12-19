### 解题思路
一定要细心；
出了问题打印调试就行

### 代码

```java
class Solution {
     public static int[] pondSizes(int[][] land) {
        List<Integer> ans = new ArrayList<>();
        // int ans_index = 0;

        int direct[][]= {{1,0}, {1,1}, {0,1}, {-1,1},
                {-1,0},{-1,-1},{0,-1}, {1, -1}};
        int row = land.length;
        if(row<=0){ return null;}
        int col = land[0].length;
        if(col<=0){ return null;}

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int land_total = 0;
                if(land[i][j]==0){
                    land[i][j]=1;
                    land_total++;
                    Queue<Integer> queue = new LinkedList<>();
                    queue.add(i * col + j);

                    while(!queue.isEmpty()){
                        int popElement = queue.remove();
                        int index_i = popElement/col;
                        int index_j = popElement%col;

                        for(int posx=0; posx<8; posx++){
                            int newPosX = index_i + direct[posx][0];
                            int newPosY = index_j + direct[posx][1];
                            if(newPosX>=0 && newPosX<row && newPosY>=0 &&
                                    newPosY<col && land[newPosX][newPosY]==0){
                                queue.add(newPosX * col + newPosY);
                                land[newPosX][newPosY] = 1;
                                land_total++;
                            }
                         }
                    }
                }
                // System.out.println("["+i+","+j+"] --> " + land_total);
                if(land_total!=0){
                    ans.add(land_total);
                }
            }
        }

        int ansLength = ans.size();
        int[] sol = new int[ansLength];
        // System.out.println(ansLength);
        for(int sol_index=0; sol_index<ansLength; sol_index++){
            sol[sol_index] = ans.get(sol_index);
            // System.out.println(ans.get(sol_index));
        }
        Arrays.sort(sol);
        return sol;
    }

}
```