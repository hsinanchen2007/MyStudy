![微信图片_20200221001300.png](https://pic.leetcode-cn.com/46713d2b8dc138b817e090ce5d97f9e5daaccbb834a9a32e6134e06b0bb15cc3-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200221001300.png)

# 思路
维护2个HashSet和HashMap即可。
HashMap用于计数，HashSet用于判断是否包含small数组中的数，LinkedList用来记录下标。
有点**滑动窗口**的内味儿。

# 代码
```java
class Solution {
    public int[] shortestSeq(int[] big, int[] small) {
        int b_len = big.length;
        if (b_len < small.length) return new int[0];
        HashSet<Integer> s_set = new HashSet<>(small.length), b_set = new HashSet<>(small.length);
        HashMap<Integer, Integer> map = new HashMap<>(small.length);
        LinkedList<Integer> idx_list = new LinkedList<>();
        for (int num : small)
            s_set.add(num);
        int res = Integer.MAX_VALUE, begin = -1, end = -1;
        for (int i = 0; i < b_len; ++i) {
            if (s_set.contains(big[i])) {
                idx_list.addLast(i);
                b_set.add(big[i]);
                map.merge(big[i], 1, (old_val, new_val) -> old_val + new_val);
                if (b_set.size() == s_set.size()) {
                    int idx;
                    while (true) {
                        idx = idx_list.removeFirst();
                        int val = map.get(big[idx]) - 1;
                        map.put(big[idx], val);
                        if (val == 0) {
                            b_set.remove(big[idx]);
                            break;
                        }
                    }
                    if (res > i - idx + 1) {
                        res = i - idx + 1;
                        begin = idx;
                        end = i;
                    }
                }
            }
        }
        return begin < 0 ? new int[0] : new int[]{begin, end};
    }
}
```
