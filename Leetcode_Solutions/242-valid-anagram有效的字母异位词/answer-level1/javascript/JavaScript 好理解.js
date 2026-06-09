### 解题思路
![image.png](https://pic.leetcode-cn.com/c480a36d65b17836637997cffd6a3596ac0adfb9b1f8af2f5172982321745f75-image.png)
- 通过 obj 进行对单个字符进行计数
- 然后通过 for in 遍历对象，判断键值对是否相等

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    debugger;
    if(s.length != t.length) return false;
    let arrA = s.split('') 
    let arrB = t.split('')
    let objA = {}
    let objB = {}
     for(let i of arrA){
         objA[i] = !objA[i] ? 1 : ++objA[i]
     }
     for(let i of arrB){
         objB[i] = !objB[i] ? 1 : ++objB[i]
     }
    for(let i in objA){
        if(objA[i] == objB[i]){
            continue
        }else{
            return false
        }
    }
    return true
   
 }

```