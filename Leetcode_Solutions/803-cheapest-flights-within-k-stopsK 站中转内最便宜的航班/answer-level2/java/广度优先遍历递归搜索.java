
```java
class Solution {
    //map[i][j]表示i到j的费用
    int[][] map;
    int result = Integer.MAX_VALUE;
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        map = new int[n][n];
        for(int[] flight:flights){
            map[flight[0]][flight[1]] = flight[2];
        }
        //可以经转k次可以看作可以飞行k+1次
        return methodOne(n,src, dst, K+1, 0);
    }

    //使用广度优先遍历递归搜索
    public int methodOne(int n, int cur, int dst, int K, int fee){
        if(cur == dst) return fee;
        if(K==0) return -1; //可以飞行的次数为0
        for(int i=0; i<n; i++){
            //fee+map[cur][i]<result可以进行剪枝
            if(map[cur][i]!=0 && fee+map[cur][i]<result){
                int temp = methodOne(n, i, dst, K-1, fee+map[cur][i]);
                if(temp!=-1) result = Math.min(result, temp);
            }
        }
        return result==Integer.MAX_VALUE?-1:result;
    }
}
```
