**解题思路**

先将会议时间按照先后顺序排序，，那么预设房间数等于初始会议时间的数量。
然后比较各个会议结束和开始时间，判断某个会议结束后是否还有没开始的会议，
如果有就让出房间，后续会议继续使用当前房间，以此类推最终得到至少需要的房间数。

```javascript
var minMeetingRooms = function(intervals) {
    if (!intervals.length) return 0;
    var rooms = intervals.sort((a, b) => a[0] - b[0]);
    for (let i = 1; i < rooms.length; i++) {
        const eleI = rooms[i];
        for (let j = 0; j < i; j++) {
            const eleJ = rooms[j];
            if (eleJ[1] <= eleI[0]) {
                rooms.splice(j, 1);
                eleI[0] = 0;
                i--;
            }
        }
    }
    return rooms.length;
};
```
如有更好的解决方法，欢迎讨论。



