执行用时 :68 ms, 在所有 Ruby 提交中击败了100.00%的用户
内存消耗 :9.9 MB, 在所有 Ruby 提交中击败了100.00%的用户

### 解题思路
直接两层迭代就能够完成。
Array#count对块计算结果为true的元素计数
Array#any?对块计算结果，一旦有true就立刻返回true，否则返回false

### 代码

```ruby
# @param {Integer[]} arr1
# @param {Integer[]} arr2
# @param {Integer} d
# @return {Integer}
def find_the_distance_value(arr1, arr2, d)
	arr1.count{|x| !arr2.any?{|y| (x-y).abs <= d}}
end
```