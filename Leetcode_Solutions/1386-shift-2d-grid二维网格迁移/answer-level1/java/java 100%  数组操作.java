java
执行用时 :38 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :53 MB, 在所有 java 提交中击败了100.00%的用户
public class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        for (int i = 0; i < k; i++) {
            shift(grid);
        }
        List<List<Integer>> ret= new LinkedList<>();
        for (int i = 0; i < grid.length; i++) {
            List<Integer> templs=new LinkedList<>();
            for (int j = 0; j < grid[0].length; j++) {
                templs.add(grid[i][j]);
            }
            ret.add(templs);
        }
        return ret;
    }

    private void shift(int[][] grid){
        System.out.println(grid[0][0]);
        int[] temp=new int[grid.length];
        for (int i = 0; i <grid.length ; i++) {
            int m=i-1;
            if (m<0){
                m=grid.length-1;
            }
            temp[i]=grid[m][grid[0].length-1];
        }

        for (int i = 0; i < grid.length; i++) {
            for (int j=grid[0].length-1; j>=1 ; j--) {
                grid[i][j]=grid[i][j-1];
            }
        }
        for (int i = 0; i <grid.length ; i++) {
            grid[i][0]=temp[i];
        }
    }
}