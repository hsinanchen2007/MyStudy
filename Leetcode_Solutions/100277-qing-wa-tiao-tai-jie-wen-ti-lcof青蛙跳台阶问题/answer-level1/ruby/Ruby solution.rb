### 解题思路
[递推求解](https://www.dotnetperls.com/fibonacci-ruby)

### 代码

```ruby
# @param {Integer} n
# @return {Integer}
def num_ways(n)
    a = 1
    b = 1
    
    # Compute Fibonacci number in the desired position
    n.times do
        tmp = a
        a = b
        # Add up previous two numbers in sequence
        b = tmp + b
    end
    
    a % (10 ** 9 + 7)
        
end
```