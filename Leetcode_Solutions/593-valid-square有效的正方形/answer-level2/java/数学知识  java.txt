执行用时 :1 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :35.3 MB, 在所有 Java 提交中击败了82.35%的用户
```
class Solution {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        if(p1[0]==p2[0] && p2[0]==p3[0] && p3[0]==p4[0] && p1[1]==p2[1] && p2[1]==p3[1]  && p3[1]==p4[1]){
            return false;
        }
        if(p1[0]+p2[0]==p3[0]+p4[0] && p1[1]+p2[1]==p3[1]+p4[1]){
            int x1=p1[0]-p2[0];
            int y1=p1[1]-p2[1];
            int x2=p3[0]-p4[0];
            int y2=p3[1]-p4[1];
            if((x1*x2+y1*y2)==0 && x1*x1+y1*y1==x2*x2+y2*y2){
                return true;
            }else{
                return false;
            }
        }else if(p1[0]+p3[0]==p2[0]+p4[0] && p1[1]+p3[1]==p2[1]+p4[1]){
            int x1=p1[0]-p3[0];
            int y1=p1[1]-p3[1];
            int x2=p2[0]-p4[0];
            int y2=p2[1]-p4[1];
            if((x1*x2+y1*y2)==0 && x1*x1+y1*y1==x2*x2+y2*y2){
                return true;
            }else{
                return false;
            }
        }else if(p1[0]+p4[0]==p2[0]+p3[0] && p1[1]+p4[1]==p2[1]+p3[1]){
            int x1=p1[0]-p4[0];
            int y1=p1[1]-p4[1];
            int x2=p3[0]-p2[0];
            int y2=p3[1]-p2[1];
            if((x1*x2+y1*y2)==0 && x1*x1+y1*y1==x2*x2+y2*y2){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
}
```
