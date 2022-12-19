import org.junit.jupiter.api.Test;

/**
 * 解题思路： 1 0 0
 *          0 1 0
 *          0 0 1
 * 相邻两行，相应位都有1，则对应两行“或”合并。
 */

public class 朋友圈 {

    @Test
    public void test() {
        int [][] M = {{1,0,0},
                {0,1,0},
                {0,0,1}};
        System.out.println(findCircleNum(M));
    }
    public int findCircleNum(int[][] M) {
        int N = M.length;
        int [] circleStatus = new int [N];
        int emerge = 0;
        for(int i = 0;i < N; i ++) {
            for(int j = i + 1;j < N;j ++) {
                if(isMergeCycle(M,i,j)) {
                    emerge ++;
                    break;
                }
            }
        }
        return N - emerge;
    }

    private boolean isMergeCycle(int [][] M, int i, int j) {
        boolean isMerge = false;
        for(int k = 0; k < M.length;k ++) {
            if(M[i][k] == 1 && M[j][k] == 1) {
                isMerge = true;
                break;
            }
        }
        if(isMerge) {
            for(int k = 0;k < M.length;k ++) {
                M[j][k] = M[j][k] | M[i][k];
            }
        }
        return isMerge;
    }
}
