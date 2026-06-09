### 解题思路
脚写的代码

### 代码

```ruby
def count_characters(words, chars)
	h, hSize = s2p(chars), chars.size
	n = i = 0
	while i < words.size
		if (s = words[i]).size <= hSize
			n += s.size if cmp(s2h(s), h)
		end
		i += 1
	end
	n
end

def s2h(s)
  i, h = -1, Hash.new(0)
  h[s[i]] += 1 while (i += 1) < s.size
  h
end
def s2p(s) ->(c){ h ||= {}; h[c] ||= s.count(c) } end
def cmp(h1, h2) h1.all?{|k, v| v <= h2[k] } end
```