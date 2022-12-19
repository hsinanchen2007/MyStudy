### 解题思路


### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
    // 下面呢，都是失败品，kmp算法没注意到是子序列，不是子字符串，而正则会超时
    // 运用一个大佬的思路
    // 如果s是t的子序列，也就是说s中的所有字符都会按照顺序出现在t中，因此，使用双指针实现即可
    // let i = 0, j = 0;
    // while(s[i] && t[j]) {
    //     if(s[i] === t[j]) i ++;
    //     j ++;
    // }
    // if(s[i]) {
    //     return false;
    // } else {
    //     return true;
    // }

    // 力扣个个是人才
    if(!s) return true;
    const slen = s.length;
    for(let i = 0; i < slen; i ++) {
        const temp = t.indexOf(s[i]);
        if(temp >= 0) {
            t = t.slice(temp + 1);
        } else {
            return false;
        }
    }
    return true;





    //KMP
    // let pmv = computePMV(s);
    // // console.log(pmv)
    // const tlen = t.length, slen = s.length;
    // for(let i = 0, j = 0; i < tlen;) {//i为t中字符的位置，j为s中字符的位置
    //     if(t[i] !== s[j] && j === 0) i ++;//必须是j=0时i才能动
    //     while(t[i] === s[j]) {
    //         i ++, j ++;
    //     }
    //     if(j === slen) return true;//此时i-j就是匹配字符串的位置
    //     if(j !== 0) j = pmv[j - 1];
    // }
    // return false;

    // function computePMV(s) {
    //     let pmv = [0];
    //     const len = s.length;
    //     for(let i = 1; i < len; ) {
    //         let j = 0, times = 1;
    //         if(s[i] !== s[0]) {
    //             pmv[i] = 0;
    //             i ++;
    //         }else {
    //             while(s[i] === s[j]) {
    //                 pmv[i] = times;
    //                 i ++, j ++, times ++; 
    //             }
    //         }
    //     }
    //     return pmv;
    // }




    //下面是正则的解法，但太长的字符串会超时
    // s = s.split('');
    // s = '\w*' + s.join('\\w*') + '\w*';
    // s = new RegExp(s);
    // return !!s.exec(t);

    //一行代码，但是不是很好理解，上面的可读性更高
    // return !!new RegExp('\w*' + s.split('').join('\\w*') + '\w*').exec(t);
};
```