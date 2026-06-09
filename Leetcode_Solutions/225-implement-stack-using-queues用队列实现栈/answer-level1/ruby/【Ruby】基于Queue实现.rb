# 解题思路
设计两个队列，用于实现栈。队列1用于存放元素，队列2只在pop或者top时，辅助存放元素。

`pop`: 先将元素逐个放入队列2，直到只剩下一个元素，即为结果。再将数据从队列2放回队列1
`top`: 其他与pop同理，区别在于，最后一个元素，需要重新放回队列1中即可
`empty`: 元素都存放于队列1中，因此，直接判断队列1是否为空。

### 代码

```ruby
class MyStack

	def initialize()
		@arr1 = Queue.new()
		@arr2 = Queue.new()
	end

	def push(x)
		@arr1.push(x)
	end

	def pop()
		(@arr1.size-1).times { @arr2.push(@arr1.pop) }
		result = @arr1.pop
		@arr1, @arr2 = @arr2, @arr1

		result
	end

	def top()
		result = pop()
		@arr1.push(result)
		result
	end

	def empty()
		@arr1.empty?
	end
end
```