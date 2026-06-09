sampling rejection.

![image.png](https://pic.leetcode-cn.com/b068d47f014d55e3e4225594f7bb42e749e367d5b1052aad48d8276d88d8e8dd-image.png)

```
func rand10() int {
    for {
        r1 := rand7()
        r2 := rand7()
        num := r1 + (r2 - 1) * 7
        if num <= 40 {
            return num % 10 + 1
        }
    }
}
```

