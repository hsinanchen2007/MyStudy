滑动窗口
```Ruby
def length_of_longest_substring(s)
	slideWindow = Hash.new
	startIndex = 0
	endIndex = 0
	ans = 0
	while startIndex < s.length and endIndex < s.length
		char = s[endIndex]
		if  slideWindow.has_key?(char)
			startIndex = [startIndex, slideWindow[char]].max
		end
		endIndex = endIndex + 1
		ans = [ans, endIndex - startIndex].max
		slideWindow[char] = endIndex
	end
	return ans
end
```