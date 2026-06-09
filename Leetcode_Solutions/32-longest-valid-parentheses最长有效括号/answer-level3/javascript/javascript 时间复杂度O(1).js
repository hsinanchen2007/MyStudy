### 解题思路
空间复杂度降为O(1)
执行时间缩减到接近 1/7
### 代码

```javascript
/**
 * 时间复杂度 O(n) 不能缩减了 毕竟都要遍历一次的吧？
 * 空间复杂度 降一下 O(1)
 * 对了 忘记提一点 【我之前不知道 可能大家都知道】
 * 偶然试了一下 s[i] 的方式也可以取得相应索引位置的 字符 理解为 类数组形式
 *    但是只支持访问 不支持修改删除 结合 Object.defineProperty 理解一下
 * 还有 s.charAt(i) 的方式 取字符
 * left --> right right ---> left 都要走一遍
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    let left = 0, right = 0, max = 0;
    for(let i = 0; i < s.length; i++){
        if( s[i] === '(' ){
            left++;
        }else if( s[i] === ')' ){
            right++;
        }
        if( left === right ){
            max = max > right * 2 ? max : right * 2;
        }else if(left < right){
            left = 0;
            right = 0;
        }
    }
    left = 0;
    right = 0;
    for(let i = s.length - 1; i >= 0; i--){
        if( s[i] === '(' ){
            left++;
        }else if( s[i] === ')' ){
            right++;
        }
        if( left === right ){
            max = max > right * 2 ? max : right * 2;
        }else if(left > right){
            left = 0;
            right = 0;
        }
    }
    return max;
};
```