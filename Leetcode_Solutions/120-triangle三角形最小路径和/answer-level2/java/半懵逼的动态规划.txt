### 思路就是：先遍历最后一层，把所有的元素都赋值给dp;
然后从倒数第二层开始遍历；是以倒数第二层为基准的
每次dp等于该层的元素 + min下层的相邻两个元素（dp[i]和dp[i+1]）;
多次求解。那么最后的dp[0]就是最小总和

### 代码

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n=triangle.size();
        int [] dp=new int[n];
        //从最后一行往上找

        List<Integer> list1=triangle.get(n-1);
        for(int i=0;i<list1.size();i++){  //把最后一行的元素全部赋值到dp中
            dp[i]=list1.get(i);
        }
        for(int j=n-2;j>=0;j--){   //从倒数第二行开始
            List<Integer> list2=triangle.get(j);
            for(int i=0;i<list2.size();i++){
                dp[i]=list2.get(i)+Math.min(dp[i],dp[i+1]);

            }
        }
       return dp[0];
    }
}
//这道题的重点在于第三块的两个for循环
```