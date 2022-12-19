### 解题思路
此处撰写解题思路
利用内积函数就行了
### 代码

```ruby
# @param {String} digits
# @return {String[]}
def letter_combinations(digits)
    alphanum = ("a".."z").to_a
    arr = digits.split("").map{|e|
        index = 3*(e.to_i-2)
        length = 3
        case e
        when "7"
            length = 4
        when "8"
            index += 1
        when "9"
            length = 4
            index += 1
        end
        e = alphanum[index,length]
    }

    arr.empty? ? [] : arr[0].product(*arr[1..-1]).map{|e| e.join("")}
end
```