```javascript []
console.log('Hello world!')
```
```python []
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        
        if numRows < 2: 
            return s
            
        result = ["" for _ in range(numRows)]

        idx = 0
        flag = -1
        for i in s:
            result[idx] += i
            
            if idx == numRows-1 or idx == 0:
                flag = -flag
            idx += flag

        return ''.join(result)
```
```ruby []
puts 'Hello world!'
```
