### 解题思路
对size小于3的nums，可以口算出结果。
（其实等于3也可以，但起始情况不用写那么多）
```ruby
m = nums.size
case m
when 0 then return 0
when 1 then return nums[0]
when 2 then return [nums[0], nums[1]].max
end
```
这个问题与之前的问题非常的相似，唯一的不同只出现在头尾两户的选择上。
这里使用“两路进行”的方法，假设m为nums.size，则一路迭代`0..m-2`，另一路迭代`1..m-1`
将其中的公共部分`1..m-2`取出成为循环条件，其他的分别在循环的头尾单独计算。

先对第一路进行计算，第一路必定取头元素，因此初始化为：`n0 = nums[0];a0 = 0`
n0保存第一路当前的数额，a0保存第一路上一次的数额（初始为0），用于在后面“反悔”。

由于只需要迭代到m-2，我们将前面代表nums.size的m-=1，避免在循环过程中反复调用m - 1

为了保证小偷能够“反悔”，先计算临时值t：`t = [n0, a0 + nums[i]].max`
n0为目前为止已经偷到的钱，而a0滞后于n0，是除去上一家的总数。
这里可以算出是偷前一家划算，还是当作没偷前一家，然后加上现在这一家划算。
但我们不知道下一家会不会又反过来打脸，所以先把现在的结果存在a0，然后才将偷到的钱n0设为t

另一路n1与a1同理，只是n1与a0都是从0开始。

前面的循环结束后，n1还可以决定要不要偷最后一家，因此再来`n1 = [n1, a1 + nums[nums.size-1]].max`
而最后我们需要的是n0与n1的最大值`[n0, n1].max`，所以这两个max可以整合到一起计算。
之前我们已经令`m = nums.size;m -= 1`了，所以以上简化为`[n0, n1, a1 + nums[m]].max`。

### 代码

```ruby
def rob(nums)
	m = nums.size
	case m
	when 0 then return 0
	when 1 then return nums[0]
	when 2 then return [nums[0], nums[1]].max
	end
	i = 1
	n0 = nums[0]
	n1 = 0
	a0 = 0
	a1 = 0
	m -= 1
	while i < m
		x = nums[i]
		t = [n0, a0 + x].max
		a0 = n0
		n0 = t
		t = [n1, a1 + x].max
		a1 = n1
		n1 = t
		i += 1
	end
	[n0, n1, a1 + nums[m]].max
end
```

执行用时 :32 ms, 在所有 Ruby 提交中击败了100.00%的用户
内存消耗 :9.4 MB, 在所有 Ruby 提交中击败了100.00%的用户