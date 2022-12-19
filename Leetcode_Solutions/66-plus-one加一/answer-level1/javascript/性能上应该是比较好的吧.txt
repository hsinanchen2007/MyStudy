执行用时 :56 ms, 在所有 javascript 提交中击败了98.26%的用户
```
    var plusOne = function (digits) {
        for (let i = digits.length - 1; i >= 0; i--) {
            if (digits[i] !== 9) {
                digits[i] = digits[i] + 1;
                i = -1;
            } else {
                digits[i] = 0;
                if (i === 0) digits.unshift(1);
            }
        }

        return digits;
    };
```
