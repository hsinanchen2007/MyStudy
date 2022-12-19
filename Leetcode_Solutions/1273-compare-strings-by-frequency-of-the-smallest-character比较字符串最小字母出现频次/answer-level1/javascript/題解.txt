### 解题思路
先將words跑迴圈取出charCode最小者並計算次數後存入dictionary，再將queries跑迴圈取出charCode最小者並計算次數，
並依此跟dictionary中的次數做比較並計算次數，將次數存入res

### 代码

```javascript
/**
 * @param {string[]} queries
 * @param {string[]} words
 * @return {number[]}
 */
var numSmallerByFrequency = function(queries, words) {
    let dictionary=[];
    for(let i=0;i<words.length;i++){
        let temp=[];
        let word=words[i];
        for(let j=0;j<word.length;j++){
            let charCode=word.charCodeAt(j);
            if(temp[0]!=undefined){
                 if(charCode<temp[0]){
                     temp=[];
                     temp.push(charCode)
                 }else if(charCode==temp[0]){
                    temp.push(charCode)
                 }
            }else{
                temp.push(charCode)
            }
        }
        dictionary.push(temp.length);
    }
    let res=[];
    for(let i=0;i<queries.length;i++){
        let temp=[];
        let querie=queries[i];
        for(let j=0;j<querie.length;j++){
            let charCode=querie.charCodeAt(j);
            if(temp[0]!=undefined){
                 if(charCode<temp[0]){
                     temp=[];
                     temp.push(charCode)
                 }else if(charCode==temp[0]){
                    temp.push(charCode)
                 }
            }else{
                temp.push(charCode)
            }
        }
        let c=0;
        for(let j=0;j<dictionary.length;j++){
            if(dictionary[j]>temp.length){
                c++;
            }
        }
        res.push(c);
    }
    return res;
};
```