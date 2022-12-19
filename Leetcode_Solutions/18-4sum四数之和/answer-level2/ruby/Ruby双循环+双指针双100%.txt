### 解题思路
执行用时 :92 ms, 在所有 Ruby 提交中击败了100.00%的用户
内存消耗 :9.8 MB, 在所有 Ruby 提交中击败了100.00%的用户

思路跟随三数之和，首先对`nums`排序。
四个索引`i,j,k,l`满足i < (j = i + 1) < (k = l - 1) < (l = m - 1)

循环过程为i从0到nums.size - 3,每一遍i循环中l从m - 1循环到i + 1
也就是从固定i在左边，l从右边逐渐往左逼近，一轮循环后l再次回到最右边

因为数组已经排序，如果用x代表n[i]而y代表n[l]，则四数之和有：
`x * 4 <= x + n[j] + n[k] + y <= y * 4`
因此如果4x大于target或者4y小于target，则四数之和必将大于（小于）target
遇到这种情况，直接可以结束l循环，进入下一轮i循环。

因为jk循环中x、y、target都是定值，这里用临时变量`t = target - x - y`减少重复计算
d为一个布尔值，代表down?，用于决定四数之和为target时是否应该k-=1
这里应当交替改变j与k，因此引入了d控制状态的变化。

为了避免重复结果，ijkl这四个索引在改变时必须确保改变后的值与原来的值不相等。


### 代码

```ruby
def four_sum(nums, target)
  m = nums.size
  return [] if m < 4
  n = nums.sort
  a = []
  i = 0
  while i < m - 3
    l = m - 1
    while i < l
      x = n[i]
      break if x * 4 > target
      y = n[l]
      break if y * 4 < target
      j = i + 1
      k = l - 1
      t = target - x - y
      d = true
      while j < k
        s = n[j] + n[k]
        case s <=> t
        when 1  then k -= 1
        when -1 then j += 1
        when 0
          a << [x, n[j], n[k], y]
          if d
            z = n[k]
            k -= 1 until z != n[k]
          else
            z = n[j]
            j += 1 until z != n[j]
          end
          d = !d
        end
      end
      l -= 1 until y != n[l]
    end
    i += 1 until x != n[i]
  end
  a
end
```