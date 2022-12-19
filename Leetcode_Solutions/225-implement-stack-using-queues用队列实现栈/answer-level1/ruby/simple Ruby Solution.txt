### 解题思路
ruby solution,use array(stack) to get queue


### 代码

```ruby
class MyStack
=begin
    Initialize your data structure here.
=end
    def initialize()
        @stk = []
    end


=begin
    Push element x onto stack.
    :type x: Integer
    :rtype: Void
=end
    def push(x)
        @stk.push x
    end


=begin
    Removes the element on top of the stack and returns that element.
    :rtype: Integer
=end
    def pop()
        @stk.pop
    end


=begin
    Get the top element.
    :rtype: Integer
=end
    def top()
        @stk.last
    end


=begin
    Returns whether the stack is empty.
    :rtype: Boolean
=end
    def empty()
        @stk.empty?
    end


end

# Your MyStack object will be instantiated and called as such:
# obj = MyStack.new()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```