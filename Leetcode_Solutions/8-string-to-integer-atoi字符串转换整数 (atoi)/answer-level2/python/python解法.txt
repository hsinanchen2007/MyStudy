```javascript []
console.log('Hello world!')
```
```python []
def myAtoi(str):
    """
    :type str: str
    :rtype: int
    """
    str = str.replace(' ', '')
    flag = ['+', '-', ' ', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    if not str or len(str) == 0 or str[0] not in flag:
        return 0
    result = ''
    if str[0] == '-' or str[0] == '+':
        result += str[0]
        str = str[1:]
    for s in str:
        if s < '0' or s > '9':
            break
        result += s
    other = ['', '+', '-']
    if result in other:
        return 0
    num = int(result)
    if num > 2**31 - 1:
        return 2**31 - 1
    elif num < -2**31:
        return -2**31

    return num


```
```ruby []
puts 'Hello world!'
```
