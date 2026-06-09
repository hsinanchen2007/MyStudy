### 解题思路
此处撰写解题思路

### 代码

```ruby
# @param {Integer} n
# @return {Boolean}
def is_power_of_three(n)
    return false if n==0
    loop do
        return true if n==1
        if n%3==0
            n=n/3
        else
            return false
        end
    end
end
```