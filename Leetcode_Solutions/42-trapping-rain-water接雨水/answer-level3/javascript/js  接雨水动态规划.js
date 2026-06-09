### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    if(height.length<=2)return 0;
    let delta=[0];
    for(let i = 1; i < height.length;i++){
        delta[i]=height[i]-height[i-1];
    }
    let dp=[0,0];
    let maxi= height[0]>height[1] ? 0 : 1;
    for(let i = 2; i < height.length;i++){
        if(delta[i] <= 0){
            dp[i]=dp[i-1];
        }   
        else{
            let min;
            if(height[i] >= height[maxi]){
                min=height[maxi];
                let sum=0;
                for(let j = maxi+1; j < i;j ++ ){
                    if(height[j]>min){
                    sum+=min; 
                    }else sum+=height[j];
                }
                console.log(min,sum,dp[maxi]);
                dp[i]=min*(i-maxi-1) - sum + dp[maxi];
                maxi=i;

            }else{
                let k=i-1; //k是比height[i]大的前一个最近元素
                for(;i > 0 ;k--){
                    if(height[k]>=height[i])break;
                }
                min=height[i];
                let sum=0;
                for(let j = k+1; j < i;j ++ ){
                    sum+=height[j];
                }
                console.log(min,sum,dp[maxi]);
                dp[i]=min*(i-k-1) - sum + dp[k];
            }
            
        }
    }
    console.log(delta,dp);
    return dp.pop();
};
```