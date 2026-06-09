我看题解中没有 JS 的版本，
我来补一个吧。
参照官方题解的 JavaScript 的版本:
```js
function f1(arr1, arr2) {
    if(arr1.length > arr2.length) {[arr1, arr2] = [arr2, arr1]}
    const arr1Length = arr1.length, arr2Length = arr2.length;
    let iMin = 0, iMax = arr1Length;
    const halfLen = Math.floor((arr1Length + arr2Length + 1) / 2);   // +1 这种情况单数时取maxleft
    while (iMin <= iMax) {
        let i = Math.floor((iMin + iMax) / 2);   //   二分查找
        let j = halfLen - i;
        if(i < iMax && arr2[j - 1] > arr1[i]) {
            iMin = i + 1;
        } else if (i > iMin && arr1[i - 1] > arr2[j]) {
            iMax = i - 1;
        } else {
            let maxLeft = 0;
            if(i === 0) {maxLeft = arr2[j-1]}
            else if(j ===0 ) {maxLeft = arr1[i-1]}
            else { maxLeft = Math.max(arr1[i-1], arr2[j-1]); }
            if ( (arr1Length + arr2Length) % 2 === 1 ) { return maxLeft; }

            let  minRight = 0;
            if (i === arr1Length) { minRight = arr2[j]; }
            else if (j === arr2Length) { minRight = arr1[i]; }
            else { minRight = Math.min(arr2[j], arr1[i]); }
            return (maxLeft + minRight) / 2
        }
    }
    return 0;
}
```
不考虑时间复杂度代码量比较小的版本:
```js
function f2(arr1, arr2) {
    const tmp = arr1.concat(arr2).sort((a, b) => a - b);
    const tmp2 = tmp.slice(Math.ceil(tmp.length/ 2) - 1 , Math.floor(tmp.length /2 ) + 1);  // 切出来的长度为1或者2
    let num= 0;
    tmp2.map(item => num += item);
    return (num / tmp2.length);
}

可以自己拿到 IDE 里去试试，当arr1 , arr2 数据量很大时，f1 和 f2 效率差异巨大。我试了一次，数组长度好像是千万。一个毫秒级，一个二十多秒。
作为一个前端，对于前端那种数据量，f2 就够用啦。