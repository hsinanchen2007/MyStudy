1.当数组长度小于2时，直接返回true
2.先根据前两个组数据求出斜率k1
3.用for遍历后边的数据，看是否与前面的斜率相等
class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        if(coordinates.length<=2){
                return false;
        }
        int x1=coordinates[0][0];
        int x2=coordinates[1][0];
        int y1=coordinates[0][1];
        int y2=coordinates[1][1];
        double k1=(double)(y2-y1)/(x2-x1);
        for(int i=2;i<coordinates.length-1;i++){
            int x3=coordinates[i][0];
            int y3=coordinates[i][1];
            double k2=(double)(y3-y1)/(x3-x1);
            if(k2!=k1){
                return false;
            }
            
        }
        return true;
    }
}