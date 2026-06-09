```
public static List<List<Integer>> generate(int numRows) {
        List<List<Integer>> lists = new ArrayList<>();
        if (numRows == 0)
            return lists;
        else {
            for (int i = 0; i < numRows; i++) {
                List<Integer> list = new ArrayList<>();
                for (int j = 0; j <= i; j++) {
                    if (j == 0 || j == i) { // 第一个和最后一个元素为1 
                        list.add(1);
                    } else {
                        List<Integer> preList = lists.get(i - 1); 
                        list.add(preList.get(j) + preList.get(j - 1)); // 每个元素等于前一个list的 j 和 j-1 角标元素值之和
                    }
                }
                lists.add(list);
            }
        }
        return lists;
    }
```