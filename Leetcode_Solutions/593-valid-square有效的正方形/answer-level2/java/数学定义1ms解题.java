### 解题思路
四条边相等并且存在一个角为直角的四边形是正方形，这里取p1作为判断是否为直角的点。需要注意输入的四个点不能出现相同的点，这里要进行判断。

### 代码

```java
class Solution{
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        boolean res = true;
        double[] p1_dis = new double[3];
        double p1p2,p1p3,p1p4,p2p3,p2p4,p3p4;
        p1p2 = distance(p1, p2);
        p1p3 = distance(p1, p3);
        p1p4 = distance(p1, p4);
        p2p3 = distance(p2, p3);
        p2p4 = distance(p2, p4);
        p3p4 = distance(p3, p4);
        double slopep1p2 = Slope(p1, p2);
        double slopep1p3 = Slope(p1, p3);
        double slopep1p4 = Slope(p1, p4);
        
        if(p1[0]==p2[0]&&p1[1]==p2[1]||p1[0]==p3[0]&&p1[1]==p3[1]||p1[0]==p4[0]&&p1[1]==p4[1]||p3[0]==p2[0]&&p3[1]==p2[1]||p4[0]==p2[0]&&p4[1]==p2[1]||p3[0]==p4[0]&&p3[1]==p4[1]){
            res = false;
        }else{
            if(p1p2==p1p3&&p1p4>p1p2){
                if(p2p4==p3p4&&p1p2==p2p4){
                    if(slopep1p2==Double.POSITIVE_INFINITY&&slopep1p3==0||slopep1p3==Double.POSITIVE_INFINITY&&slopep1p2==0){
                        res = true;
                    }else if(((p1[0]-p2[0])*(p1[0]-p3[0]))/((p1[1]-p2[1])*(p1[1]-p3[1]))==-1){
                        res = true;
                    }else{
                        res = false;
                    }
                }else{
                    res = false;
                }
            }else if(p1p2==p1p4&&p1p3>p1p2){
                if(p1p2==p2p3&&p2p3==p3p4){
                    if(slopep1p2==Double.POSITIVE_INFINITY&&slopep1p4==0||slopep1p4==Double.POSITIVE_INFINITY&&slopep1p2==0){
                        res = true;
                    }else if(((p1[0]-p2[0])*(p1[0]-p4[0]))/((p1[1]-p2[1])*(p1[1]-p4[1]))==-1){
                        res = true;
                    }else{
                        res = false;
                    }
                }else{
                    res = false;
                }
            }
            else if(p1p3==p1p4&&p1p2>p1p3){
                if(p1p3==p2p3&&p2p3==p2p4){
                    if(slopep1p3==Double.POSITIVE_INFINITY&&slopep1p4==0||slopep1p4==Double.POSITIVE_INFINITY&&slopep1p3==0){
                        res = true;
                    }else if(((p1[0]-p3[0])*(p1[0]-p4[0]))/((p1[1]-p3[1])*(p1[1]-p4[1]))==-1){
                        res = true;
                    }else{
                        res = false;
                    }
                }else{
                    res = false;
                }
            }else{
                res = false;
            }
        }
        return res;
    }

    /**
     * 
     * @param p1 p1坐标
     * @param p2 p2坐标
     * @return
     */
    public double distance(int[] p1,int[] p2){
        double dis = 0.0;
        dis=Math.sqrt(Math.pow((p1[0]-p2[0]),2)+Math.pow((p1[1]-p2[1]),2));
        return dis;
    }

    /**
     * 
     * @param p1 p1坐标
     * @param p2 p2坐标
     * @return 返回p1 p2所在直线的斜率
     */

    public double Slope(int[] p1,int[] p2){
        double slope = 0.0;
        if((p1[1]-p2[1])!=0){
            slope = (p1[0]-p2[0])/(p1[1]-p2[1]);
        }else{
            slope = Double.POSITIVE_INFINITY;
        }
        return slope;
    }

}


```