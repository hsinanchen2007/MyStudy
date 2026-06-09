### 解题思路
定义left和right分别指向数组第一个值和最后一个值的下标。定义temp指向right对应值，接下来将temp向左移动，直到temp刚好指向left+1处。这个过程寻找到所有符合条件的且包含最左边和最右边值的集合个数。

之后将right--，重复上述步骤，直到找到所有符合条件的包含第一个值的集合个数。再将left++，重复以上所有步骤。
![image.png](https://pic.leetcode-cn.com/a9995143d4df43b6419e1c999f1d9cabf5290a0b05d7db10ea591908811379e6-image.png)


### 代码

```javascript
/**
 * @param {number[]} rating
 * @return {number}
 */
var numTeams = function(rating) {
    let left,right,
        n=rating.length,
        count=0;
   if (n>=3) {
    for(let i=0;i<=n-3;i++){
        left=i;
        right=n-1;
        while(right>=(left+2)){
             if(rating[right]>rating[left]){
                let temp=right;
                 while(temp>(left+1)){
                    temp--;
                    if(rating[right]>rating[temp]&&rating[temp]>rating[left]){ 
                     count++; 
                     }
                }   
            }
            else if(rating[right]<rating[left]){
            let temp=right;
             while(temp>(left+1)){
                temp--;
                if(rating[right]<rating[temp]&&rating[temp]<rating[left]){
                 count++; 
                }
              }   
            }
            right--;
        }
   }
   }
    return count;

};
```