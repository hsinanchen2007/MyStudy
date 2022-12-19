### 解题思路
方法一、反转 + 排序 + 字符串查找

### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var minimumLengthEncoding = function(words) {
    var N = words.length;
    var arr=new Array();
//反转字符串
    for(var i=0;i<N;i++){
        arr[i] = words[i].split("").reverse().join("");
    }
//字符串排序
    arr.sort();
    var res=0;
    for(var i=0;i<N;i++){
//排序后的字符串，在下一个字符串中查找当前字符串，如果找到并且索引位置为0，说明当前字符串是下一个字符串的后缀，不需要计数
        if(i+1<N && arr[i+1].search(arr[i])==0){

        }else{
            res += arr[i].length +1;
        }
    }
    return res;
};
```
方法二、Set、切片、has()、delete()
```
var minimumLengthEncoding = function(words) {
//首先使用 Set 去除重复的单词，则在set中的单词肯定都不重复
    var hashset = new Set(words)
// for..of 是遍历值，for..in 是遍历属性
    for(var item of hashset){
//由于单词都不重复，直接从每个单词的第二个字母到结尾做切片，在Set 中查找，如果找到就删除
        for(var i=1;i<item.length;i++){
            var target = item.slice(i);
            if(hashset.has(target)){
                hashset.delete(target);
            }
        }
    }
// 遍历统计所有的长度即可
    var res=0;
    hashset.forEach(item =>{
        res += item.length+1;
    })
    return res;
};
```
