### 解题思路
和前面二进制加法差不多。

### 代码

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int carry = 0;
        for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0; --i, --j) {
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;

            int tmp = n1 + n2 + carry;

            result = to_string(tmp % 10) + result;
            carry = tmp / 10;
        }

        if (carry) {
            result = "1" + result;
        }

        return result;

    }
};
```

```python3
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        result = ""
        carry = 0

        i, j = len(num1) - 1, len(num2) - 1
        while i >= 0 or j >= 0:
            n1 = int(num1[i]) if i >= 0 else 0
            n2 = int(num2[j]) if j >= 0 else 0
            tmp = n1 + n2 + carry

            result = str(tmp % 10) + result
            carry = tmp // 10

            i -= 1
            j -= 1

        if (carry):
            result = '1' + result

        return result


```

```javascript
var addStrings = function(num1, num2) {
  // 前面做过二进制的相加，这个是十进制的相加思路差不多
  let result = "";
  let carry = 0; // 用于临时储存向上进位

  for (
    let i = num1.length - 1, j = num2.length - 1;
    i >= 0 || j >= 0;
    i--, j--
  ) {
    const tmp = (parseInt(num1[i]) || 0) + (parseInt(num2[j]) || 0) + carry;

    result = (tmp % 10) + result;
    carry = Math.floor(tmp / 10);
  }
  if (carry !== 0) {
    result = 1 + result;
  }

  return result;
};

```