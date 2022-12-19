### 解题思路
回文子串的对称轴有两种情况：中央字符或者是中央字符之间的间隔，取决于该字符串长度的奇偶。那对于长度为n的字符串，其中所有可能的回文子串对称轴应有2n-1个。
遍历每一个对称轴，由对称轴向两边依次检验左右字符是否相同，直到不同，即可得到该对称轴下最长的回文字符串，所有对称轴的最长回文串进行综合，就可以得到整个字符串中最长的回文子串。时间复杂度为n²，空间复杂度为1.

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    var longestS = s.slice(0,1), 
        longestL = 1;
    const L = s.length;
    // 遍历所有对称轴
    for(let i = 1;i<2*L-2;i++){
        let leftIndex,rightIndex;
        // 确立对称轴左右两侧字符的起始位置
        if(i%2===1){
            leftIndex=(i-1)/2,rightIndex=leftIndex+1;
        }else{
            leftIndex=i/2-1,rightIndex=leftIndex+2;
        }
        // 由内向外依次检测
        while(leftIndex>-1 && rightIndex<L && s[leftIndex]===s[rightIndex]){
            leftIndex--;
            rightIndex++;
        }
        leftIndex++,rightIndex--;
        // 回文子串比最大值长就记录下来
        let tempL = rightIndex-leftIndex+1;
        if(tempL>longestL){
            longestS = s.slice(leftIndex,rightIndex+1);
            longestL = tempL;    
        }
    }
    return longestS;
};
```