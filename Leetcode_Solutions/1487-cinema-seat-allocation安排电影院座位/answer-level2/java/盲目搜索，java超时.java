```
import java.util.*;

/**
 * 48 / 53 个通过测试用例
 * 状态：超出时间限制
 * 提交时间：1 分钟之前
 */
class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for (int a[] : reservedSeats) {
            if (!map.containsKey(a[0])) {
                map.put(a[0], new HashSet<>());
            }
            map.get(a[0]).add(a[1]);
        }
        int rst = 0;
        for (int i = 1; i <= n; ++i) {
            Set list = map.get(i);
            if (null == list) {
                rst += 2;
                continue;
            }
            if (list.contains(4) || list.contains(5)) {
                if (!list.contains(6) && !list.contains(7) && !list.contains(8) && !list.contains(9)) {
                    rst += 1;
                }
            } else if (list.contains(6) || list.contains(7)) {
                if (!list.contains(2) && !list.contains(3) && !list.contains(4) && !list.contains(5)) {
                    rst += 1;
                }
                // 4 5  6 7都不包含至少可以放下一个家庭，试着寻求放入两个家庭
            } else if (list.contains(2) || list.contains(3) || list.contains(8) || list.contains(9)) {
                //2 3 8 9 有一个位置被占用，不着放下两个
                rst += 1;
            } else if (list.contains(1) || list.contains(10)) {
                rst += 2;
            }
        }
        return rst;
    }
}
```
