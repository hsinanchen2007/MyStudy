one line solution
```ruby
def find_number_in2_d_array(matrix, target)
    matrix.any?{|row| row.include?(target)}
end
```
