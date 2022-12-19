### 解题思路

### 代码

```java
class Solution {
    /**
    * 分治的思想
    * 与归并排序算法类似，先划分后合并
    * 这个题的一个困难之处在于将输入数据转化为输出数据的格式，
    * 输入数据的格式为[Left,Right,Height],分别表示建筑物的左下角点，右下角点，高度
    * 在这里我们将输入数据处理为[Left,Height],[Right,0]
    * 即一个简单的矩形建筑物可以用左上角点与右下角点所表示，格式与要求的输出格式相同了
    */
    public List<List<Integer>> getSkyline(int[][] buildings) {
        int n = buildings.length;
        List<List<Integer>> output = new ArrayList<List<Integer>>();
        //特殊情况处理
        if (n == 0) return output;
        if (n == 1) {//只有一个矩形建筑物
            int left = buildings[0][0];//左下角点
            int right = buildings[0][1];//右下角点
            int height = buildings[0][2];//高度
            //根据上面的注释所说，将数据处理成输出格式
            output.add(new ArrayList<Integer>() {{add(left); add(height);}});
            output.add(new ArrayList<Integer>() {{add(right); add(0);}});
            return output;
        }

        //将问题划分求解
        List<List<Integer>> leftSkyline = getSkyline(Arrays.copyOfRange(buildings, 0, n / 2));
        List<List<Integer>> rightSkyline = getSkyline(Arrays.copyOfRange(buildings, n / 2, n));

        //将两个问题合并
        return mergeSkylines(leftSkyline, rightSkyline);
    }

    /**
    *  将两个问题合并，按照x轴的大小顺序，排头合并
    */
    public List<List<Integer>> mergeSkylines(List<List<Integer>> left, List<List<Integer>> right) {
        int leftSize = left.size();
        int rightSize = right.size();
        int leftIndex = 0;//记录left中遍历到的位置下标
        int rightIndex = 0;//记录right中遍历到的位置下标
        int curHeight = 0; //当前的建筑物高度
        int leftHeight = 0; //left中的建筑物高度
        int rightHeight = 0;//right中的建筑物高度
        int index;//当前遍历到的x轴的下标位置
        int maxHeight;//当前建筑物的最大高度
        List<List<Integer>> output = new ArrayList<List<Integer>>();

        while ((leftIndex < leftSize) && (rightIndex < rightSize)) {
            List<Integer> pointL = left.get(leftIndex);
            List<Integer> pointR = right.get(rightIndex);
            // 在x轴中寻找index最小的点
            if (pointL.get(0) < pointR.get(0)) {
                index = pointL.get(0);
                leftHeight = pointL.get(1);
                leftIndex++;
            }else {
                index = pointR.get(0);
                rightHeight = pointR.get(1);
                rightIndex++;
            }
            // 求出建筑物的最大高度
            maxHeight = Math.max(leftHeight, rightHeight);
            // 如果当前的高度curHeight与最大高度maxHeight不同，遇到了转折点，证明需要更新结果集了
            if (curHeight != maxHeight) {
                updateOutput(output, index, maxHeight);
                curHeight = maxHeight;
            }
        }

        // 将剩余的left中的数据加入到结果集
        appendSkyline(output, left, leftIndex, leftSize, curHeight);
        // 将剩余的right中的数据加入到结果集
        appendSkyline(output, right, rightIndex, rightSize, curHeight);

        return output;
    }

    /**
    * 更新结果集
    * 这里有两种情况，一种是普通情况的更新结果集
    * 一种是垂直状况的更新结果集，官方题解最后一个图
    */
    public void updateOutput(List<List<Integer>> output, int index, int height) {
        // 普通情况更新结果集
        if (output.isEmpty() || output.get(output.size() - 1).get(0) != index){
            output.add(new ArrayList<Integer>() {{add(index); add(height); }});
        }
        else {// 垂直情况更新结果集
            output.get(output.size() - 1).set(1, height);
        }
    }

    /**
    *  将剩余的skyline中的数据加入到结果集中
    */
    public void appendSkyline(List<List<Integer>> output, List<List<Integer>> skyline,
                                int index, int n, int curHeight) {
        while (index < n) {
            List<Integer> point = skyline.get(index);
            int x = point.get(0);
            int height = point.get(1);
            index++;
            //证明遇到了转折点，更新结果集
            if (curHeight != height) {
                updateOutput(output, x, height);
                curHeight = height;
            }
        }
    }
}
```