每个位置的数字信息可以直接通过计算得出，代码如下
```
        int[] numOrder = new int[n + 1];
        numOrder[0] = 0;
        Map<Integer, Integer> fMap = new HashMap<>();
        fMap.put(0, 1);
        List<Integer> list = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            fMap.put(i, fMap.get(i - 1) * i);
            list.add(i);
        }
        for (int i = 1; i <= n; i++) {
            numOrder[i] = ((int) Math.ceil(k / 1.0 / fMap.get(n - i))) % (n - i + 1);
            if (numOrder[i] == 0) {
                numOrder[i] = n - i + 1;
            }
        }
        StringBuffer s = new StringBuffer();
        for (int i = 1; i < n; i++) {
            s.append(list.get(numOrder[i] - 1));
            list.remove(numOrder[i] - 1);
        }
        s.append(list.get(0));
        return s.toString();
```
