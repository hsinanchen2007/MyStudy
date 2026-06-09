### 解题思路
1.首先根据二维数组中每个一维数组的[0]进行升序排序，即根据start进行排序；
2.合并条件是前一个的结束 大于等于 后一个的开始
3.然后建立linkedList作为中间处理对象，当集合为空或者不满足条件，加入集合的末尾；
4.集合不为空且满足合并条件时，取集合中最后一个元素让它的end为原值和合并区间end中的最大值，解决1,5;2,4这样的区间问题。
5.集合处理完成，对其循环遍历取首元素，放入res结果数组中

### 代码

```java
class Solution {
    public int[][] merge(int[][] arr) {
        Arrays.parallelSort(arr, Comparator.comparingInt(x -> x[0]));

        LinkedList<int[]> list = new LinkedList<>();
        for (int i = 0; i < arr.length; i++) {
            if (list.size() == 0 || list.getLast()[1] < arr[i][0]) {
                list.add(arr[i]);//集合为空，或不满足条件，向后新增
            } else {//满足条件，集合最后元素的end=最大值
                list.getLast()[1] = Math.max(list.getLast()[1], arr[i][1]);
            }
        }
        int[][] res = new int[list.size()][2];//生成结果数组
        int index = 0;
        while (!list.isEmpty()) {//遍历集合
            res[index++] = list.removeFirst();//删除集合首元素
        }
        return res;
    }
}
```