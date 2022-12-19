### 解题思路
先把people数组按k大小排序，相同k的值按h值大小排序。然后依次放入一个整数对，并插入对应位置。

### 代码

```java
class Solution {
    public int[][] reconstructQueue(int[][] people) {
        int[][] res = new int[people.length][2];
        if (people == null || people.length == 0) {
            return res;
        }
        Arrays.sort(people, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[1] != o2[1]) {
                    return o1[1] - o2[1];
                }
                return o1[0] - o2[0];
            }
        });
        res[0] = people[0];
        for (int i = 1; i < people.length; i++) {
            int count = 0;
            int index = 0;
            for (int j = 0; j < i; j++) {
                if (res[j][0] >= people[i][0]) {
                    count++;
                }
                if (count == people[i][1]) {
                    index = j;
                }
            }
            if (index == i - 1) {//插入末尾
                res[i] = people[i];
            } else {//插在中间
                for (int k = i; k > index + 1; k--) {
                    res[k] = res[k - 1];
                }
                res[index + 1] = people[i];
            }
        }
        return res;
    }
}
```