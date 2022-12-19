将矩形重叠转化成x,y 轴上的区间重叠
列举出区间没有重叠的情况，再取反就是最后的结果
```
var isRectangleOverlap = function (rec1, rec2) {
    return !(rec1[2] <= rec2[0] || rec2[2] <= rec1[0] || rec1[3] <= rec2[1] || rec2[3] <= rec1[1])
}
```
