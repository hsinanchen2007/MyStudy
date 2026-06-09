### 解题思路
变量有点多，Xab中X代表横坐标，a代表正方形序号，b代表左上右下边（1，2，3，4）。

### 代码

```cpp
class Solution {
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
        vector<double> res(4);
        double x1 = square1[0]+square1[2]*1.0/2;
        double y1 = square1[1]+square1[2]*1.0/2;
        double x2 = square2[0]+square2[2]*1.0/2;
        double y2 = square2[1]+square2[2]*1.0/2;
        if(x1==x2)
        {
            res[0]=x1;res[2]=x1;
            if(y1>y2)
            {
                res[3]=y1+square1[2]*1.0/2;
                res[1]=square2[1];
            }
            else if(y2>y1)
            {
                
                res[3]=y2+square2[2]*1.0/2;
                res[1]=square1[1];cout<<square1[1]<<endl;
            }
            else
            {
                if(square1[2]>square2[2])
                {
                    res[3]=square1[1]+square1[2];
                    res[1]=square1[1];
                }
                else
                {
                    res[3]=square2[1]+square2[2];
                    res[1]=square2[1];
                }
            }
            return res;
        }
        double k = (y2-y1)*1.0/(x2-x1);
        double b = y1-k*x1;

        
        vector<double> xx(4);
        vector<double> yy(4);
        int count = 0;
        
        double x11 = square1[0];
        double y11 = k*x11+b;
        if(y11>=square1[1]&&y11<square1[1]+square1[2])
        {
            xx[count]=x11;
            yy[count]=y11;
            count++;
        }
        
        double y12 = square1[1]+square1[2];
        double x12 = (y12-b)*1.0/k;
        if(x12>=square1[0]&&x12<square1[0]+square1[2])
        {
            xx[count]=x12;
            yy[count]=y12;
            count++;
        }
        
        double x13 = square1[0]+square1[2];
        double y13 = k*x13+b;
        if(y13>square1[1]&&y13<=square1[1]+square1[2])
        {
            xx[count]=x13;
            yy[count]=y13;
            count++;
        }
        double y14 = square1[1];
        double x14 = (y14-b)*1.0/k;
        if(x14>square1[0]&&x14<=square1[0]+square1[2])
        {
            xx[count]=x14;
            yy[count]=y14;
            count++;
        }
        
        double x21 = square2[0];
        double y21 = k*x21+b;
        if(y21>=square2[1]&&y21<square2[1]+square2[2])
        {
            xx[count]=x21;
            yy[count]=y21;
            count++;
        }
        
        double y22 = square2[1]+square2[2];
        double x22 = (y22-b)*1.0/k;
        if(x22>=square2[0]&&x22<square2[0]+square2[2])
        {
            xx[count]=x22;
            yy[count]=y22;
            count++;
        }
        
        double x23 = square2[0]+square2[2];
        double y23 = k*x23+b;
        if(y23>square2[1]&&y23<=square2[1]+square2[2])
        {
            xx[count]=x23;
            yy[count]=y23;
            count++;
        }
        double y24 = square2[1];
        double x24 = (y24-b)*1.0/k;
        if(x24>square2[0]&&x24<=square2[0]+square2[2])
        {
            xx[count]=x24;
            yy[count]=y24;
            count++;
        }
        double maxValue = *max_element(xx.begin(),xx.end()); 
        double minValue = *min_element(xx.begin(),xx.end());
        for(int i = 0;i<4;i++)
        {
            if(xx[i]==maxValue)
            {
                res[2]=xx[i];
                res[3]=yy[i];
            }
            if(xx[i]==minValue)
            {
                res[0]=xx[i];
                res[1]=yy[i];
            }
        }
        return res;
        
    }
};
```