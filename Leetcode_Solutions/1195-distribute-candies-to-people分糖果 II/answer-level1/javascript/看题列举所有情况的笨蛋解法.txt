### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function(candies, num_people) {
    let pre = 0;
    let ans = [];
    for(let i = 0;i<num_people;i++){
        ans[i] = 0;
    }
    function getCandies(){
        for(let i=0;i<num_people;i++){
        if(candies>0&&candies<pre+1){
            ans[i%num_people] = ans[i%num_people] + candies;
            candies = 0;
        }else if(candies<=0){
            ans[i%num_people] = ans[i%num_people] + 0;
            candies = 0;
        }else{
            ans[i%num_people] = ans[i%num_people] + pre+1;
            pre = pre+1;
            candies = candies - pre;
        }  
    }
    if(candies!=0){
        getCandies();
    }
    }
    getCandies();

    console.log(ans);
    return ans;
};
```