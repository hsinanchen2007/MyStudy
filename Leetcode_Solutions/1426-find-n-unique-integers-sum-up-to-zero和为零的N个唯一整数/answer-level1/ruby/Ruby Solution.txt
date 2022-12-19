Ruby one line solution ~60ms.

```ruby
def sum_zero(n)
    # generate array from -n + 1 to n by 2
    return (1-n...n).step(2).to_a
end
```
