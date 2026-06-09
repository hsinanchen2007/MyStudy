一开始没有仔细读题，直接写了一个重复字符串的排列组合；
如果假定字符串中没有重复字符，可以快一倍，但都是层序遍历的思路
```
# @param {String} s
# @return {String[]}

def permutation(input)
  queue = ['']
  input.each_char do |c|
    next_queue = []
    queue.each do |s|
      (0...s.length).each do |i|
        next_queue << s.dup.insert(i, c)
      end
      next_queue << s + c
    end
    queue = next_queue
  end
  return queue
end

# 重复字符串的排列组合
=begin
def permutation(s)
  dic = Hash.new(0)
  s.each_char { |c| dic[c] += 1 }
  queue = [['', dic]]
  (1..s.length).each do |i|
    next_queue = []
    queue.each do |s, d|
      d.each do |c, c_count|
        next_d = d.dup
        if c_count == 1 then next_d.delete(c) else next_d[c] = c_count - 1 end
        next_queue << [s + c, next_d]
      end
    end
    queue = next_queue
  end
  return queue.map! { |s, d| s }
end
=end
```
