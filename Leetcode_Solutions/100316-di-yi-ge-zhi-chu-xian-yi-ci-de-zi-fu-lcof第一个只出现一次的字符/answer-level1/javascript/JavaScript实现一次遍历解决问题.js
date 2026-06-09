### 解题思路
实现一次遍历解决问题，用两个数组，一个数组用来输出最后值，一个用来对已经出现两次的数进行标记

### 代码

```javascript
/**
 * @param {string} 
 * @return {character}
 */
var firstUniqChar = function(s) {
    var arr = s.split('')
    var a = [],b=[]
    arr.forEach(item=>{
        if(a.indexOf(item)<0){
            if( b.indexOf(item)<0){a.push(item)}           
        }else{
            a.splice(a.indexOf(item),1)
            b.push(item)
        }
    })
    if(a.length>0){
        return a[0]+""
    }else{
        return " "
    }
};
```