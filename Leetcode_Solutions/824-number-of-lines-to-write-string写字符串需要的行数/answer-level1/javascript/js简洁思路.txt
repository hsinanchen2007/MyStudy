### 解题思路
建立一个字符串记录a到z，用角标获取s中对应的长度，

### 代码

```javascript
/**
 * @param {number[]} widths
 * @param {string} S
 * @return {number[]}
 */
var numberOfLines = function(widths, S) {
    var chars="abcdefghijklmnopqrstuvwxyz";
    let index=0,sum=0,lines=1;

    for(i=0;i<S.length;i++){
        index=chars.indexOf(S[i]);console.log(index);
        sum+=widths[index];console.log(sum);
        if(sum>100){
            lines+=1;
            sum=widths[index];//总和超过100时，换行，并将该字符放在该行里
        }
    }
    return [lines,sum];
};
```