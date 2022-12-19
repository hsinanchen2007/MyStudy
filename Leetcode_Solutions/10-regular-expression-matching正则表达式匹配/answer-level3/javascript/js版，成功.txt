

```js
/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 * 执行时间太长  但是一些简单的还是可以的  继续长期优化
 */
var isMatch = function(s, p) {

    if (s === p) return true;
    var regs = []; // 最终
    for (var i = 0; i < p.length; i++) {
        if (p[i + 1] === '*') {
            var last = regs[regs.length - 1];
            if (last && last.str === p[i] && last.len === Number.MAX_VALUE) {
            } else {
                regs.push({
                    str: p[i],
                    len: Number.MAX_VALUE,
                });
            }

            i++;
        } else {
            regs.push({
                str: p[i],
                len: 1,
            });
        }
    }

    return findOne(s, regs);
    function findOne(s, reg) {
        // console.log(s, JSON.stringify(reg));
        if (s === '' && reg.findIndex(i => i.len === 1) === -1) return true; // 特例
        if (s === '' && reg.findIndex(i => i.len === 1) !== -1) return false; // 特例
        if (s[0] && reg.length === 0) return false;

        if (s[0] === reg[0].str || reg[0].str === '.') {
            if (!s[1] && !reg[1]) return true;
            else {
                if (reg[0].len > 1) {
                    if (s[1] && !reg[1]) {
                        return findOne(s.slice(1), reg);
                    } else if (!s[1] && reg[1]) {
                        return (
                            findOne(s, reg.slice(1)) ||
                            findOne(s.slice(1), reg.slice(1))
                        );
                    } else {
                        var b1 = findOne(s, reg.slice(1));
                        var b2 = findOne(s.slice(1), reg);
                        var b3 = findOne(s.slice(1), reg.slice(1));
                        return b1 || b2 || b3;
                    }
                } else {
                    if (s[1] && reg[1])
                        return findOne(s.slice(1), reg.slice(1));
                    else if (
                        !s[1] &&
                        reg.slice(1).findIndex(i => i.len === 1) === -1
                    )
                        return true;
                    else return false;
                }
            }
        } else if (reg[0].len > 1) return findOne(s, reg.slice(1));
        else return false;
    }
};


// 一些测试用例

// var res;

// s = 'aa';
// p = 'a*c*';
// res = isMatch(s, p);
// console.log(res === true, '-----------------');

// s = 'aaaaaaaaaaaaab';
// p = 'a*a*a*a*a*a*a*a*a*a*c';
// res = isMatch(s, p);
// console.log(res === false, '-----------------');

// s = 'a';
// p = 'ab*';
// res = isMatch(s, p);
// console.log(res === true, '-----------------');
// s = 'aab';
// p = 'c*a*b';
// res = isMatch(s, p);
// console.log(res === true, '-----------------');

// s = 'aaa';
// p = 'ab*ac*a'; // aaa abaa abaca
// res = isMatch(s, p);
// console.log(res === true, '-----------------');

// s = '';
// p = '.';
// res = isMatch(s, p);
// console.log(res === false, '-----------------');
// s = '';
// p = 'a*';
// res = isMatch(s, p);
// console.log(res === true, '-----------------');

// s = '';
// p = '.*';
// res = isMatch(s, p);
// console.log(res === true, '-----------------');

// s = 'aaa';
// p = 'a*a';
// res = isMatch(s, p);
// console.log(res === true, '-----------------');

// s = 'bbbba';
// p = '.*a*a';
// res = isMatch(s, p);
// console.log(res === true, '-----------------');

// s = 'aaa';
// p = '.*a';
// res = isMatch(s, p);
// console.log(res === true, '-----------------');

// s = 'abcd';
// p = 'd*';
// res = isMatch(s, p);
// console.log(res === false, '-----------------');

// s = 'ab';
// p = '.*c';
// res = isMatch(s, p);
// console.log(res === false, '-----------------');

// s = 'ab';
// p = '.*c';
// res = isMatch(s, p);
// console.log(res === false, '-----------------');

// s = 'aa';
// p = 'a';
// res = isMatch(s, p);
// console.log(res === false, '-----------------');

// s = 'mississippi';
// p = 'mis*is*p*.';
// res = isMatch(s, p);
// console.log(res === false, '-----------------');

// s = 'ab';
// p = '.*';
// res = isMatch(s, p);
// console.log(res === true, '-----------------');

// s = 'aa';
// p = 'a*';
// res = isMatch(s, p);
// console.log(res === true, '-----------------');

// s = 'bbbba';
// p = '.*a*a';
// res = isMatch(s, p);
// console.log(res === true, '-----------------');

// s = 'bbbba';
// p = 'b.*a';
// res = isMatch(s, p);
// console.log(res === true, '-----------------');
```