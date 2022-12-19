 

### 解题思路
三角形自顶向下移动，

1、第n层的边界元素 （最左边 or 最右边）只需要与上一层的边界元素相加即可。

2、第n层其他元素的路径分析：
    在第n层的i个元素可能由有n-1层的第i个或者i-1个元素移动过来
    为了取最小路径，需取i或者i-1最小值。将i或i-1与第n层的i相加

3、如此递归

![image.png](https://pic.leetcode-cn.com/0bf895f0b379aa941c4fd7710b556592282585be32cfd46e28cd65e7f1be8ed7-image.png) 
### 代码

```java

class Solution {
     private static int depth, size;
    private  static int currentMin, tmpValue;

    public static  int minimumTotal(List<List<Integer>> triangle) {
        depth = triangle.size();
        currentMin = triangle.get(0).get(0);
        helper(triangle, 1);
        return currentMin;
    }

    private static  void helper(List<List<Integer>> triangle, int level) {
        if(level >= depth) {
            return;
        }
        int minLevel= Integer.MIN_VALUE;

        // 遍历当前层
        for (int i = 0; i < triangle.get(level).size(); i++) {
            size = triangle.get(level).size();
            if(i == 0 || i == size -1) {
                int topLevelSize = triangle.get(level -1).size();
                tmpValue = (i == 0)?triangle.get(level).get(0) + triangle.get(level -1).get(0):
                                    triangle.get(level).get(i) + triangle.get(level - 1).get(topLevelSize -1);
                triangle.get(level).set(i, tmpValue);
            } else {
                tmpValue = Math.min(triangle.get(level - 1).get(i - 1), triangle.get(level - 1).get(i));
                tmpValue += triangle.get(level).get(i);
                triangle.get(level).set(i, tmpValue);
            }
            minLevel = Math.min(minLevel, tmpValue);
        }

        currentMin = minLevel;
        helper(triangle, level +1);
    }
}
```