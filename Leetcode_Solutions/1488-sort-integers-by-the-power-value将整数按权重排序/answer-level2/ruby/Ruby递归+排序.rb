### 解题思路
竞赛代码，未必最优化，请多多包涵。

权值用递归实现。
递推的结束条件为`x == 1`
题目已经给出了递推公式，最终需要的是“步数”，因此每次递归+1即可。
为了避免子问题的重复计算，用哈希@dp存储中间过程的结果。
```ruby
def weight(x)
  return 0 if x == 1
  @dp ||= {}
  @dp[x] ||= 1 + (x.odd? ? weight(x * 3 + 1) : weight(x / 2))
end
```

用数组a存储从[lo, hi]映射出的数组[x, weight(x)]
```ruby
a = []
(lo..hi).each{|x| a << [x, weight(x)]}
```

`a.sort{|x, y| (x[1] <=> y[1]) == 0 ? x[0] <=> y[0] : x[1] <=> y[1] }`
随后用自己定义的排序方法对a排序：
先以两个数的权重为判断依据，当权重相等时再判断两个数本身。

`a.sort{...}[k-1][0]`
排序后取第k个元素（下标为k-1），再对元素调用[0]拆数组得到最终值。

### 代码

```ruby
def get_kth(lo, hi, k)
  a = []
  (lo..hi).each{|x| a << [x, weight(x)]}
  a.sort{|x, y| (x[1] <=> y[1]) == 0 ? x[0] <=> y[0] : x[1] <=> y[1] }[k-1][0]
end

def weight(x)
  return 0 if x == 1
  @dp ||= {}
  @dp[x] ||= 1 + (x.odd? ? weight(x * 3 + 1) : weight(x / 2))
end
```