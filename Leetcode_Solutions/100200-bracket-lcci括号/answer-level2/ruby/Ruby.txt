参考了题目给出的提示，果然理解问题的角度才是最重要的……
感觉层序遍历会比较清晰直观
```
# @param {Integer} n
# @return {String[]}
def generate_parenthesis(n)
  return [] if n <= 0
  xs = [['(', 1, 0]]
  (2..(n * 2)).each do |i|
    next_xs = []
    xs.each do |s, l, r|
      next_xs << [s + '(', l + 1, r] if l < n # 左括号没用完可以添加左括号
      next_xs << [s + ')', l, r + 1] if l > r # 左括号比右括号多可以添加右括号
    end
    xs = next_xs
  end
  return xs.map! { |s, l, r| s }
end
```
