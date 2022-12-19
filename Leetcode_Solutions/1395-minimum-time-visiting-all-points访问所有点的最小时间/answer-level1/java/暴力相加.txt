![image.png](https://pic.leetcode-cn.com/a3302e1b7796c1093788820a6060170d16b7975a9fb13173f27019a47362ce90-image.png)
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int sum=0;
        int i=0;
        for(i=0;i<points.length-1;i++){
            sum+=distance(points[i][0],points[i+1][0],points[i][1],points[i+1][1]);
        }
        return sum;
    }
    public int distance(int a1 ,int a2,int b1,int b2){
       return Math.max(Math.max(a1,a2)-Math.min(a1,a2), Math.max(b1,b2)-Math.min(b1,b2));
    }
}