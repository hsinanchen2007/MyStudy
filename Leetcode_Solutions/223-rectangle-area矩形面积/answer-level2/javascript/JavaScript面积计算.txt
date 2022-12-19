```
/**
 * @param {number} A
 * @param {number} B
 * @param {number} C
 * @param {number} D
 * @param {number} E
 * @param {number} F
 * @param {number} G
 * @param {number} H
 * @return {number}
 */
var computeArea = function (A, B, C, D, E, F, G, H) {
    var coverRecXLen = (C - A + G - E - (G > C ? G : C) + (A < E ? A : E)) //重合矩形宽度
    var coverRecYLen = (D - B + H - F - (D > H ? D : H) + (B < F ? B : F)) //重合矩形高度
    return (C - A) * (D - B) + (G - E) * (H - F)
        - (coverRecXLen > 0 && coverRecYLen > 0 ? coverRecXLen * coverRecYLen : 0)  //有重合则减去重合面积
};

```
