### 题目梳理：
1. 在某一固定位置`index`处倒水
2. 如果左侧有比`index`处低的位置，则水将会流过去
3. 如果右侧有比`index`处低的位置，则水将会流过去
4. 如果两侧都没有比`index`处低的位置，则水将不流动

### 步骤：
1. 从`index`处分成左右两部分进行分治
2. 左侧从`index - 1`处向左查找，记录位置最低处的`lowestIndex`，并将此处的高度+1
3. 右侧从`index + 1`处向右查找，记录位置最低处的`lowestIndex`，并将此处的高低+1
4. 如果两侧都没有找到`lowestIndex`，则在`index`处+1
5. 递归执行


##### P.S. 需要处理存在高墙的特殊场景，示意如下：
```bash
#     #
# #ww #
# ##ww#
#######
 01234
// index = 1处是高度为3的高墙
```
处理的方法是在左右查找的时候，判断`i`处的高度是否大于`index`当前的高度，如果大于则不继续查找。

```java
public class Solution_755 {
    public int[] pourWater(int[] heights, int times, int index) {
        if (times == 0) {
            return heights;
        }
        int leftLowestIndex = getLeftLowestIndex(heights, index);
        if (leftLowestIndex != -1) {
            heights[leftLowestIndex]++;
            return pourWater(heights, times - 1, index);
        }
        int rightLowestIndex = getRightLowestIndex(heights, index);
        if (rightLowestIndex != -1) {
            heights[rightLowestIndex]++;
            return pourWater(heights, times - 1, index);
        }
        heights[index]++;
        return pourWater(heights, times - 1, index);
    }

    private int getLeftLowestIndex(int[] heights, int index) {
        int lowestIndex = -1;
        int height = heights[index];
        for (int i = index - 1; i >= 0; i--) {
            // High wall
            if (heights[i] > height) {
                break;
            }
            if (heights[i] < height) {
                height = heights[i];
                lowestIndex = i;
            }
        }
        return lowestIndex;
    }

    private int getRightLowestIndex(int[] heights, int index) {
        int lowestIndex = -1;
        int height = heights[index];
        for (int i = index + 1; i <= heights.length - 1; i++) {
            // High wall
            if (heights[i] > height) {
                break;
            }
            if (heights[i] < height) {
                height = heights[i];
                lowestIndex = i;
            }
        }
        return lowestIndex;
    }
}
```

