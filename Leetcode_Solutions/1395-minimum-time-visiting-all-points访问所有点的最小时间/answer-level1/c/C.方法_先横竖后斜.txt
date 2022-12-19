### 解题思路
1.把问题看成分析两点之间的距离的关系
2.两点的x值有一个距离，y值有一个距离
3.因为只能竖着横着或者斜着走，故最佳行走方式即为
  (1).若两点x轴距离大于y轴距离，就先横着走，直到xy距离两者相等
  (2).若两点y轴距离大于x轴距离，就先竖着走，直到xy距离两者相等 
4.xy距离相等，直接斜着走，此时距离即为x或y轴距离，直接相加即可

### 代码

```c
int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize){
   int sum=0;//总和
   int a,b;//两点x、y距离
   for(int i=0;i<pointsSize-1;i++){
       a=abs(points[i][0]-points[i+1][0]);
       b=abs(points[i][1]-points[i+1][1]);
       sum+=abs(a-b);
       if(a>b) sum+=b;
       else sum+=a;
   }
   *pointsColSize=sum;
   return sum;
}
```