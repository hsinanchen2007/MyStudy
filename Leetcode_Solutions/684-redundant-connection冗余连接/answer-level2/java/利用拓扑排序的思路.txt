循环遍历，去掉入度为1的点，然后把这条边上的点的入度都减1.直到没有入度为1的点。剩下的点就是环。然后把所有边从后往前遍历。返回在环上的边。
```
public class Main_684 {
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        int[] inDegrees = new int[n];
        for(int[] edge: edges){
            inDegrees[edge[0]-1]++;
            inDegrees[edge[1]-1]++;
        }
        while (true) {
            //System.out.println(Arrays.toString(inDegrees));
            int flag = -1;
            //System.out.println(flag);
            for (int i = 0; i < n; i++) {
                if (inDegrees[i] == 1) {
                    flag = 1;
                    for (int[] edge : edges) {
                        if (edge[0] == i+1 || edge[1] == i+1) {
                            inDegrees[edge[0] - 1]--;
                            inDegrees[edge[1] - 1]--;
                        }
                    }
                }
            }
            if(flag==-1){
                break;
            }
        }
        ArrayList<Integer> list = new ArrayList<>();
        for (int i=0;i<n;i++){
            if(inDegrees[i]==2){
                list.add(i+1);
            }
        }
        for(int i=edges.length-1;i>=0;i--){
            if(list.contains(edges[i][0])&&list.contains(edges[i][1])){
                return edges[i];
            }
        }
        return new int[2];
    }

    public static void main(String[] args){
        int[][] edge = new int[][]{{1,2},{2,3},{3,4},{1,4}, {1,5}};
        Main_684 main = new Main_684();
        System.out.println(Arrays.toString(main.findRedundantConnection(edge)));
    }
}
```
