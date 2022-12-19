
利用`ruby`和`递归`可以把写非常少的代码既可以解决问题，有什么更好的写法欢迎指出
```ruby
def add_two_numbers(l1, l2, carry = 0, arr = [])
  if l1 || l2 || !carry.zero?
    sum = (l1&.val || 0) + (l2&.val || 0) + carry
    carry = sum / 10
    arr << sum % 10
    add_two_numbers(l1&.next, l2&.next, carry, arr)
  else
    return arr
  end
end
```
