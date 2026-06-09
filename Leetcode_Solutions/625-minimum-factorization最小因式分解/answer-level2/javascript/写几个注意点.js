### 解题思路
写几个JS编译时的注意点：
    1、在查找可以被a整除的数的时候，要用while循环；比如输入25，目标结果是55；就用到了循环；
    2、32位有符号整数 范围是-2^31~2^31-1

### 代码

```javascript
/**
 * @param {number} a
 * @return {number}
 */
var smallestFactorization = function(a) {
    if(a<2){
            return a
        }
        let mul=0,temp=1
        for(i=9;i>=2;i--){
            while(a%i==0){
                a/=i;
                mul+=i*temp;
                temp*=10;
            }
        }
        return a<2&&mul<Math.pow(2, 31)?mul:0

};
```