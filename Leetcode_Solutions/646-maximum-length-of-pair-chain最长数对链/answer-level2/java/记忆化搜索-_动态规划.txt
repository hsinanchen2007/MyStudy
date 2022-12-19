### 记忆化递归(不用排序)解题思路
1.这题和300.最长子序列不同，该题646.最长数对链的output与数对之间的**顺序无关**，也就是说`[1,2][2,3][3,4]`还是`[3,4],[2,3],[1,2]`,结果都是2
2.第300题的输出和数组元素之间的**顺序有关**,比如`[1,2,3] output=3`，而`[3,2,1] output=1`

3.先想到的是递归：用一维数组memo[i],表示`从pair[i]开始拼接，能凑出的最长上升链`
4.在递归过程中出现`比当前数对pair[i]更大`的数对`pair[k]`，就将`pair[k]拼接在pair[i]的后面`，再去找比pair[k]大的数对

5.因为数对之间是**无序**的，所以每次查找的范围都是`[0,len-1],len=pair.length`


### 动态规划(需要排序)解题思路
1.300题的状态转移方程`dp[i]=Math.max(dp[j]+1,dp[i])`可以继续使用，**前提是要排序**

2.dp[i]的意思是`以pair[i]作为结尾的最长链`，每到一个数对pair[i],尝试将`pair[i]放到前面的pair[j]的后面作为结尾`，
`j=[0,i)`,由此得到`dp[i]=dp[j]+1`，如果当前遍历pair[i]不能放到前面的pair[j]后面，由此得到dp[i]=dp[i]

### 记忆化递归代码
```
int[] memo;//从当前pair[i]开始拼接，能凑出的最长上升数对链
    public int findLongestChain(int[][] pairs) {
        if(pairs.length==0){
            return 0;
        }
        memo=new int[pairs.length];
        int maxLength=0;
        for(int i=0;i<pairs.length;i++){//依次尝试以[3,4],[2,3],[1,2]作为链的结尾，去找更大的数对[]来拼接在它们后面
            maxLength=Math.max(maxLength,recursion(pairs,pairs[i],i)); 
        }
        return maxLength;    
    }
    //curPos是目前以pair[curPos]作为链的结尾
    //cur[] 是当前链结尾的数对，如果有比cur[]还大的数对，就拼接在cur[]的后面
    private int recursion(int[][] pairs,int[] cur,int curPos){
        if(memo[curPos]>0){
            //出现过了
            return memo[curPos];
        }
        int ans=1;
        for(int i=0;i<pairs.length;i++){
            if(pairs[i][0]>cur[1]){//[3,4]的3>cur[1]=2 cur=[1,2]
                ans=Math.max(ans,1+recursion(pairs,pairs[i],i));
              //[3,4]拼接在[1,2]后面，[3,4]就作为结尾，继续找比[3,4]大的数对
            }
        }
        memo[curPos]=ans;
        return ans;
    }
```

### 动态规划代码
```java
class Solution {
    
    public int findLongestChain(int[][] pairs) {
        if(pairs.length==0){
            return 0;
        }
        //pair[i]作为结尾放在前面任意的数对后面，能组成最长链,和300不同，该题要排序才能和300题类似
        Arrays.sort(pairs,(a,b)->a[0]-b[0]);//以数对的head作为排序依据
        int[] dp=new int[pairs.length];
        Arrays.fill(dp,1);//每个pair[i]都可以让自己单独作为结尾,长度为1
        int maxLength=0;
        for(int i=0;i<pairs.length;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){//[3,4]的3>2 [1,2]
                    dp[i]=Math.max(dp[j]+1,dp[i]);
                }
                maxLength=Math.max(maxLength,dp[i]);//不管能不能放在pair[i]的后面，都要更新maxLength的值 
            }            
        }
        //最长上升子序列不一定以nums[len]为结尾,比如[[3,4],[2,3][1,2]]是以[3,4]作为结尾最长
        return maxLength;    
    }
    
}
```

