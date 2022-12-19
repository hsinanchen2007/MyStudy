(1) Brute Force 递归
但是会有大量的重复计算问题，因为 
fib(N) = fib(N - 1) + fib(N - 2)
fib(N - 1) = fib(N - 2) + fib(N - 3)
fib(N - 1) 会重复计算 fib(N - 2)的问题
```
def fib(N):
  if N == 0 or N == 1:
      return N
  if N > 1:
    return fib(N - 1) + fib(N - 2)
```

(2) DP 动态规划
- 同样的问题, 不要再去计算, 也就是说, 重复问题放到一个store中, 遇到重复的内容, 就直接从store中去取就好

自己想到的放到dictionary中, 但是没有第三种好
```
def fib(N):
  if N == 0 or N == 1: return N
  # fib(N) = fib(N - 1) + fib(N - 2), 只需要知道 从 2 到 N - 1的问题即可
  _dict = {
    0: 0,
    1: 1
  }
  i = 2
  while i < N:
    _dict[i] = _dict[i - 1] + _dict[i - 2]
    i += 1

  print(_dict)
  return _dict[N - 1] + _dict[N - 2]

print(fib(6))
```

第三种 也是动态规划的方法，内容放到数组中，不是放到list中
```
def fib(N):
  if N < 2: return N

  F = [0, 1]
  i = 2
  # 例如 N = 6, 那就是 到5这个数位置 (5) + (4)的问题
  while i < N:
    F.append(F[i - 1] + F[i - 2])
    i += 1
  return F[i - 1] + F[i - 2]
```
