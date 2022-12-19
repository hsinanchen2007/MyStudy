### 解题思路
此处撰写解题思路

### 代码


第一种方法就是排除法：

```golang
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
	// 第一个矩形
	x11, y11 := rec1[0], rec1[1]
	x12, y12 := rec1[2], rec1[3]
	
	// 第二个矩形
	x21, y21 := rec2[0], rec2[1]
	x22, y22 := rec2[2], rec2[3]
	
	// 为了方便起见，这里利用排除法，排除掉不相交的情况
	//case1
	if y11 >= y22 || y12 <= y21  {
		return false
	}

	// case2
	if x12 <= x21 || x22 <= x11 {
		return false
	}

	return true
}
```

第二种就是分析法：

```python
class Solution(object):
    def isRectangleOverlap(self, rec1, rec2):
        """
        :type rec1: List[int]
        :type rec2: List[int]
        :rtype: bool
        """
        if rec1 is None or rec2 is None:
            return False

        if len(rec1) != 4 or len(rec2) != 4 :
            return False

        x11, y11, x12, y12 = rec1[0], rec1[1], rec1[2], rec1[3]
        x21, y21, x22, y22 = rec2[0], rec2[1], rec2[2], rec2[3]

        w1 = abs(x11 - x12)
        h1 = abs(y11 - y12)

        w2 = abs(x21 - x22)
        h2 = abs(y21 - y22)

        w12 = max(abs(x11 - x22), abs(x12 - x21))
        h12 = max(abs(y11 - y22), abs(y12 - y21))

        if w12 < (w1 + w2) and h12 < (h1 + h2):
            return True
        return False
```