### 解题思路
![QQ截图20200405201906.png](https://pic.leetcode-cn.com/bc710d37d8ba8f6b4eb4ce8e946fe948992c5602753a692f70677417c1a4fee6-QQ%E6%88%AA%E5%9B%BE20200405201906.png)

先排序，再用300.最长上升子序列的DP方法一样的思路，用DP的做法排序的时候应该是依照pairs[i]的[0]处元素大小排，然后对排好序的数组，按照特定规则填DP表

设dp[i]表示**以pairs[i]这个数对作为结尾的最长链的长度**，最小为1
dp[i]=max{
if(pairs[i][0] > pairs[j][1]):dp[j]+1;其中0<=j<=i-1
//先保证以pairs[j]结尾的链加上pairs[i]后还是符合题意的数对链，再加1
}
注意不必统计以每一个数对结尾的可能的链长的最大值了，直接返回dp[n-1],因为排好序后，最后一个数对一定在最长的一条链上

累了，刷不动DP了，不久该转其他tag了
### 代码

```java
class Solution {
    public int findLongestChain(int[][] pairs) {
       int n=pairs.length;
        if(n==1) return 1;
        
        //先排序，再求最长数对链
        Arrays.sort(pairs,new Comparator<int[] >() {
            @Override
            public int compare(int[] A, int[] B) {//按数对里前面的那个数排序
                if (A[0] > B[0]) return 1;
                else if (A[0] < B[0]) return -1;
                else return 0;
            }
        });


        int [] dp_len=new int[n];//dp[i]表示以pairs[i]这个数对结尾的最长链的长度
        for(int i=0;i<n;i++) dp_len[i]=1;
        

        for(int i=1;i<n;i++){
            int temp = 1;
            for(int j=0;j<i;j++) {
                if (pairs[i][0] > pairs[j][1]) {//前面的链加上pairs[i]能组成链
                    temp=dp_len[j] + 1;
                }
                //不能组成链则使用默认值1
                if(temp>dp_len[i]){//以pairs[i]这个数对结尾的最长的可能
                    dp_len[i]=temp;
                }


            }
            
        }
        return dp_len[n-1];

    }
}
```