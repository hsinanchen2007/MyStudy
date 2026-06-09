
思路：先找到num里面第一组a1 + a2 = a3的值，以及a1、a2、a3的位置下标。即可继续验证a2 + a3 == a4 、 a3 + a4 == a5 ....

```
function isAdditiveNumber(num) {
    let headers = findAdditiveHeader(num);
    for(let k in headers ) {
        let header = headers[k];
        if( findNextAdditive(header) ) return true;
    }
    return false;
};

/**
 * 查找下一个累加数；
 * 前面已经找到num的第一个公式，以及里面的两个加数和接过书的下标，这里可以验证第二个被加数和第一个结果数之和是不是接下来的数。
 * 即，已验证num中有a1 + a2 = a3，并且知道a1、a2、a3的下标。那接下来验证a2 + a3 是否num接下来的数；
 */
function findNextAdditive(header) {  
    let num = header.num;
    let next = Number(num.slice(...header.a2)) + Number(num.slice(...header.a3));
    let nextLength = (next + '').length;
    if( header.a3[1] === header.num.length ) return true;
    if(num.slice(header.a3[1], header.a3[1] + nextLength) == next) {
        if( header.a3[1] + nextLength === num.length ) return true;
        return findNextAdditive({
            num: num,
            a1: header.a2,
            a2: header.a3,
            a3: [header.a3[1], header.a3[1] + nextLength]
        });
    }
    return false;
}

/**
 * 找到一个字符串的累加数的开头一组简单累加数，及其坐标
 * [{
 *      num: 输入的字符串,  // 以11213为例，num为12313
 *      a1: [0, 第一个被加数结束的下标] // 以11213为例，al为[0, 2]
 *      a2: [第二个被加数开始的坐标, 第二个被加数结束的坐标]  // 以11213为例，a2为[2, 3]
 *      a3: [第一个结果数开始的坐标, 第一个结果数结束的坐标]  // 以11213为例，a3为[3, 5]
 * }]
 * 返回值是一个数组，因为一个字符串可能有多个头一组简单累加数，比如11213 就有 1 + 12 = 13 也有 1 + 1 = 2;
 */
function findAdditiveHeader(num) {
    let length = num.length;
    let result = [];
    for(let index = 3; index <= length ; index++ ) {
        let isAdditive = isSingleAdditive(num.slice(0, index))
        if(isAdditive.result) {
            result.push({
                num: num,
                a1: [0, isAdditive.index],
                a2: [isAdditive.index, isAdditive.index2],
                a3: [isAdditive.index2, index]
            })
        }
    };
    return result;
};

/**
 * 验证这是不是一个简单的累加数，即该数只能拆分成一次加法，如：123(true)  11213(true)   1235(false)
 * 返回值为对象
 * {
 *      result: boolean, //是否简单累加数
 *      index: 第一个分割下标， //以11213为例，index为1
 *      index2: 第二个分割下标  //以11213为例，index为3
 * }
 */
function isSingleAdditive(num) {
    function isValid(num) {
        if( num.length > 1 ) return num[0] != 0;
        return true;
    }
    for(let index = 1; index <= num.length - 2; index++ ) {
        for(let index2 = index + 1; index2 <= num.length -1; index2++ ) {
            let a1 = num.slice(0, index);
            let a2 = num.slice(index, index2);
            let a3 = num.slice(index2);
            if( !isValid(a1) || !isValid(a2) || !isValid(a3)) continue;
            if( a3 - a2 == a1 ) return { result: true, index, index2 };
        };
    };
    return {result: false} ;
};
```