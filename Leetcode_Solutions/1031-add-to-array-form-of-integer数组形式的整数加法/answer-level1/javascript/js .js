### 解题思路
感觉这个题类似于js的大数加法   同样的思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/ed2bb1ee320becde1fd72b5ec9e3d6b839b62b9baa62319e1c8519daf5245d3f-image.png)

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} K
 * @return {number[]}
 */
var addToArrayForm = function(A, K) {
    let cin=0;
    let res="";
    let nums=String(K).split("");
    while(A.length||nums.length||cin){
        cin+=~~A.pop()+~~nums.pop();
        res=cin%10+res;
        cin=cin>9;
    }
   
    return res.split("")
};
```