 startPos:左上角的点；startNum:左上角的数值，n:左上角开始，螺旋一周，且边长为n;

```
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        ans = dp(n, ans, 0, 1);
        return ans;

    }
    public int[][] dp(int n, int[][] ans, int startPos, int startNum){
        if(n<=0) return ans;
        for(int i = startPos; i < startPos+n; i++){
            ans[startPos][i] = startNum++;
        }
        // down
        for(int j = startPos+1; j < startPos+n; j++){
            ans[j][startPos+n-1] = startNum++;
        }
        //<-
        for(int i = startPos+n-2; i>=startPos; i--){
            ans[startPos+n-1][i] = startNum++;
        }
        // up
        for(int j = startPos+n-2; j > startPos; j--){
            ans[j][startPos] = startNum++;
        } 
        ans = dp(n-2, ans, startPos+1, startNum);
        return ans;
    }
}
```
