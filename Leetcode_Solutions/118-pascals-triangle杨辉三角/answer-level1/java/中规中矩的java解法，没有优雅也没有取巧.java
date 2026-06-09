# 中规中矩的java解法，没有优雅也没有取巧 
集合，一层一层一个一个算
```java []
    public static List<List<Integer>> generate(int numRows) {
        // 初始化返回集合
        List<List<Integer>> xie = new ArrayList<List<Integer>>();
        if (numRows == 0) {
            return xie;
        }

        // 构建集合的第一层
        List<Integer> tmpList_1 = new ArrayList<>();
        tmpList_1.add(0, Integer.valueOf(1));
        xie.add(0, tmpList_1);
        if (numRows == 1) {
            return xie;
        }

        // 构建集合的第二层
        List<Integer> tmpList_2 = new ArrayList<>();
        tmpList_2.add(Integer.valueOf(1));
        tmpList_2.add(Integer.valueOf(1));
        xie.add(tmpList_2);
        if (numRows == 2) {
            return xie;
        }

        // 循环构建后续n层的数据
        for (int i = 2; i < numRows; i++) {
            // 对于每一层数据，借助前一层数据进行构建,其中：第i层游i+1个数据
            List<Integer> tmpList_i = new ArrayList<>();
            // 初始化第一个数
            tmpList_i.add(Integer.valueOf(1));
            for (int j = 1; j < i; j++) {
                tmpList_i.add(xie.get(i-1).get(j-1)+xie.get(i-1).get(j));
                // 如果已到达最后一个数，加一个数1
                if (j==i-1) {
                    tmpList_i.add(Integer.valueOf(1));
                    break;
                }
            }
            xie.add(tmpList_i);
        }
        return xie;
    }
```
