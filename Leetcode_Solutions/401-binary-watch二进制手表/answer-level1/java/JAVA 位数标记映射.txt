思路：先统计小时和分钟对应二进制位为1的个数，放入map中，然后根据分钟和小时对应位数之和来判断取值结果
```
public List<String> readBinaryWatch(int num) {
        List<String> list = new ArrayList<String>();
        Map<Integer, List<Integer>> hoursMap = getMap(12);
        Map<Integer, List<Integer>> minuteMap = getMap(60);
        int n = Math.min(hoursMap.size(), num);
        for (int i = 0; i <= n; i++) {
            if (hoursMap.containsKey(i) && minuteMap.containsKey(num - i)) {
                for (Integer hours : hoursMap.get(i)) {
                    for (Integer minute : minuteMap.get(num - i)) {
                        list.add(hours + ":" + (minute < 10 ? "0" + minute : minute));
                    }
                }
            }
        }
        return list;
    }

    private Map<Integer, List<Integer>> getMap(int num) {
        Map<Integer, List<Integer>> map = new HashMap<Integer, List<Integer>>();
        int i = 0;
        while (i < num) {
            int count = 0;
            int n = i;
            while (n != 0) {
                n &= n - 1;
                count++;
            }
            List<Integer> list = map.containsKey(count) ? map.get(count) : new ArrayList<Integer>();
            list.add(i);
            map.put(count, list);
            i++;
        }
        return map;
    }
```
