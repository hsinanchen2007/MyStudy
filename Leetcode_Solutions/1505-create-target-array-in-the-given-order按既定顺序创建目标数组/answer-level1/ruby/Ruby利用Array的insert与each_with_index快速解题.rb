### 解题思路
each_with_index分别迭代index数组的每个元素k与元素下标i，
随后在a中将nums[i]插入到位置k。

由于Ruby核心库的强大性，可以直接按题目描述一步到位。

### 代码

```ruby
def create_target_array(nums, index)
  a = []
  index.each_with_index{|k, i| a.insert(k, nums[i])}
  a
end
```
执行用时 :32 ms, 在所有 Ruby 提交中击败了100.00%的用户
内存消耗 :9.3 MB, 在所有 Ruby 提交中击败了100.00%的用户