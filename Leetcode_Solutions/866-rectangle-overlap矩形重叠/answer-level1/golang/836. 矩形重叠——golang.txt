### 解题思路
此处撰写解题思路
本题思路很简单。可以分为以下几种情况：
1. 如果rec2的最右边在rec1的最左边的左边，返回false。
2. 如果rec2的最左边在rec1的最右边的右边，返回false。
3. 如果rec2的最下边在rec1的最上边的上面，返回false。 
4. 如果rec2的最上边在rec1的最下边的下面，返回false。 


### 代码

```golang
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
    if rec2[2]<=rec1[0]||rec2[0]>=rec1[2]||rec2[1]>=rec1[3]||rec2[3]<=rec1[1]{
        return false
    }
    return true
}
```