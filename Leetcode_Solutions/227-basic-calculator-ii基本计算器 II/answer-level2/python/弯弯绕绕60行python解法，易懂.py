class Solution:
```javascript []
console.log('Hello world!')
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```
    def calculate(self, s: str) -> int:
        nums = []
        signs = []
        num = ""
        for i in s:
            if i in ["0","1","2","3","4","5","6","7","8","9"]:
                num = num + i
            elif i in ["+", "-", "*", "/"]:
                nums.append(int(num))
                num = ""
                signs.append(i)
            else:
                continue
        nums.append(int(num))
        if len(nums) == 1:
            return nums[0]
        new_nums = []
        new_signs = []
        flag = False
        mul = 0
        for i, sign in enumerate(signs):
            if sign == "*" and not flag:
                mul = nums[i] * nums[i + 1]
                flag = True
            elif sign == "/" and not flag:
                mul = nums[i] // nums[i + 1]
                flag = True
            elif sign == "*" and flag:
                mul = mul * nums[i + 1]
            elif sign == "/" and flag:
                mul = mul // nums[i + 1]
            else:
                if flag:
                    new_nums.append(mul)
                else:
                    new_nums.append(nums[i])
                flag = False
                new_signs.append(sign)
        if signs[-1] in ["+", "-"]:
            new_nums.append(nums[-1])
        else:
            new_nums.append(mul)
        if len(new_nums) == 1:
            return new_nums.pop()
        total = 0
        for i, sign in enumerate(new_signs):
            if sign == "+" and i == 0:
                total = new_nums[i] + new_nums[i + 1]
            elif sign == "-" and i == 0:
                total = new_nums[i] - new_nums[i + 1]
            elif sign == "+":
                total = total + new_nums[i + 1]
            else:
                total = total - new_nums[i + 1]
        return total