### 解题思路
先处理边界问题：零修改以及相差大于2的情况 
中心思想:
相等- 逐个字母比较，差异大于2，则false
不相等-找到不相等的下标，往差异处插入字符、删除字符，再比较是否一致，一致则true
![image.png](https://pic.leetcode-cn.com/c73b2e1977b76edd7e93bf38ce511919f00b4f0340c57799cabc2f20714a79a0-image.png)


### 代码

```javascript
var oneEditAway = function(s1, s2) {
    const s1Len = s1.length
    const s2Len = s2.length

    if(s1===s2) return true
    if(Math.abs(s1Len-s2Len) >= 2) return false;
//  相等
    if(s1Len === s2Len){
        let count =0;
        s1.split('').forEach((item,index)=>{
            if(item !== s2[index]){
                count++
            }
        })
        return count < 2 ? true :false 
    }
//  不等
    let Long = s1Len > s2Len ? s1Len : s2Len
    let s2Arr = s2.split('')
    for(let i= 0;i<Long;i++){
        if(s1[i] !== s2[i]){ 
            if(s1Len > s2Len){
                s2Arr.splice(i,0,s1[i])
                return s1 === s2Arr.join('') ? true :false
            }else{
                s2Arr.splice(i,1)
                return s1 === s2Arr.join('') ? true :false
            }

        }
    }
};
```