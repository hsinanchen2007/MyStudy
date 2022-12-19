```
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if(x_center>=x1 && x_center<=x2&&y_center >= y1&&y_center <= y2)
        {
            //printf("situation1");
            return  true;
        }   
        //在圆心里面，返回true
        else   if((x_center>=x1&&x_center<=x2)||(y_center>=y1&&y_center<=y2))
        {
           //printf("situation2\n");
            if(x_center>=x1&&x_center<=x2)
            {
                if(y_center >= y2)
                {
                    return  (y_center-y2)<=radius;
                }
                else  if(y_center <= y1)
                {
                    return  (y1-y_center)<=radius;
                }
            }
            else  if(y_center>=y1&&y_center<=y2)
            {
                if(x_center<=x1)
                {
                    return  (x1-x_center)<=radius;
                }
                else  if(x_center >=x2)
                {
                    return  (x_center-x2)<=radius;
                }
            }
        }
        //上下左右的四个区域

        else 
        {
            //printf("situation3\n");
            if(x_center<=x1&&y_center>=y2)
            {
                return  (x_center-x1)*(x_center-x1)+(y_center-y2)*(y_center-y2)<=radius*radius;
            }
            //区域6
            else   if(x_center>=x2&&y_center>=y2)
            {
                return  (x_center-x2)*(x_center-x2)+(y_center-y2)*(y_center-y2)<=radius*radius;
            }
            //区域7
            else   if(x_center<=x1&&y_center<=y1)
            {
                return  (x_center-x1)*(x_center-x1)+(y_center-y1)*(y_center-y1)<=radius*radius;
            }
            else
            {
                return  (x_center-x2)*(x_center-x2)+(y_center-y1)*(y_center-y1)<=radius*radius;
            }
        }
        //左上，左下，右上，右下四个区域
        //判断四个边界点是否在圆的内部
        return  false;
    }
};
```
