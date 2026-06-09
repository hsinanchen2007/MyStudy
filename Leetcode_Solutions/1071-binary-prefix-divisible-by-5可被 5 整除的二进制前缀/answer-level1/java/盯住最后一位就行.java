![image.png](https://pic.leetcode-cn.com/46250960d8adc295805e16ef38f7d2e8696ec7daf9afd80195437dfd8ba58192-image.png)

依次把每个值求和出来是不行的

```
    List<Boolean> res = new ArrayList<Boolean>();
    int tail = 0;
    for(int i: A) {
        tail = tail * 2 + i;
        tail = (tail > 9) ? tail - 10 : tail;
        if(tail == 0 || tail == 5) {
            res.add(true);
        } else {
            res.add(false);
        }
    }
    return res;
```

