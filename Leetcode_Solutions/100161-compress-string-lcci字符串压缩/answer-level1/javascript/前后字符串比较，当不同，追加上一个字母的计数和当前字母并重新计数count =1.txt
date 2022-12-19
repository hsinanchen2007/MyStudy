### 解题思路
中心思想:从s[1]开始与前一位进行比较
同- count++ 计数加一
不同- 记录当前不同字母，并重新计数 count=1

### 代码
![image.png](https://pic.leetcode-cn.com/57372d73fde48f660934bd9f7a7569ff2bfb8f274a694d65a03490f5777a3dc7-image.png)


```javascript
var compressString = function(s) {
    let count = 1; 
    let arr = [].concat(s[0])

    for(let i =1;i<s.length;i++){
        if(s[i-1] === s[i] ){
            count++;
        }else{
            arr.push(count)
            arr.push(s[i])
            count =1
        }
        if(i === s.length-1){
           arr.push(count)
        }
    }
    return arr.length < s.length ? arr.join('') : s
};
```