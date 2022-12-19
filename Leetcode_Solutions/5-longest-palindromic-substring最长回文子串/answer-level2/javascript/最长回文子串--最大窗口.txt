一个循环语句，
1. 通过设置窗口ck来从长到短比较出最长的回文数，
2. 首先ck的大小为 s.length, 能够比较的次数times为s.length-ck次，
3. 然后比较k和d对应位置的值，如果不相等 
                                    判断times是否为0，
                                            为0则缩小窗口，
                                            不为零，通过i,j移动窗口，直到times为0，
                            如果相等，判断是否是回文数，
                                是回文数,返回回文数
                                不是继续times的判断

```
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    if(s.length === 0){
        return s;
    }
    var i = 0,j = s.length - 1; // 通过 i,j 来移动窗口
    var k = 0; // 通过 k,d 来比较是不是回文数
    var d = j;
    var ck = s.length; // 窗口大小
    var times = 0; // 每个窗口下有几次比较的机会
    while(k<d)  {
        if(s[k] === s[d]) {
            k++;
            d--;
        }else {
            if(times <= 0) {
                ck --;
                i = 0;
                j = i + ck -1;
                times = s.length - ck;
            }else {
                i ++;
                j ++;
                times --;
            }
            k = i;
            d = j;
        }
    }
    return s.slice(i,j+1);
};
```
