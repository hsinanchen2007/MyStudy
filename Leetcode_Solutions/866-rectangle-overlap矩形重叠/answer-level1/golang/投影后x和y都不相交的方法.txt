### 解题思路

无非就投影到x上后
rec1_x1 >= rec2_x2就绝对不相交，把四种情况理清楚，如下。
### 代码

```golang
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
    // x上不相交
    if (rec1[2] <= rec2[0] )|| (rec1[0] >= rec2[2]){
        return false
    }
    // y上不相交
    if (rec1[1] >= rec2[3]) || (rec1[3] <= rec2[1]){
        return false;
    }
    return true;
}


```