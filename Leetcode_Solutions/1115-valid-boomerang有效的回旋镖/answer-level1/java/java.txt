```java
class Solution {
    public boolean isBoomerang(int[][] points) {
    	//有点相同：
    	String pointA = points[0][0] +""+points[0][1];
    	String pointB =  points[1][0] +""+points[1][1];
    	String pointC =  points[2][0] +""+points[2][1];
    	if(pointA.equals(pointB)||pointA.equals(pointC)||pointB.equals(pointC)){
    		return false;
    	}
        //A B C 同一直线;
        double Kab = (points[0][1] - points[1][1])*1.0/(points[0][0] - points[1][0])*1.0;
        double Kac = (points[1][1] - points[2][1])*1.0/(points[1][0] - points[2][0])*1.0;
        double Kbc = (points[0][1] - points[2][1])*1.0/(points[0][0] - points[2][0])*1.0;
        if(Kab==Kac||Kab==Kbc||Kac==Kbc){
        	return false;
        }
        return true;
        
    }
}
```