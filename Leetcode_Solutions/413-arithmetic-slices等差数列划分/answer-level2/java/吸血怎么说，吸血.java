### 解题思路
![QQ截图20200404192249.png](https://pic.leetcode-cn.com/84af0236a15cfba00bb8c96bb9b329038dc10974a2eff76e077d198d13aca6c9-QQ%E6%88%AA%E5%9B%BE20200404192249.png)

dp[i]表示以A[i]结尾的子数组的等差数列的个数
dp[i]={
dp[i-1]+1...if A[i]+A[i-2]==A[i-1]+A[i-1];
0...else
}

如果当前待检查元素与它前面的两个能构成等差关系，那么以A[i]为结尾的等差数列的个数dp[i]是dp[i-1]+1，因为多读入一个数，就代表多了一种可能的组合，实际上若dp[i-1]！=0时，就是在在终点指针end固定（指向i）的情况下，选择所有可能的起始指针start,使end-start+1>=3，每当终点指针向后走一步，start也就多了一种可能，所以在dp[i-1]的基础上+1。
若dp[i-1]==0，即使以A[i-1]结尾的数组构不成等差数列，但A[i]和它前面的两个元素可以构成等差数列，dp[i]就为1，也是dp[i-1]+1；


如果当前元素与它前面的两个元素构不成等差关系，那么以当前元素结尾的子数组不存在等差数列，即dp[i]=0,因为只要是以A[i]结尾，想要构成等差数列必然包含A[i-1]和A[i-2],包含不等差数列的数列不可能是等差数列，所以直接为0


之所以这样定义状态，是因为所有可能的等差数列都一定是以A中的某一个元素A[i]为结尾的（i>=3)，把所有可能的等差数列结尾的情况下的等差数列个数相起来，即解值sum


建议和718.最长公共子数组问题放一起做，体会“**以当前元素结尾的XXX**”的状态定义的方法

### 代码

```java
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        if(A.length<3) return 0;
        if(A.length==3) return A[2]-A[1]==A[1]-A[0]?1:0;
        int n=A.length;
        int [] dp_num=new int[n];//dp_num[i]:以A[i]结尾的等差数列的个数
        int sum=0;
        //因为等差数列最短长度为3，所以从第三个元素为结尾的子数组开始初始化
        dp_num[2]=A[2]+A[0]==A[1]+A[1]?1:0;
        sum=dp_num[2];
        for(int i=3;i<n;i++){//以A[i]结尾的等差数列
            if(A[i]+A[i-2]==A[i-1]+A[i-1]){
                dp_num[i]=dp_num[i-1]+1;
                sum+=dp_num[i];
            }
            else dp_num[i]=0;
        }
        

        
        return sum;
        

    }
}
```