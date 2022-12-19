### 解题思路
什么情况啊这是

### 代码

```ruby
# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}

def two_sum(nums, target)
    (nums.size-1).times do |i|
        (nums.size-i-1).times do |j|
            j = j+i+1
            if nums[i]+nums[j]==target
#                puts "[#{i},#{j}]"
#                return "[#{i},#{j}]"
                 return [i,j]
            end
        end
    end
end

``` 