显然，这是一类动态规划题目。既然是动态规划题目，就要考虑一下三个问题：
1. 动态规划的数组是一维还是二维的？里面的i，j参数表示什么？
2. 数组f[i,j]的值应当表示什么？
3. f[i,j]是怎么来的？
我们一步一步来看。
1.首先数组肯定是二维的，因为我们要考虑word1和word2的不同位置。
  那么就用i代表word1的位置，j代表word2的不同位置。
2.第二个问题，我们去看题目是什么，word1转化为word2最少的步数。
  显然，f[i,j]应当表示word1前i个元素，转化为word2前j个元素，需要的最少步数。
3.f[i,j]是怎么来的？
  **插入：**
  word1:x1,x2,...,xi
         ↓   经过一些编辑
中间word:y1,y2,...,yj-1  
         ↓   最后一次是插入yj元素
  word2:y1,y2,...,yj 
这时候我们只要插入yj，就实现了word1的前i个元素到word。
于是：f[i,j]=f[i,j-1]+1;
  **删除：**
 word1:x1,x2,...,xi                               
         ↓   经过一些编辑
中间word:y1,y2,...,yj,xi  
         ↓   最后一次是删除xi元素
  word2:y1,y2,...,yj
注意：word1到中间word就是f[i-1,j] 即word1:x1,x2,...,xi-1  →  word2:y1,y2,...,yj
即f[i,j]=f[i-1,j]+1;
  **替换：**
 word1:x1,x2,...,xi                               
         ↓   经过一些编辑
中间word:y1,y2,...,yj-1,xi  
         ↓   最后一次是把xi替换为yj元素
  word2:y1,y2,...,yj
word1到中间word，是把word1的前i-1个元素转化为word2的前j-1个元素。
注意：如果xi本身就等于yj,那么最后一步替换可以不需要。
即:f[i,j]=f[i-1,j-1]+(xi==yj?0:1);


下面我们开始写代码:
```
class Solution {
    public int minDistance(String word1, String word2) {
        int m=word1.length(),n=word2.length();
        int[][] f=new int[m+1][n+1];
        for(int i=0;i<=m;i++) f[i][0] = i-0;  //简单初始化，因为i变为0就是删掉这i个元素
        for(int i=0;i<=n;i++) f[0][i] = i-0;  //同理
        for(int i=1;i<=m;i++) 
            for(int j=1;j<=n;j++) {
                f[i][j]=min(f[i-1][j],f[i][j-1],f[i-1][j-1])+1; //插入删除和替换的最小值
                if(word1.charAt(i-1)==word2.charAt(j-1)) {     //不需要操作的情况
                    f[i][j]=Math.min(f[i][j],f[i-1][j-1]);
                }
            }
        return f[m][n];
    }
    public int min(int a,int b,int c) {
        if(a<b) return a<c?a:c;
        return b<c?b:c;
    }
}
```

