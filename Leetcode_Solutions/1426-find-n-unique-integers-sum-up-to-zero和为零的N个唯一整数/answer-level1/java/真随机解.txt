
```
public int[] sumZero(int n) {
        int res[] = new int[n];
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 1; i <= n / 2; i++) {
            list.add(-i);
            list.add(i);
        }
        if(n % 2 == 1) list.add(0);
        Collections.shuffle(list);
        for (int i = 0; i < res.length; i++) {
            res[i] = list.get(i);
        }
        return res;
    }

```
