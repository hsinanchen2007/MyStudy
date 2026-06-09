```
public class Num657 {

    /**向上*/
    private static final char UP    =  'U';
    /**向下*/
    private static final char DOWN  =  'D';
    /**向左*/
    private static final char LEFT  =  'L';
    /**向右*/
    private static final char RIGHT =  'R';

    public static boolean judgeCircle(String moves) {
        int vertical = 0, level = 0;//各自表示竖直方向、水平方向的位置
        for (char c : moves.toCharArray()) {
            switch (c) {
                case UP ://如果是‘U’，竖直方向加1
                    vertical++;
                    break;//**必须加break，不然就错了（踩坑）**
                case DOWN ://如果是‘D’，竖直方向减1
                    vertical--;
                    break;
                case LEFT ://如果是‘L’，水平方向减1
                    level--;
                    break;
                case RIGHT ://如果是‘R’，水平方向加1
                    level++;
                    break;
            }
        }
        return vertical == 0 && level == 0;//如果竖直方向和水平方向都是0，说明返回了原点
    }
}
```
