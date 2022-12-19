list保存每个区间，偶数保存下界，奇数保存上界。
如果输入恰好等于上下界，或者插入点为上界，则不用操作，否则判断插入点前后的数执行相应操作。
```java
class SummaryRanges {

        List<Integer> list;

        public SummaryRanges() {
            list = new ArrayList<>();
        }

        public void addNum(int val) {
            if (list.size() == 0) {
                list.add(val);
                list.add(val);
                return;
            }
            int index = Arrays.binarySearch(list.toArray(), val);
            if (index < 0) {
                index = -index - 1;
                if (index % 2 == 0) {
                    if (index == 0) {
                        if (val == list.get(0) - 1) list.set(0, val);
                        else {
                            list.add(0, val);
                            list.add(0, val);
                        }
                    } else if (index == list.size()) {
                        if (val == list.get(list.size() - 1) + 1) list.set(list.size() - 1, val);
                        else {
                            list.add(list.size(), val);
                            list.add(list.size(), val);
                        }
                    } else {
                        if (val == list.get(index) - 1) {
                            if (val == list.get(index - 1) + 1) {
                                list.remove(index);
                                list.remove(index - 1);
                            } else list.set(index, val);
                        } else {
                            if (val != list.get(index - 1) + 1) {
                                list.add(index, val);
                                list.add(index, val);
                            } else list.set(index - 1, val);
                        }
                    }
                }
            }
        }

        public int[][] getIntervals() {
            int[][] res = new int[list.size() / 2][2];
            for (int i = 0; i < list.size(); i++) {
                res[i / 2][i % 2] = list.get(i);
            }
            return res;
        }
    }
```
