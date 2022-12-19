### 解题思路
此处撰写解题思路
通过中点坐标公式，得出两个矩形的中点；
如果两矩形重叠则有，两中点横坐标距离和纵坐标距离分别均小于两矩形长与宽之和的一半；
反之则没有重叠
### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size)
{
    float a,b,c,d,t1,t2;
    float e,f,g,h,z1,z2;
    a=fabs(rec1[0]-rec1[2])/2.0;
    b=fabs(rec1[3]-rec1[1])/2.0;
    c=fabs(rec2[0]-rec2[2])/2.0;
    d=fabs(rec2[3]-rec2[1])/2.0;

    t1=(c+a);
    t2=(b+d);

    e=(rec1[0]+rec1[2])/2.0;
    f=(rec1[3]+rec1[1])/2.0;
    g=(rec2[0]+rec2[2])/2.0;
    h=(rec2[3]+rec2[1])/2.0;

    z1=fabs(g-e);
    z2=fabs(h-f);

if(z2>=t2||z1>=t1)
 return false;
//if(a==0||b==0||c==0||d==0)
 //return true;
 
 return true;
}
```