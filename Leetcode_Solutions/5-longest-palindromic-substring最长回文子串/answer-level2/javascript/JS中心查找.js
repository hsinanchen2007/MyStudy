### 解题思路
此处注意从中心往两边辐射的计算方式
注意有偶数的情况，偶数就是从两个数中间开始
while()的边界条件，左边可以===0

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    if(s == null || s.length <1){return ""}
    let start = 0;
    let len = 0;
    for(let i =0 ;i< s.length;i++){
        let len1 = recordLength(s, i,i)
        let len2 = recordLength(s, i,i +1)
        let temp = Math.max(len1, len2)
        if(temp > len){
            len = temp;
            if(len1 > len2){
                start = i- (len -1)/2
            }else{
                 start = i- (len)/2 +1
            }
            
        }
    }
    return s.substring(start ,start + len)
};

var recordLength = function(s, l, r){
    while(l >= 0 && r < s.length){
        if(s[l] == s[r]){
            l--;
            r++;
            continue;
        }
        break;
    }
    return (r- l -2) + 1
}
```