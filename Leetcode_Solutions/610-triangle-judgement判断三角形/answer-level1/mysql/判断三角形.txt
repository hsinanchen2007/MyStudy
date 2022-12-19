__方法__

  判断两条线段长度的和是否大于第三条线段长度

__算法__

  要求x+y>z ； x+z>y ； y+z>x 三个式子都符合就能构成三角形

```
select *, if(x+y>z and x+z>y and y+z>x, 'Yes', 'No') as triangle 
from triangle;
```