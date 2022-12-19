这课题主要考到的知识点：

        1、0开头的数字，js会自动解析成8进制
        2、对1的匹配，记录出现次数

        菜鸡解法：
    ```
        var hammingWeight = function (n) {
            var j = 0
            var num = n.toString(2).split('')
            for (var i = 0, len = num.length; i < len; i++) {
                if (num[i] == 1) {  
                    j++
                }
            }
            return j
        };
    ```
        大神解法：（直接正则搞定）ps:我怎么没想到，大神就是大神。
    ```
        var hammingWeight = function (n) {
            return ((n.toString(2)).match(/1/g) || []).length
        };
    ```
