### 解题思路
&emsp;&emsp;统计B集合种所有单词中单个字母出现的最大频次，拿去与A集合的单词比对即可。没必要用hashmap。

### 代码

```javascript []
/**
 * @param {string[]} A
 * @param {string[]} B
 * @return {string[]}
 */
var wordSubsets = function(A, B) {
    let check = new Array(26).fill(0),
        res = [];
    for(let i = 0; i < B.length; i++){
        let temp = new Array(26).fill(0);
        for(let j = 0; j < B[i].length; j++){
            temp[B[i][j].charCodeAt() - 97]++;
        }
        for(let j = 0; j < 26; j++){
            check[j] = Math.max(check[j], temp[j]);
        }
    }
    for(let i = 0; i < A.length; i++){
        let temp = new Array(26).fill(0),
            isRight = true;
        for(let j = 0; j < A[i].length; j++){
            temp[A[i][j].charCodeAt() - 97]++;
        }
        for(let j = 0; j < 26; j++){
            if(temp[j] < check[j]){
                isRight = false;
                break ;
            }
        }
        isRight && res.push(A[i]);
    }
    return res;
};
```