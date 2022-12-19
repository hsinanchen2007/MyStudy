### 解题思路
此处撰写解题思路

### 代码

```ruby
# @param {String[]} queries
# @param {String} pattern
# @return {Boolean[]}
def camel_match(queries, pattern)
  res = Array.new(queries.size, false)
  i = 0
  while i < queries.size
    idx = 0 # 记录pattern的长度
    j = 0 # 记录query的长度

    while j < queries[i].size
      if idx == pattern.size
        if queries[i][j] >= 'A' &&  queries[i][j] <= 'Z'
          break
        end
        j += 1
        next
      end

      if queries[i][j] == pattern[idx]
        idx += 1
      else
        if queries[i][j] >= 'A' &&  queries[i][j] <= 'Z'
          break
        end  
      end
      j += 1
    end

    if j == queries[i].size && idx == pattern.size
       res[i] = true
    end
    i += 1
  end
  res
end
```