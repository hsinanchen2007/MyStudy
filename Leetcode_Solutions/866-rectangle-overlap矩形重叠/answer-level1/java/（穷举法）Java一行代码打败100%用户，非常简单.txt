
思路很简单，很好理解，就是用穷举法，把每一种情况的坐标关系都列举出来，然后代码实现值就可以了~

```
package Day45;

/**
 * @Author Zhongger
 * @Description 矩形以列表 [x1, y1, x2, y2] 的形式表示，其中 (x1, y1) 为左下角的坐标，(x2, y2) 是右上角的坐标。
 * 如果相交的面积为正，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。
 * 给出两个矩形，判断它们是否重叠并返回结果。
 * @Date  2020.3.18
 */
public class IsRectangleOverlapSolution {
    public static void main(String[] args) {
        int[] rec1={0,0,1,1};
        int[] rec2={1,0,2,1};
        System.out.println(new IsRectangleOverlapSolution().isRectangleOverlap(rec1, rec2));
    }
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        int ax1=rec1[0],ay1=rec1[1],ax2=rec1[2],ay2=rec1[3]; //第一个矩形
        int bx1=rec2[0],by1=rec2[1],bx2=rec2[2],by2=rec2[3]; //第二个矩形
        if (bx1<=ax1&&by1<=ay1){
            if (bx2>ax1&&by2>ay1){
                return true;
            }else {
                return false;
            }
        }
        if (bx1<=ax1&&by1>ay1&&by1<ay2){
            if (by2>by1&&by2>ay1&&bx2>ax1){
                return true;
            }else {
                return false;
            }
        }
        if (bx1<=ax1&&by1>ay1) {
            return false;
        }
        if (bx1>ax1&&bx1<ax2&&by1<ay1){
            if (bx2>bx1&&by2>=ay1){
                return true;
            }else {
                return false;
            }

        }
        if (bx1>ax1&&bx1<ax2&&by1>ay1&&by2<ay2){
            return true;
        }
        if (bx1>ax1&&bx1<ax2&&by1>=ay2){
            return false;
        }
        if (bx1>=ax2){
            return false;
        }

        return true;
    }

}
```
