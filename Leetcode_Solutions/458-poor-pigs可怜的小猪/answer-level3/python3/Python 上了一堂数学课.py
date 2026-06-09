
![image.png](https://pic.leetcode-cn.com/8942648ef76b2bf34bcb7cf8bc1c888a2cb57fb96467a43ff7a7292201bf865e-image.png)



```

'''
上了一堂数学课
每只猪可以参与的实验次数是 n次 minutesToTest // minutesToDie 次
也就是每只猪可以喂水n次
如果只有一只猪，n次喂水可以验证n+1个桶，前n个如果出现猪死了，马上可以知道谁有毒，如果都没死，那一定最后一个有毒
如果有两只猪，可以验证(n+1)*(n+1)个桶，把这些桶分成n+1行，n+1列，第一只猪每次喝一行水，第二只猪每次喝一列水
最后一定能知道有毒的水在哪一行和哪一列，
有三只猪就可以验证(n+1) ** 3 个桶

依次类推，最后就是求x 让 (n+1)^x >= buckets

'''

class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        n = minutesToTest // minutesToDie
        sum = 1
        x = 0
        while True:
            if sum >= buckets:
                break
            x += 1
            sum *= (n+1)
        return x
```
