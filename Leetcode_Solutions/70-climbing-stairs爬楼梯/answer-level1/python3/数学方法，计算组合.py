![QQ截图20191209212937.png](https://pic.leetcode-cn.com/bbac4c752e71f198cac46a02fd825fb099a74209ef5a01564cf86dbdb1457749-QQ%E6%88%AA%E5%9B%BE20191209212937.png)

思路：用排列组合中计算组合的方法，看爬的序列中有几个2，因为这个2是无序的，所以用组合
```
num = n // 2
        shang = n / 2
        if n == 1:
            return 1
        elif n == 2:
            return 2
        else:
            ways = 1  # 0个2
            ways += (n-1)  # 一个2
            # nums考虑组合式中上标的取值范围
            if num == shang:  # 会出现全为2的情况
                nums = num
                ways += 1  # 全为2时结果加1
            else:
                nums = num + 1
            for i in range(2, nums, 1):  # 计算会存在的组合式
                fenzi = 1  # 分子
                fenmu = 1  # 分母
                for j in range(i):  # 计算分子
                    fenzi *= (n-i-j)
                for j in range(i):  # 计算分母
                    fenmu *= (i-j)
                ways += (fenzi/fenmu)
            return int(ways)
```
