### 解题思路
总体的思路：求出总面积再减去各个元素之和即为结果答案。
具体步骤：
    1. 从左开始找到最左侧的最大值first（不清楚有几个最大值），并在遍历中计算除去雨水所有的面积（数组中各个元素之和）。
    2. 将数组由最大值的坐标氛分为左右两个部分，分别计算总面积size。
        2.1 从左开始，递增则将该元素的高度加入总和；递减则将小于开始元素的高度全都置为开始元素的高度，并将指针指向的元素数据加入size
        2.2 从右开始，做法与从左开始基本相同。不同的地方在于，如果能在右侧找到与max值相同的元素，则它与max之间的面积就无需统计了，中间的面积就是max*两点之间距离。
    3. 循环结束后计算包含雨水的总面积为 size + (last - first + 1) * height[first]。
    4. 返回结果 size - sum。
---------------------------
![WX20200404-230511@2x.png](https://pic.leetcode-cn.com/716205227dc2f7395b1cd79f8f530172d8b60922ef003a2b7eba9f68f5425098-WX20200404-230511@2x.png)
---------------------------

### 代码

```java
class Solution {
    public int trap(int[] height) {
        if (height.length==0) return 0;
        int max = 0;
        int first = 0;
        int sum = 0;//除去雨水所有的面积
        for (int i = 0; i < height.length; i++) {
            sum += height[i];//统计所有元素的总和
            if (height[i] > max) {
                max = height[i];
                first = i;//找到最左侧的最高点
            }
        }

        int size = 0;
        //由开始向最高点
        for (int i = 0; i < first; ) {
            if (height[i] <= height[i + 1]) {
                size += height[i];//递增则将该元素的高度加入总和
                i++;//移动指针
            } else {
                int now = height[i];
                while (height[i] > height[i + 1]) {//递减则将小于开始元素的高度全都置为开始元素的高度
                    size += now;
                    i++;
                    height[i] = now;
                }
            }
        }
        //由最后向最高点
        int last = first;//定义另一个最高点的位置
        for (int i = height.length - 1; i > first; ) {
            if (height[i] == max) { //如果从后往前找到同最大值相同的元素，则退出，中间的面积就是max*两点之间距离
                last = i;
                break;
            }
            if (height[i] <= height[i - 1]) {
                size += height[i];
                i--;
            } else {
                int now = height[i];
                while (height[i] > height[i - 1]) {
                    size += now;
                    i--;
                    height[i] = now;
                }
            }
        }
        
        size += (last - first + 1) * height[first];
        return size - sum;
    }
}
```