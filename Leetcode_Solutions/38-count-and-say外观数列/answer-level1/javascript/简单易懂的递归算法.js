本题大意为
1项不做处理，直接返回本身1
2即解释说明1项，1项是1个1组成，所以为11
3项解释说明2项，2项是2个1组成，所以是21
4项解释说明3项，3项是1个2和1个1组成，所以是1211
5项同理，1个1项和1个2项和2个1项组成，即111221
同理推倒下去。。。

简单递归思路。在做这种需要依赖上一个资源进行计算的题目时，很容易让人联想到递归算法。
简单明确下本体的思路。
1、首先要明确的是递归终止条件。开头满足条件即返回
然后就是处理，用数组就是处理，用字符串性能消耗更大，我试过了。。。
先进行查找，如果相等，那么重合度k增加1，如果不相等，那么进行字符串（数组）拼接
最后用这个新的字符串调用自己进行处理成新的字符串。
```
var countAndSay = function(n) {
    return createStr(1, ['1'], n)

	function createStr(index, str, n) {
        if(index == n)
            return str.join('')//终止条件：查询到了第n个数了，立即返回，否则index+1
        index++
        let newChar = []
        let k = 1//保存该数存在次数：当查询到不等的时候，在下方重置k
        for(let j = 0; j < str.length; j++) {
            let char = str[j]
            if(char == str[j+1] && j != str.length - 1) {//不等，且遍历没到底，那就继续寻找
                   k++
            }else {
                newChar.push(k)
                newChar.push(str[j])
                k=1
            }
        }
        return createStr(index, newChar, n)
    }  
}
```
```
执行用时 :72 ms, 在所有 JavaScript 提交中击败了97.40%的用户
内存消耗 :35.2 MB, 在所有 JavaScript 提交中击败了73.83%的用户
```