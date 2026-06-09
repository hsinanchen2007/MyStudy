### 解题思路
根据等差数列求和公式 求出数列中项数最大为多少
（首+末)*项数=2*target
末项可表示为 首+项数-1，因此：
（2*首+项数-1)*项数=2*target
由于希望项数最大，所以此时首项应该为1：
（项数+1)*项数 =2*target
根据上式，可以得到项数最大应该为parseInt(Math.sqrt(2target))

循环从项数为1开始，逐步递增，直到最大项数
由于项数为2时：n+（n+1)=target 首项n=（target-1)/2
项数为3时：n+(n+1)+(n+2)=target 首项n=(target-1-2)/3
以此类推
项数为n时：首项n=(target-sum)/n,其中sum=(n*(n-1))/2

只需判断首项是否为正整数，即可得知本组是否成立

### 代码

```javascript
/**
 * @param {number} N
 * @return {number}
 */
var consecutiveNumbersSum = function(N) {
    let number=0;
    let number_max = parseInt(Math.sqrt(2*N));
    let sum;
    for (n=1;n<=number_max;n++){
        sum = (n*(n-1))/2;
        if((N-sum)%n == 0){
           number++; 
        }
    }
    return number;
};
```