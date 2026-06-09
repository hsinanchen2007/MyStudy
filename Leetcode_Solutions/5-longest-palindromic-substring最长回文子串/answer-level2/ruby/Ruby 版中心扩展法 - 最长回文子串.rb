```ruby
# @param {String} s
# @return {String}
def longest_palindrome(s)
    return "" if s.nil? || s.length == 0 
    i = 0
    begin_index = 0
    end_index = 0
    while i < s.length do 
        len1 = expand_around_center(s, i, i)
        len2 = expand_around_center(s, i, i+1)
        len = [len1, len2].max
        if len > end_index - begin_index 
            begin_index = i - (len - 1)/2
            end_index = i + len/2
        end
        i = i + 1
    end
    return s.slice(begin_index, end_index - begin_index + 1)
end

def expand_around_center(s, left, right) 
    l = left
    r = right 
    while l >= 0 && r <= s.length && s[l] == s[r] do
        l = l - 1
        r = r + 1
    end
    return r - l - 1
end
```