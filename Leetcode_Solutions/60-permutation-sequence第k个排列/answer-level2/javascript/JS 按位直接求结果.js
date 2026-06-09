### 解题思路
首先想一下如何构造排列，知道了如何构造排列，这道题也就答对了一半。
举例，n = 9时，k = 3000;
首先 9 排列，共有362880种，
1 ******** 40320种 0 ~ 40320项
2 ******** 40320种 40321 ~ 80640项
3 ******** 40320种 80641 ~ 120960项
4 ******** 40320种 120961 ~ 161280项
5 ******** 40320种 161281 ~ 201510项
7 ******** 40320种 1201511 ~ 241740项
8 ******** 40320种 以此类推。。。。
9 ******** 40320种 以此类推。。。。
 所以可以k的值确定，答案的每一位是多少。
```
    //此处是伪代码，答案代码在最下面
    if(k > 40320){  
        if( k % 40320 == 0){
            说明是整数倍，str[0] = arr[k / 40230 -1] 
            然后直接把直接就是 198765432（把arr数组逆序直接加上）
        }
        str[0] = floor(k / 40230)
    }
    if(k == 40320){
        说明是1 *******的最后一项，直接就是 198765432（把arr数组逆序直接加上）
    }
    if(k < 40320){
        说明是1 *******
        然后就可以用同样的方法确定第二项,
        12******* 0 ~ 5040
        12******* 5041 ~ 10080 
    }
    速度还可以，空间复杂度  O(n);
    由于使用了两个辅助数组 fact 和 arr
    但是长度是 常数长度 O(1);    
```
![fact.png](https://pic.leetcode-cn.com/8a1aa3151786302e82219d10f6eff300c90ddfdb721a1358b744e5aa59b0a3de-fact.png)

### 代码

```javascript
/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getPermutation = function(n, k) {
    if(k == 0){
        return "";
    }
    let fact =[0,1,2,6,24,120,720,5040,40320,362880];
    let i = 1;
    let str = "";
    let arr = [1,2,3,4,5,6,7,8,9];
    arr.splice(n);
    while(str.length < n){
        let now = fact[n - i];
        if(k < now){
            str += arr.shift();
        }else if(k > now){
            if(k % now != 0){
                let floor =  Math.floor(k / now);
                str += arr.splice(floor, 1);
                k -=  floor * now;
            }else{
                let pos =  k / now - 1;
                str += arr.splice(pos, 1);
                arr.reverse();
                str += arr.join(""); 
                return str;
            }
        }else{
           str += arr.shift();
           arr.reverse();
           str += arr.join(""); 
           return str;
        }
        i++;
    }
    return str;
};
```