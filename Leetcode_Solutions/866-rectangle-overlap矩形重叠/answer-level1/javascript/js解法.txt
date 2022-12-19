```
/**
 * @param {number[]} rec1
 * @param {number[]} rec2
 * @return {boolean}
 */
var isRectangleOverlap = function(rec1, rec2) {
    // 也就是两个矩形的x轴各自较后的哪个点中较小的那个都比各自靠前的两个点中较大的那个大
    // 且y轴同理
    return ( (Math.min(rec1[2],rec2[2])>Math.max(rec1[0],rec2[0]))
            &&(Math.min(rec1[3],rec2[3])>Math.max(rec1[1],rec2[1])) )
};
```
