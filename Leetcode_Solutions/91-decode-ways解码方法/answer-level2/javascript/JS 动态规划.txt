### 解题思路
方法一 
动态规划
这种题其实都和爬楼梯很像，无非是爬楼梯可以选择走两步或者一步，但是解码 或者 像93题的IP划分这样的题，能走几步得讨论一下。
这道题分为两种情况，一种是比较特殊得s[i] = 0，一种是其他数字。
1.    首先，0 作为一个独立个体不能产生效益（0不对应任何字母，且0X 也不对应任何字母，30，40 ，...都不对应任何字母，所以0是一个残障人士）所以在这里不能一步走过来，
只能两步跳过来，并且只有前面是 1 || 2这样得大哥得时候（10，20 有对应得字母）才能跳两步，此时dp[i] = dp[i-2]不然就走不了，直接返回0；
2. 除了零，此项是任何数字都可以至少走一步，因为自身就对应得一个字母 所以 至少有 dp[i] = dp[i-1]
    此时如果前面一位为2，而当前位置为1~6，或者是前面一位为1，那么多了一种选择，可以组合再一起生成一个字母，相当于跳了两步，此时多了一个选择， dp[i] = dp[i-1] + dp[i-2];
    如果前面s[i-1]大于2, 或者(s[i-1] = 2,且 6 < i),则无法多生成一个码，此时也无法走两步，只能走一步，dp[i] = dp[i-1];
### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var numDecodings = function(s) {
    if(s.length <= 0 || s == "0" || s[0] == 0 ){
        return 0;
    }
    let dp = [];
    dp[0] = 1;
    dp[-1] = 1;
    for(let i = 1; i < s.length; i++){
        if(s[i] == "0"){
            if(s[i-1] == "1" || s[i-1] == "2"){
                dp[i] = dp[i-2];
            }else{
                return 0;
            }
        }else{
            if(s[i-1] == "1" || (s[i-1] == "2" && s[i] <= 6 && s[i] >= 1)){
                dp[i] = dp[i-1] + dp[i-2];
            }else{
                dp[i] = dp[i-1]
            }
        }
    }
    return dp.pop();
};
```
方法二
回溯，此处超时，思路很简单，一点一点的剪，这里不细说，主要看第一种方法。
```javascript
    if(s.length <= 0 || s == "0"){
        return 0;
    }
    let count = 0;
    function helper(s){
        if(s.length >= 2){
            if(s[0] != "0"){
                helper(s.slice(1))
            }
            if(s.slice(0,2) <= 26 && s.slice(0,2) >= 10){
                helper(s.slice(2));
            }
        }else if(s.length == 1){
            if(s != "0"){
                helper(s.slice(1))
            }
        }else if(s.length == 0){
            count++;
        }
    }
    helper(s);
    return count;
```