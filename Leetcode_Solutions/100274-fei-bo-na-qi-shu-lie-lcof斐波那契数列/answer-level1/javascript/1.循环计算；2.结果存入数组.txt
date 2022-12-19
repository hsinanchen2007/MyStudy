### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    const mod=1e9+7;
    if(n==0) return 0;
    if(n==1) return 1;
    // 1.循环计算
    // var temp1=0,temp2=1,temp;
    // for(let i=2;i<=n;i++){ 
    //     temp=(temp1+temp2)%mod;         
    //     temp1=temp2;
    //     temp2=temp;       
    // }
    // return temp;
    
    // 2.存入数组
    var arr=[0,1];
    for(let i=2;i<=n;i++){
        let cur=(arr[i-1]+arr[i-2])%mod;
        arr.push(cur);
    }
    return arr[n];
};
```