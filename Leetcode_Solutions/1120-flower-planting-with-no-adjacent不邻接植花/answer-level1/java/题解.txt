```java
class Solution {
    public int[] gardenNoAdj(int N, int[][] paths) {
        int[][] topo = new int[N+1][3] ;
        for( int[] cur : paths ){
            int temp = 0 ;
            while( topo[cur[0]][temp] != 0 ) temp++ ;
            topo[cur[0]][temp] = cur[1] ;
            temp = 0 ;
            while( topo[cur[1]][temp] != 0 ) temp++ ;
            topo[cur[1]][temp] = cur[0] ;
        }
        int[] res1 = new int[N+1] ;
        int[] res = new int[N] ;
        for( int i = 1 ; i <= N ; i++ ){
            int temp = 1 ;
            while( res1[topo[i][0]] == temp || res1[topo[i][1]] == temp || res1[topo[i][2]] == temp ) temp++ ;
            res1[i] = temp ;
        }
        for( int i = 0 ; i < N ; i++ ) res[i] = res1[i+1] ;
        return res ;
    }
}