
```ruby []
def length_of_longest_substring(s)
    max = 0
    curr_arr = []
    s.each_char do |c|
        if curr_arr.include?(c)
            index = curr_arr.index(c)
            curr_arr.slice!(0..index)
        end
        curr_arr << c 
        max = curr_arr.length > max ? curr_arr.length : max
    end
    return max  
end
```
