菜鸡javascript解法，思想是对非零数的二进制数进行操作,具体做法就是从后往前对第j(1<j<binNum.length)位和他前面的数进行异或操作：
var grayCode = function (n) {
            var res = [0];
            if (n == 0) return res;
            var len = Math.pow(2, n);
            for (var i = 1; i < len; i++) {
                var binNum = i.toString(2).toString();
                binNum = binNum.split("")
                for (var j = binNum.length; j > 1; j--) {
                    if (binNum[j - 1] ^ binNum[j - 2]) {
                        binNum.splice(j - 1, 1, '1');
                    } else {
                        binNum.splice(j - 1, 1, '0');
                    }
                }
                binNum = binNum.join('');
                res.push(parseInt(binNum, 2));
            }
            return res;
        };
