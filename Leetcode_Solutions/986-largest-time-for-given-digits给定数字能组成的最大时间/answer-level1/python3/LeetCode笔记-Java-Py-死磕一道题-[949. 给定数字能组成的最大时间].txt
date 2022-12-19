##### 方法1：暴力排列
- 索引
    - `i,j,m,n`表示的是`23:41`的索引，从`[0,1,2,3]` 索引和为`6`，这是 `int n = 6 - i - j - m;`的缘故
    - 因为索引没每一个位置只能有一个，如果`i`占了`0`位置，那么 j,m,n就不能占用`0`位置了，这是 `j != i`     和` m != j && m != i `控制条件的原因
- 控制最大值
    - 因为时间的格式是以`60`为递进单位的，每次比较值的时候可以用整数值比较，控制好边界`：hour < 24 && min < 60`
    - 返回的时候，注意下即可
```javas []
public String largestTimeFromDigits(int[] A) {
    int res = -1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j != i) {
                for (int m = 0; m < 4; m++) {
                    if (m != j && m != i) {
                        int n = 6 - i - j - m;
                        System.out.println(String.format("i:%d,j:%d,m:%d,n:%d", i, j, m, n));
                        int hour = 10 * A[i] + A[j];
                        int min = 10 * A[m] + A[n];
                        if (hour < 24 && min < 60) {
                            res = Math.max(res, hour * 60 + min);
                        }
                    }
                }
            }
        }
    }
    return res >= 0 ? String.format("%02d:%02d", res / 60, res % 60) : "";
```
```python []
print('Hello world!')
```





##### 方法2：DFS，Backtracing
- 初始化
    - `int[] max = {2, 3, 5, 9};` 最大数组，很好理解
    - `res` 结果集
    - `int[] cur = new int[4];` 都置为`-1` 后续`dfs`时可以调整，以区别
- `helper(int[] A, boolean[] used, int[] cur, int index)` 准备这个辅助函数，A是源数组，`used[i]` 表示 `A[i]`是否被使用过，`cur`是当前生成的数组，`index`表示游走的数组的当前位置，不超过`4`
- 退出条件
`index`最大到4，索引是 `0,1,2,3` 如`23:45`，退出条件时有个收集最优解的控制条件 
```
 if (res == null || res.compareTo(tmp) < 0) {
                res = tmp;
            }

```

- 剪枝
    - 第一个`if`条件排除这种情况 `{0,1}[9]:23`,当第一位是`0`时，第二位最多不能超过`9`
    - 第二个`elif` 条件排除的是`{2}[3]:47`,当第一位是`2`时，第二位最多不能超过`3`，最大值是`23:59`,这个条件不写，试下`//[1,2,3,4] 24:31` 这个例子

```
if (index == 1) {
            if (cur[0] == 0 || cur[0] == 1) max[1] = 9;
            else if (cur[0] == 2) max[1] = 3;//[1,2,3,4] 24:31
        }


```

代码
```java []
String res;
    int[] max = {2, 3, 5, 9};

    public String largestTimeFromDigits(int[] A) {
        int[] cur = new int[4];
        Arrays.fill(cur, -1);
        helper(A, new boolean[4], cur, 0);
        return res == null ? "" : res;
    }

    /**
     * @param A     数组
     * @param used  A[i]元素是否被使用过
     * @param cur   当前组成的结果集
     * @param index cur的索引
     */
    public void helper(int[] A, boolean[] used, int[] cur, int index) {
        if (index == 4) {
            String tmp = "" + cur[0] + cur[1] + ":" + cur[2] + cur[3];
//            System.out.println(tmp);
            if (res == null || res.compareTo(tmp) < 0) {
                res = tmp;
            }
            return;
        }

        if (index == 1) {
            if (cur[0] == 0 || cur[0] == 1) max[1] = 9;
            else if (cur[0] == 2) max[1] = 3;//[1,2,3,4] 24:31
        }
        for (int i = 0; i < 4; i++) {
            if (used[i] || A[i] > max[index]) continue;
            cur[index] = A[i];
            used[i] = true;
            helper(A, used, cur, index + 1);
            cur[index] = -1;
            used[i] = false;
        }

    }
```
```python []
print('Hello world!')
```

