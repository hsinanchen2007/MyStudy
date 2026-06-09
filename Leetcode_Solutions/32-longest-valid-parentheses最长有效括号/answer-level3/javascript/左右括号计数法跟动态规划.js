### 解题思路
1.左右计数器方法
2.动态规划方法

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    //分别定义一个左右括号的计数器及最长有效果括号长度
   let left=0,right=0,maxLen=0;
   //从头开始遍历字符串
   for(let i = 0;i<s.length;i++){
       if(s[i]==='(') {
           left++
       }else{
           right++
        }
        //当出现左右括号数量相等时，则当前有效括号长度为left+right
        if(left===right){
            //判断当前最长值是否为最长有效值
            maxLen=Math.max(maxLen,right * 2)
        //当出现有括号的值大于左括号时，则代表出现了多余的括号，第i位数前的最长有效值已计算完，重新开始计算第i位数后面最长有效值
        }else if(right>left){
            left=0
            right=0
        }
   }
    // 从右往左再来一次
   right=0
   left=0
   for(let j=s.length-1;j>0;j--){
       if(s[j]===')'){
           right++
       }else{
           left++
       }
       if(left===right){
           maxLen=Math.max(maxLen,left * 2)
       }else if(left>right){
           left=0
           right=0
       }
   }
   return maxLen
};

//动态规划版本
var longestValidParentheses2 = function(s) {
    const arrLen = s.length
    if(arrLen<2) return 0
    //创建一个等长数组用于标记当前有效长度，初始全部值为0
    let countArr = new Array(arrLen).fill(0)
    for(let k=0;k<=arrLen-1;k++) {
        if(s[k]===')'){
            if(s[k-1]==='('){
                //当出现一个有效括号时，则其有效长度为k-2位前的有效括号+当前有效括号（值2），因为括号是两位的，所以上一个有效括号应该是k-2
                countArr[k]=k-2>0?countArr[k-2]+2:2
                //当出现两个右括号时，即两个闭口，则判断其有效长度前1位是否为左括号，既开口
            }else if(s[k-1]===')' && s[k-countArr[k-1]-1]==='('){
                //若是，则代表这两个括号有效（+2）
                countArr[k]=countArr[k-1]+2
                //加上此时有效括号前的有效括号数，如()(())    ===>   ()+(())
                if((k-countArr[k-1]-2)>0) {
                    countArr[k]=countArr[k]+countArr[k-countArr[k-1]-2]
                } 
            }
        }
    }
    countArr.sort((a,b)=>a-b)
    return countArr[arrLen-1]
};
```
