### 解题思路
特殊情况:
    1.A、B长度不等或任一长度小于2，return false
    2.A==B，如果任一字符串内存在重复字符，return true;
特殊情况之外:
    按位比对不相同的字符个数，不为2则 return false，若为2 且 A[i]==B[j]&&A[j]==B[i]则 return         true,否则 return false
### 代码

```javascript
/**
 * @param {string} A
 * @param {string} B
 * @return {boolean}
 */
var buddyStrings = function(A, B) {
    if(A.length<2 || A.length!==B.length){
        return false;
    }
    if(A===B){
        if(hasSame(A)){
            return true;
        }
    }
    let c = 0;
    let a = [];
    for(let i=0; i<A.length; i++){
        if(A[i]!==B[i]){
            a[c] = i;
            c += 1;
            if(c>2){
                return false;
            }
        }
    }
    if(c<2){
        return false;
    }else{
        if(A[a[0]]===B[a[1]] && A[a[1]]===B[a[0]]){
            return true;
        }else{
            return false;
        }
    }
};
function hasSame(str){
    let c = 0;
    for(let i=0; i<str.length-1; i++){
        for(let j=i+1; j<str.length; j++){
            if(str[i]===str[j]){
                c += 1;
                return true;
            }
        }
    }
    if(c===0){
        return false;
    }
}
```