### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @return {number}
 */
var minAddToMakeValid = function(S) {
    let cnt = 0;
    let res = 0;
    for(let i = 0; i < S.length; i++){
        if(S.charAt(i) == '('){ //每当遇到（，cnt++
            cnt++;
        }else if(S.charAt(i) == ')' && cnt > 0){//每遇到），cnt--，若cnt已经是0，表示缺少（，res++
            cnt--;
        }else{
            res++;
        }
    }
    return res + cnt;
//res表示多余的）缺少的（
//cnt表示多余的（缺少的）
};
```