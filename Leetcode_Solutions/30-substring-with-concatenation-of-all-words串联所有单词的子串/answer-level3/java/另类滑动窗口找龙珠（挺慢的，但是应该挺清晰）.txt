```
public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> li = new ArrayList<Integer>(); // 返回值
        if (words == null) return li; // 判空
        int wc = words.length;
        if ( wc < 1) return li; // 判空
        int l = words[0].length();
        int lc = wc * l; // 计算总长
        if (s.length() < l) return li;
        HashMap<String, Integer> m = ini(words); // 用于记录每个龙珠中出现次数（负的），随着记录改变
        HashMap<String, Integer> n = cp(m); // 用于记录每个龙珠中出现次数（负的），用于复原
        HashMap<String, Integer> b = new HashMap<String, Integer>(); // 记录龙珠首次出现位置

        // i扫描游标，j记录找到龙珠的初始位置，k记录找到龙珠数
        for (int i = 0, j = -1, k = 0; i <= s.length() - l; ) {
            if (j == -1 && s.length() - i < lc) break; // 对于不足长，而且还没开始凑龙珠的，不凑了
            String focusStr = s.substring(i, i + l);
            Integer focusStrC = m.get(focusStr);
            if (focusStrC == null) { // 不在m中
                if (j == -1) {
                    i++;
                } else {
                    i = j + 1;
                    m = cp(n);
                    b = new HashMap<String, Integer>();
                    j = -1;
                    k = 0;
                }
            } else {
                Integer initB = b.get(focusStr); // 首次看到这个龙珠的位置
                if (initB == null) { // 之前没出现过这颗龙珠
                    b.put(focusStr, i); // 记录首次出现为止
                    m.put(focusStr, focusStrC + 1);
                    if (j == -1) j = i;
                    i += l;
                    k++;
                } else if (focusStrC + 1 > 0) { // 这颗龙珠出现次数超了，这里我们不在j开始，从j到initB已经没有意义了
                    i = initB + 1;
                    j = -1;
                    m = cp(n);
                    b = new HashMap<String, Integer>();
                    k = 0;
                } else { // 之前出现过这颗龙珠，而且没超
                    m.put(focusStr, focusStrC + 1);
                    i += l;
                    k++;
                }
                if (k == words.length) { // 凑满了龙珠
                    i = j + 1;
                    li.add(j);
                    j = -1;
                    k = 0;
                    m = cp(n);
                    b = new HashMap<String, Integer>();
                }
            }
        }
        return li;
    }

    public HashMap<String, Integer> ini(String[] words) {
        HashMap<String, Integer> m = new HashMap<String, Integer>();
        for (int i = 0; i < words.length; i++) {
            String w = words[i];
            Integer n = m.get(w);
            int a = (n == null ? -1 : n - 1);
            m.put(w, a);
        }
        return m;
    }
    public HashMap<String, Integer> cp(HashMap<String, Integer> m) {
        HashMap<String, Integer> n = new HashMap<String, Integer>();
        m.forEach((k, v) -> {
            n.put(k, v);
        });
        return n;
    }
```
