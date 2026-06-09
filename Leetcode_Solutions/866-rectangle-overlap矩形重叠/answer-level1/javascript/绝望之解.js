```javascript
/**
 * @param {number[]} rec1
 * @param {number[]} rec2
 * @return {boolean}
 */
var isRectangleOverlap = function(rec1, rec2) {
    // 情况一: rec1 在 rec2中
    // 情况二: rec1 包含 rec2
    // 情况三: rec1 与 rec2交叉
    // 取四个点
    let ax = rec1[0], ay = rec1[1];
    let bx = rec1[2], by = rec1[3];
    let cx = rec2[0], cy = rec2[1];
    let dx = rec2[2], dy = rec2[3];

    if(ax === bx || ay === by || cx === dx || cy === dy) {
        return false;
    }

    if(cx < ax && ax < dx && cy < by && by <= dy && dy > cy) { //情况一: rec1 在 rec2中
        return true;
    } else if(ax < cx && cx < bx && cy < dy && dy <= by && dy > ay) { //情况二: rec1 包含 rec2
        return true;
    } else if(ax < dx && cx > ax && cx < bx && by > cy && by < dy) { // 情况三: rec1 与 rec2交叉
        return true;
    } else if(cx < bx && cx < ax && ax < dx && dy > ay && dy < by) { // 情况三: rec1 与 rec2交叉
        return true;
    } else if(cx >= ax && cy < ay && dy > ay && bx > cx) { // 情况三: rec1 与 rec2交叉
        return true;
    } else if(ax >= cx && ay < cy && by > cy && dx > ax) { // 情况三: rec1 与 rec2交叉
        return true;
    } else {
        return false;
    }
};
```
