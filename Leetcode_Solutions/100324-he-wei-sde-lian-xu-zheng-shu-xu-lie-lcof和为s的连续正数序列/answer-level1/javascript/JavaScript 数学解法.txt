### 解题思路
根据等差数列求和公式 求出数列中项数最大为多少
（首+末）*项数=2*target
末项可表示为 首+项数-1，因此：
（2*首+项数-1）*项数=2*target
由于希望项数最大，所以此时首项应该为1：
（项数+1）*项数 =2*target
根据上式，可以得到项数最大应该为parseInt(Math.sqrt(2*target))

题目要求按照从小到大排列，所以循环从最大项数开始，逐步递减
由于项数为2时：n+（n+1)=target 首项n=（target-1)/2
项数为3时：n+(n+1)+(n+2)=target 首项n=(target-1-2)/3
以此类推 
项数为n时：首项n=(target-sum)/n,其中sum=(n*(n-1))/2

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    let sequence = [];
    let number_max = parseInt(Math.sqrt(2*target));
    let index = 0;
    let sum;
    let first_num;
    for (n=number_max;n>=2;n--){
        sum = (n*(n-1))/2;
        if((target-sum)%n == 0){
            first_num = (target-sum)/n;
            let each_sequence = [];
            for(i=0;i<n;i++){
                each_sequence.push(first_num+i);
            }
            sequence.push(each_sequence);
        }
    }
    return sequence;

};
```