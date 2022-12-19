### 解题思路
抄袭的官方答案，但是赋值做了一些修改，比较好理解一些
current从fib(3)开始，求解fib(i),一直向右挪动得出fib(n);i的取值范围为[3,n]; current = fib(i)

### 代码

```ruby
# @param {Integer} n
# @return {Integer}
#n        0       1       2       3         4       5          6          7
#fib(n)   0       1       1       2         3       5          8         13,...,fib(n-2),fib(n-1),fib(n)
#       prev0   prev1 + prev2 -->current
#                         |         |
#                       prev1  + prev2-->current
#                                   |       |
#                                prev1 +  prev2--> current
def fib(n)
    if n <= 1
        return n
    elsif n == 2
        return 1
    else
        current = 0
        prev1 = 1
        prev2 = 1
        for i in 3..n
            current = prev1 + prev2
            prev1 = prev2
            prev2 = current
        end
        return current
    end

end

```