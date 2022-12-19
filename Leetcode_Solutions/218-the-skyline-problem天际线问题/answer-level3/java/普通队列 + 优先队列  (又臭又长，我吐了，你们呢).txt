# 思路
- 普通队列队列记录下一个建筑的侧边（可能是左边👈也可能是右边👉），优先队列（也就是堆）记录下一下看到的建筑的高度。
- 效率和内存占用还行：
![image.png](https://pic.leetcode-cn.com/599a8ea9e64c3f12daed22812f1484bc86f96e8e8394f6512aa37f7c4e2281df-image.png)

# 代码
```java
    static class High{
        int high;
        int expaired;

        public High(int high, int expaired) {
            this.high = high;
            this.expaired = expaired;
        }
    }

    public List<List<Integer>> getSkyline(int[][] buildings) {
        int i = 0, len = buildings.length;
        List<List<Integer>> ans = new ArrayList<>();
        if (len == 0) return ans;
        Queue<High> high = new PriorityQueue<>((h1, h2) -> (h2.high - h1.high) == 0 ? h1.expaired - h2.expaired : (h2.high - h1.high));
        Queue<Integer> curq = new PriorityQueue<>();
        int cur;
        High nowHigh = null;
        while (i < len){
            int[] item = buildings[i];
            boolean changed = false;
            if (curq.size() > 0 && curq.peek() < item[0]){
                cur = curq.poll();
                if (nowHigh.expaired <= cur){
                    if (high.size() > 0) nowHigh = high.poll();
                    while (nowHigh != null && nowHigh.expaired <= cur) nowHigh = high.poll();
                    changed = true;
                }
            }else {
                cur = item[0];
                curq.add(item[1]);
                if (nowHigh != null && nowHigh.high < item[2]){
                    if (nowHigh.expaired > cur) high.add(nowHigh);
                    nowHigh = new High(item[2], item[1]);
                    changed = true;
                }else high.add(new High(item[2], item[1]));
                i++;
            }

            while (!changed && (nowHigh == null || nowHigh.expaired <= cur) && high.size() > 0){
                nowHigh = high.poll();
                changed = true;
            }
            if (changed) {
                if (ans.size() > 0 && ans.get(ans.size() - 1).get(1) == (nowHigh == null ? 0: nowHigh.high)) continue;
                if (ans.size() > 0 && ans.get(ans.size() - 1).get(0) == cur) ans.remove(ans.size() - 1);
                ans.add(Arrays.asList(cur, nowHigh == null ? 0 : nowHigh.high));
            }
        }
        while (high.size() > 0 && nowHigh != null){
            if (ans.size() > 0 && ans.get(ans.size() - 1).get(0) == nowHigh.expaired) ans.remove(ans.size() - 1);
            if (high.size() > 0 && high.peek().expaired <= nowHigh.expaired){
                high.poll();
                continue;
            }
            List<Integer> list = new ArrayList<>();
            list.add(nowHigh.expaired);
            nowHigh = high.poll();
            list.add(nowHigh.high);
            if (ans.size() > 0 && ans.get(ans.size() - 1).get(1) == nowHigh.high) continue;
            ans.add(list);
        }
        if (ans.size() > 0 && ans.get(ans.size() - 1).get(1) == 0) return ans;
        if (ans.size() > 0 && ans.get(ans.size() - 1).get(0) == nowHigh.expaired) ans.remove(ans.size() - 1);
        ans.add(Arrays.asList(nowHigh.expaired, 0));
        return ans;
    }
```