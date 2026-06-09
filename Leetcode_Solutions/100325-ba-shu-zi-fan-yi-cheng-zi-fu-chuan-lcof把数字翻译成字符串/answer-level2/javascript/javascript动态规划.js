
思想就是：当一个数和它前面的数组成的数在0-25之间的时候，对翻译数目有增益，此时dp[i]=dp[i-1]+dp[i-2]
相反组成的数不在0-25之间，对翻译数目无增益，dp[i]=dp[i-1]
```
var translateNum = function(num) {
  let s=num.toString();
  let dp=new Array(s.length+1).fill(1);
  for(let i=1;i<s.length;i++){
    if(s[i-1]=='1'||(s[i]<=5&&s[i-1]=='2')){
      dp[i+1]=dp[i]+dp[i-1];
    }else{
      dp[i+1]=dp[i]
    }
  }
  return dp[s.length]
};
```
