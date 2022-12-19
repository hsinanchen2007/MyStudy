### 解法

```java
public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        if(matrix.length == 0 || matrix[0].length == 0)
            return res;
        int row = matrix.length, col = matrix[0].length;
        for(int i = 0; i < row; i++){
            int colMinIndex = 0; // 找到该行最小的元素的列索引
            for(int j = 1; j < col; j++){
                if(matrix[i][j] < matrix[i][colMinIndex])
                    colMinIndex = j;
            }
            int rowMaxIndex = i;
            for(int j = 0; j < row; j++){
                if(matrix[j][colMinIndex] > matrix[i][colMinIndex]){
                    rowMaxIndex = j;
                    break;
                }
            }
            if(rowMaxIndex == i)
                res.add(matrix[i][colMinIndex]);
        }
        return res;
    }
```

思路分析：

* 仔细看看幸运数的定义，该行最小且为该列最大。
* 每一行肯定能找到一个最小元素，但是它不一定是该列的最大元素，所以当找到某一行的最小元素后还要判断他是不是该行最大元素。由于要找到所有幸运数所以要对每一行都进行一次这样的判断。
* 外循环对每一行进行。首先对当前行进行一次遍历确定行中最小元素的列索引，然后再对该列进行遍历，一旦找到一个比待判断元素大的元素就停止，并且修改`rowMaxIndex`。如果列循环结束没有改变`rowMaxIndex`，则说明它是该列最大的元素，它是一个幸运数。
* 空间复杂度，取决于有多少个幸运数 $O(m)$。时间复杂度，进行了两层遍历，所以为$O(n^2)$。

运行结果：

* 难度 easy  7ms

更多LeetCode题解请看我的[github](https://github.com/ustcyyw/yyw_algorithm)，地址https://github.com/ustcyyw/yyw_algorithm。还有别的小项目也很好玩~卑微求个小星星💖