思路见注释

```ruby []
require 'set'
# @param {String} s
# @param {String[]} words
# @return {Integer[]}

def find_substring(s, words)
  return [] if words.empty?
  word_length = words.first.size
  sub_string_length = words.size * word_length
  marks = Set.new
  words_set = words.to_set
  
  # 第一步：先记录每个单词出现过的位置，存入set `marks`
  # 如
  # s = "barfoothefoobarman",
  # words = ["foo","bar"]
  # 
  # marks = [0, 3, 9, 12]
  # 0, 3, 9, 12都是`words`里面的单词出现过的位置
  s.chars.each_with_index do |_, i|
    if words_set.include?(s[i, word_length])
      marks << i
    end
  end

  # 第二步：检查`marks`中每个标记
  # 以当前标记点为起点，如果后面连续`words.size - 1`个点都被标记过
  # 则说明当前标记的点有可能符合题目要求
  # 以上面的输入为例，当前标记为9时，下一个需要被标记的点是12 (9 + word_length = 12)
  # 12又刚好被标记过，所以9可能是符合题目的解
  resuts = []
  marks.each do |mark|
    next if mark + sub_string_length > s.size
    sub_set = Set.new [mark]
    (words.size - 1).times do
      sub_set << (mark + word_length)
    end

    if sub_set.subset? marks
      resuts << mark
    end
  end

  # 第三步：过滤第二步结果
  # 第二步的结果中可能会包含错误结果
  # 如
  # s = "barfoothefoofooman",
  # words = ["foo","bar"]
  # 第二步的结果认为9是一个符合要求的解
  # 但此时9对应的子串是`foofoo`，需要被过滤掉
  #
  # 如果继续优化的话，这一步可能能放到第二步
  # 不过这里数据量已经很小，基本是O(n)操作，不优化性能也不会受太大影响
  words = words.sort
  resuts.select do |i|
    sub_string = s[i, sub_string_length]
    sub_string_set = sub_string.scan(/\w{#{word_length}}/).sort
    sub_string_set == words
  end
end
```
