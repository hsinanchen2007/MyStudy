```
var rec1 = [0, 0, 2, 2],
    rec2 = [1, 1, 3, 3];
var isRectangleOverlap = function (rec1, rec2) {
      if (rec1[2] <= rec2[0] || rec1[0] >= rec2[2]) {
            return false;
        } else {
            if (rec1[3] <= rec2[1] || rec2[3] <= rec1[1]) {
                return false;
            } else {
                return true;
            }
        }
    };
    console.log(isRectangleOverlap(rec1,rec2));
```
用时：52ms

思路：先做一个方向的判断（竖直方向），若直接满足则弹出false，否则的话再做另一个方向的判断。

附加：我总共写了4种方法，发现执行用时的长短主要取决于所用语句的复杂性，而不在于代码量的长短，有位网友用时56ms，只用了最简单的判断和比较。