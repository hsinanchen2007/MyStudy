思路：分治法，第一个下标座位有人坐和没人坐两种情况考虑。最后一个位置要判断是否有人坐。
代码：
```
class Solution {
    public int maxDistToClosest(int[] seats) {
        if (seats.length <= 1) {
            return 0;
        }
        ArrayList<Integer> list = new ArrayList<>();
        int book = seats[0];
        int j = 0;
        if (book == 0) {
           Boolean flag = false;
            for (int i = 1; i < seats.length; i++) {
                    if (flag == false) {
                        if (seats[i] == 1) {
                            list.add(i - j);
                            j = i;
                            flag = true;
                        }
                    } else {
                        if (i == seats.length - 1) {
                            if (seats[i] == 0) {
                                list.add((i - j));
                            } else if (seats[i] == 1) {
                                list.add((i - j) / 2);
                            }
                        } else {
                            if (seats[i] == 1) {
                                list.add((i - j) / 2);
                                j = i;
                            }
                        }
                    }

            }
        } else if (book == 1) {
            for (int i = 1; i < seats.length; i++) {
                if (i == seats.length - 1) {
                    if (seats[i] == 0) {
                        list.add((i - j));
                    } else if (seats[i] == 1) {
                        list.add((i - j) / 2);
                    }
                } else if (seats[i] == 1) {
                    list.add((i - j) / 2);
                    j = i;
                }
            }
        }
        Collections.sort(list);
        System.out.println(list);
        if (list.size() > 0) {
            return list.get(list.size()-1);
        }
        return 0;
    }
}
```
