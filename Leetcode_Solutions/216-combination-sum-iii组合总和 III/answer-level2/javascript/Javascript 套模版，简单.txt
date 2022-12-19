### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} k
 * @param {number} n
 * @return {number[][]}
 */
var combinationSum3 = function(k, n) {
     let res = [];
     let temp = [];
     let backtrack=(temp,n,start)=>{
        
        if(k===temp.length&&n==0){
            res.push(temp);
            return;
        }
        for(let i=start;i<10;i++){
            temp.push(i)
            backtrack(temp.slice(),n-i,i+1);
            temp.pop();
            }
        }
     
     backtrack(temp,n,1);
     return res;
};
```