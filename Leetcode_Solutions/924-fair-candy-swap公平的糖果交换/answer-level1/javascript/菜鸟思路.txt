### 解题思路
此处撰写解题思路
1、计算两个小朋友当前拥有
2、计算两个小朋友总共拥有
3、计算交换后两个小朋友分别拥有
4、计算当前拥有与交换后拥有差值
5、判断哪个小朋友的糖多，遍历寻找匹配项，如果一个小朋友的某块糖减去差值在另一个小朋友的那里有匹配，就压入res，压入顺序要稍微注意
### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number[]}
 */
var fairCandySwap = function(A, B) {
    let res = []
    // 1计算两边个分别拥有大小
    let resA = eval(A.join('+'))
    let resB = eval(B.join('+'))
    let total = resA + resB
    // 2计算总大小，交换后两人必须拥有多少
    let changed = Math.round(total / 2)
    // 3计算差
    let diff = 0
    if(resA > resB){
        diff = Math.abs(changed - resA)
        for(let i=0; i<A.length; i++){
            if(B.indexOf(A[i]-diff) > -1){
                res.push(A[i], B[B.indexOf(A[i]-diff)] )
                return res
            }
        }
    }else{
        diff = Math.abs(changed - resB)
        for(let j=0; j<B.length; j++){
            if(A.indexOf(B[j]-diff) > -1){
                res.push(A[A.indexOf(B[j]-diff)], B[j])
                return res
            }
        }
    }
    // console.log(res)
    return 0
};
```