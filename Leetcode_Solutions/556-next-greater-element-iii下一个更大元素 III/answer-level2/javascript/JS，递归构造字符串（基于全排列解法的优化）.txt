### 解题思路
&emsp;&emsp;官方的全排列算法会把所有可能的数字字符串进行枚举，然后比较得出最小值。显然构造出所有的数字字符串太耗费时间了。
&emsp;&emsp;题目要求我们给出大于当前值的最小值，且所得值存在的位数和给出值完全相同。明显的当给出的值是其所有位数构成的最大值的时候问题无解，也即是所有的位数都是逆序排序的时候，例如：5521, 98422...。
&emsp;&emsp;当题目有解时，我们从数字的高位开始向后做判断，当前高位固定的情况下分两种情况讨论：
&emsp;&emsp;1. 后面的位数能构成更大值改动后面的位数即可（保证最小值）；
&emsp;&emsp;2. 后面的位数已经是最大值了，明显的我们要改变当前的高位。将当前高位和后面的位数一起做一次升序排序选出大于当前高位的下一个值，将其替换高位，然后将排序后剩下的所有位数拼接上去既是大于当前值的最小值。


### 代码

```javascript []
/**
 * @param {number} n
 * @return {number}
 */
var nextGreaterElement = function(n) {
    //判断是否是逆序排序，是否有大于当前值的最小值。
    function check(source, sort){
        for(let i = 0; i < source.length; i++){
            if(source[i] != sort[i]){
                return true;
            }
        }
        return false;
    }
    function buildString(str){
        let strArray = str.split(''),
            firstChar = strArray.shift(),
            sortArray = [...strArray].sort((a, b)=> a > b ? -1 : 1),
            res = '';
        /*
            除去高位（第一个字符）后的从大到小排序比较，
            如果一样，证明后续位数是除去高位后剩下位数所能构成的最大值，
            因此要选取升序中高位的下一个数来替换高位，
            替换高位后所得值已经比给出值大，所以只需将后面的位数最小化即可；
        */
        if(!check(strArray, sortArray)){
            for(let i = 0; i <= sortArray.length; i++){
                if(sortArray[i] <= firstChar || i == sortArray.length){
                    res += sortArray[i - 1];
                    sortArray.splice(i - 1, 1, firstChar);
                    break;
                }
            }
            sortArray.sort((a, b)=> a > b ? 1 : -1);
            return res + sortArray.join('');
        }
        //无需改变高位，只关心后续位数
        return firstChar + buildString(strArray.join(''));;
    }

    let nToString = n.toString().split(''),
        sortSet = [...nToString].sort((a, b)=> a > b ? -1 : 1);
    //判断是否有解，解是否是32位整数
    if(check(nToString, sortSet)){
        let num = buildString(nToString.join('')) - 0;
        return num > Math.pow(2, 31) - 1 ? -1 : num;
    }
    //无解
    return -1;
};
```