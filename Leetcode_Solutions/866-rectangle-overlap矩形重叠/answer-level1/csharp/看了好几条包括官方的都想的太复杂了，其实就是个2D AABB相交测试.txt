AABB相交测试的规则就一条，对于测试的双方都是： min < max
对于本题来说：矩形 rec 的最小点是 (rec[0],rec[1]), 最大点是(rec[2],rec[3])
如果rec1,rec2相交，那么最小点无论怎么移动都不能大于对方的最大点，这个条件对于双方都必须同时成立，因此一句话就可以完成检测：

public class Solution {
    public bool IsRectangleOverlap(int[] rec1, int[] rec2) {
        return rec2[0]<rec1[2] && rec2[1]<rec1[3]
         && rec1[0]<rec2[2] && rec1[1]<rec2[3];
    }
}

其实官方的解法一，进行逻辑运算后是一样的