rec1 与 rec2 不重叠的情况有以下4种：

rec1 = [x1,y1,x2,y2]
rec2 = [a1,b1,a2,b2]

- rec1在rec2左边，不重叠时，rec1右上角的点[x2,y2] 小于rec2左下角的点[a1,b1]

- rec1在rec2右边，不重叠时，rec1左下角的点[x1,y1] 大于rec2右下角的点[a2,b2]


```js
var isRectangleOverlap = function(rec1, rec2) {
    
    return !(rec2[0] >= rec1[2] || rec2[1] >= rec1[3] || rec2[2] <= rec1[0] || rec2[3] <= rec1[1]);
    
};
```