### 解题思路
此处撰写解题思路
在这里首先想到的是用对象的key去存储相同字符，结果发现如果出现haha情况那么仍然存值为两个
于是又想到了加了一个递增数字以确保唯一性，可以优化的地方比如如果length不相同直接跳过步骤二返回最终不匹配结果，这样依赖就可以避免浪费调用了，看到一个大佬写的正则匹配，感觉真厉害。
### 代码

```javascript
/**
 * @param {string} S
 * @param {string[]} words
 * @return {number}
 */
var expressiveWords = function (S, words) {
    let count=0;
    for(let i=0;i<words.length;i++){
        if(comCnt(S,words[i])){
            count++
        }
    }
    return count;
};
 function ownChange(attr) {
            let obj = {};
            let num=0;
            let arr = [...attr.split('').join('')];
           for(let i=0;i<arr.length;i++){
            if(!obj[arr[i]+num]){
                obj[arr[i]+num]=1
            }
            if(arr[i]==arr[i+1]){
                obj[arr[i]+num]+=1;
            }else{
                num++;
            }
           }
           //console.log(obj)
            return obj;
        }
function comCnt(s,words) {
    let obj = ownChange(s);
    let obj2 = ownChange(words)
    let res=true;
    let count=0;
    for (var key in obj) {
     if(obj[key]-obj2[key]>=2||obj[key]==obj2[key]){
         count++
     }else if(obj[key]>obj2[key]&&obj[key]>2){

     }else{
         count++
         res=false
     }
    }
    if(count>1){

    }else{
        res=false
    }
    return res;
}
```