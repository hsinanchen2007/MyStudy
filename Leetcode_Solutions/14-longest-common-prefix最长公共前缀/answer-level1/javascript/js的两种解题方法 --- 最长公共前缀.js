1. 第一种
```
var longestCommonPrefix = function(strs) {
    let r = ""
    let i = 1 //初始化参数
    
    if (strs.length === 0) {
      return ""
    }
    
    if (strs.length === 1) {
      return strs[0]
    }
    
    r = strs[0]
    
    for (; i < strs.length; i ++) { // 从第二个元素开始遍历
        let j = strs[i].split('')
        let j_i = j.length
        while (j_i >= 0) {	
           if(j.slice(0, j_i).join('') === r.split('').slice(0, j_i).join('')) { // 假设正好查到 公共的则返回
              r = j.slice(0, j_i).join('') 
			  break	
           } else { // 没有找到公共的则将参数减一
              j_i --
           }   
        }
    }
    
    return r
};

```

第二种：
```
var longestCommonPrefix = function(strs) {
     let result = ""; // 初始化结果
    if(strs.length === 0) {
       return "";
    } else {
       result = strs[0] // 将数组的第一位数赋值给result
        if(strs.length === 1) { // 长度为1的情况
           return result;
        }
       // 从第二位之后 ----> 跟前面的进行比较 取得相同的字符 (长度大于1的情况)
       let a = strs.slice(1);
       a.forEach(i => {
           let r = result.split('') 
		   let s = i.split('')
           // 得到 i 是 第n个数 然后切割成数组 一一比较
           let l = s.filter((f, d) => {
               return s[0] === r[0] && f === r[d]
           })
           result = l.join('')
       }) 
    }
    return result;
};

```