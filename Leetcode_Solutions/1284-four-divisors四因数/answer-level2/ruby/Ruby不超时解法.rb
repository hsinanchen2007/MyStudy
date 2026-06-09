### 解题思路
竞赛时一直超时，最后抛弃了分治与找质数的方法。

除1以外，每个数num的因数至少有2个：1与num
先记录下因数数量2与因数和1 + num
由于1的因数数量不足4个，不会被加入总数cnt中，这里没有另外处理。

每一个因数j都有另一个因数num / j与之对应，
在num != j*j的情况下，可以一次记录2个因数。
当因数数量超过4个时，直接舍弃当前数num进入下一个数的判断。

因为在每一个小于√num的数被记录时，另一个较大的因数num / j也被记录了
因此循环到j * j <= num就可以中止。
随后，满足因数数目恰为4个的num，其因数和sum计入总数cnt。


### 代码

```ruby
def sum_four_divisors(nums)
  cnt = 0
  i = 0
  while i < nums.size
    num = nums[i]
    sum = 1 + num
    divisors = 2
    j = 2
    while j * j <= num
      if num % j == 0
        divisors += 1
        sum += j
        if j * j < num
          divisors += 1
          sum += num / j
        end
      end
      j += 1
    end
    cnt += sum if divisors == 4
    i += 1
  end
  cnt
end
```

执行用时 :268 ms, 在所有 Ruby 提交中击败了100.00%的用户
内存消耗 :10 MB, 在所有 Ruby 提交中击败了100.00%的用户