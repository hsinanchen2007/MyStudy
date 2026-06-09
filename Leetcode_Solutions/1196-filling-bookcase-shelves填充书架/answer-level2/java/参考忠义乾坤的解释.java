```
// 将第i本书当做最后一本书，我们需要求i本书的最小高度dp[i]。
// 所以如果最后一本书放到新的一层中，dpi] = dp[i-1]+books[i-1][1]
// 最后一本书也可以和他前一本书一同放到新的一层。这时：dp[i] = dp[i-2] + max(books[i-1][1]，books[i-2][1])
// 这时我们应该考虑最后一本书一共和它的前面几本书放到新的一层呢？这样就可以采用试探来做，试探的终止条件就是前面没有书了或者是        当前层的宽度超出了最大宽度。记录这个过程中最小的dp[i]
// 状态转移方程： dp[i] = Math.min(dp[i],dp[m]+findMax(m,i,books)); 其中i的范围可参考程序
// 初始条件dp[0] = 0,一本书都没有最小高度肯定是0；dp[1] = books[0][1];计算顺序i从小到大。
class Solution {
    public int minHeightShelves(int[][] books, int shelf_width) {
        int []dp =new int[books.length+1];
        Arrays.fill(dp,10000000);
        dp[0] = 0;
        dp[1] = books[0][1];
        for(int i=2;i<books.length+1;i++){
         //计算dp[i]的最优值
         //超出最大宽度，当前和之前的书的最小index 
            int index = findMinIndex(i,books,shelf_width);
            if(index == 0){
                //全部能放下，则为1:i中书最高的一本
                dp[i] = findMax(0,i,books);
            }else{
                //第index本书，books[index-1]这本书放不下在当前层
                for(int m =index;m<i;m++){   
                 dp[i] = Math.min(dp[i],dp[m]+findMax(m,i,books));   
                }
            }
        }
        return dp[books.length];
    }
    //i代表第i本书，注意书下标从0开始
    public static int findMinIndex(int i,int[][] books,int shelf_width){
        int sum_width=books[i-1][0];
        while((--i)>=1){
          if(sum_width+books[i-1][0]<=shelf_width) 
              sum_width+=books[i-1][0];
            else{
                //返回的是该书已经放不下在最新层，给dp[i]
                return i;
            }
        }
        //前面没书，也就是0，全部可放在一层
        return i;
    }
    //找区间最大高度的书记，注意包含i点
    public static int findMax(int i,int j,int[][] books){
        int max = books[j-1][1];
        for(int k=i;k<j;k++){
            max =Math.max(books[k][1],max);
        }  
        return max;
    }
}
```
