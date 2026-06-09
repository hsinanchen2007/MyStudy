
```
# @param {Integer} n
# @return {String}
def count_and_say(n)
    return "1" if n == 1
    say(count_and_say(n-1))
end

def say(str)
   prev = str.split(/(1+)|(2+)|(3+)/).delete_if { |item| item.empty? }
   prev.map { |item| item.length.to_s + item[0] }.join
end
```
