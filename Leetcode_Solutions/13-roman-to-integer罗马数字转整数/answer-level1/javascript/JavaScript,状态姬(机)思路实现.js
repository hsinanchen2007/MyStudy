对于此题状态机只有两个状态，因为我们只有 I,X,C,作为单独数字 或与之后的一个字符组成组合数字.

这里我的状态机实现是非常经典的方式：用函数表示状态，用 if 表示状态的迁移关系，用 return 值表示下一个状态.

因为状态要根据下一个字符判断,所以最后要在补一个字符进去.


O(n)的算法,重要的不是效率,主要是为了玩状态姬(逃___)

```
        var res = 0; 
        var NUM = 0; //预存状态,最终态要根据后一位判定
        const start = char => {
            if (char == 'I') {
                NUM = 1
                return notEnd;
            } else if (char == 'X') {
                NUM = 10
                return notEnd;
            } else if (char == 'C') {
                NUM = 100
                return notEnd
            }
            if (char == 'V') {
                res += 5
                return start
            }
            if (char == 'L') {
                res += 50 
                return start
            }
            if (char == 'D') {
                res += 500
                return start
            }
            if (char == 'M') {
                res += 1000
                return start
            }
        }
        const notEnd = char => {
            if (char == 'V' && NUM == 1) {
                res += 4
                return start
            } else if (char == 'X' && NUM == 1) {
                res += 9
                return start
            } else if (char == 'L' && NUM == 10) {
                res += 40
                return start
            } else if (char == 'C' && NUM == 10) {
                res += 90
                return start
            } else if (char == 'D' && NUM == 100) {
                res += 400
                return start
            } else if (char == 'M' && NUM == 100) {
                res += 900
                return start
            } else {
                res += NUM
                return start(char)
            }
        }
        var romanToInt = function (s) {
            res = 0;
            var state = start;
            for (var c of s.split('')) {
                state = state(c);
            }
            state('') //后判定状态姬,再传一个,保证最后一个字符的状态确定
            return res
        };
```
