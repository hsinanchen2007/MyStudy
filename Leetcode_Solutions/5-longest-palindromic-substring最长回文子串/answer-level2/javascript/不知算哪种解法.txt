由题意发现回文字符串有两种格式，为``aba``和``baab``，分别针对两种格式设计方法。姑且算暴力破解吧。。
```
// time: 192ms(54.93%) memory: 37.4MB(46.79%)
var longestPalindrome = function(s) {
    if (s.length <= 1) return s;
    let res = '', _res = '';

    // 1.aba模式
    for (let i = 1; i < s.length - 1; i++) {
        let flag = true;
        let left = i - 1, right = i + 1;// 左右边界

        while(flag) {
            if (left >= 0 && right <= s.length - 1) {
                if (s[left] === s[right]) {
                    let str = s.slice(left, right + 1);

                    res = str.length >= res.length ? str : res;
                    left--;
                    right++;
                } else {
                    flag = false;
                }
            } else {
                flag = false;
            }
        }
    }

    // 2.baab模式
    for (let i = 0; i < s.length; i++) {
        let _flag = true;
        let _left = i, _right = i + 1;// 左右边界

        while(_flag) {
            if (_left >= 0 && _right <= s.length - 1) {
                if (s[_left] === s[_right]) {
                    let _str = s.slice(_left, _right + 1);

                    _res = _str.length >= _res.length ? _str : _res;
                    _left--;
                    _right++;
                } else {
                    _flag = false;
                }
            } else {
                _flag = false;
            }
        }
    }

    if (!_res.length) _res = s[0];
    return res.length > _res.length ? res : _res;
};
```