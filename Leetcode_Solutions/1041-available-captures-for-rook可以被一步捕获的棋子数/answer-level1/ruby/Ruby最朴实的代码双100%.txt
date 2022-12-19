### 解题思路
先遍历i与j找到R，之后分别对R的上下左右元素进行遍历
出现B就跳出循环，出现p则计数+1并跳出循环。
四方向遍历后return计数即为结果。

### 代码

```ruby
def num_rook_captures(board)
  @list ||= ['R', 'B', 'p']
  n = 0
  i = 0
  while i < 8
    j = 0
    while j < 8
      if board[i][j] == @list[0]
        k = i
        while k > 0
          case board[k][j]
          when @list[1] then break
          when @list[2] 
            n += 1
            break
          end
          k -= 1
        end
        k = i
        while k < 8
          case board[k][j]
          when @list[1] then break
          when @list[2] 
            n += 1
            break
          end
          k += 1
        end
        k = j
        while k > 0
          case board[i][k]
          when @list[1] then break
          when @list[2] 
            n += 1
            break
          end
          k -= 1
        end
        k = j
        while k < 8
          case board[i][k]
          when @list[1] then break
          when @list[2] 
            n += 1
            break
          end
          k += 1
        end
        return n
      end
      j += 1
    end
    i += 1
  end
end
```

执行用时 :32 ms, 在所有 Ruby 提交中击败了100.00%的用户
内存消耗 :9.3 MB, 在所有 Ruby 提交中击败了100.00%的用户