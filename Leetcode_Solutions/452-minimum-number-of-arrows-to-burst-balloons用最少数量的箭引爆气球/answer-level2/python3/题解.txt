### 解题思路
每个气球都要被枪毙，所以让气球一个一个排队枪毙（此处使用排序）。被一枪多枪毙一个气球都是为国家省一颗子弹，所以尽量一枪多毙（看看有没有和这个气球重复的）。既然我们排好了队，那就不用担心前面的没被枪毙，只要比较后面的，或者被自身覆盖等着加急的（这里两种情况都显示气球结束的点才是我们重视的点，所以我们修改排序方式为按照气球结束的点排序）。为了一枪多毙，我们要确保正在准备被枪毙的气球的结束点大于后一个气球的开始点。我们用count来计算为国家省了多少子弹，用len来计算原本要多少子弹。两者一减就是我们实际用的子弹。按照上述方法我们能多快好省的枪毙气球：）

### 代码

```python3
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        len_p=len(points)
        if len_p == 0:
            return 0
        points.sort(key=lambda x:x[1])
        end=points[0][1]
        count=0
        for n in range(1,len_p):
            if end >= points[n][0]:
                count += 1
            else:
                end = points[n][1]
        return len_p-count
```