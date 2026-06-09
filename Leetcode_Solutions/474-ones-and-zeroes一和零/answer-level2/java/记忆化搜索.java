### 0-1背包递归写法
记忆化递归这儿没有状态转移方程，对于每个字符串"10","0001"都有选和不选两种可能，如果不选"10"就跳到下一个字符串"0001"开始重新做选择。

遗憾的是没能把三维的数组变成二维的，迭代写法的动态规划却可以，如果有知道递归写法的优化二维数组的小伙伴能否分享一下，谢谢哈

记忆化递归的写法的时空复杂度虽然和迭代的写法差不多，但是执行用时却不尽人意
![474一和零的递归写法.PNG](https://pic.leetcode-cn.com/d3ed1cd967ed5ee1c6b0498559fcc30890337d28e02f150f9ca0ebbd810a96e1-474%E4%B8%80%E5%92%8C%E9%9B%B6%E7%9A%84%E9%80%92%E5%BD%92%E5%86%99%E6%B3%95.PNG)

### 代码

```java
class Solution {
    int[][][] memory;//容量为m,n的情况下，在搜索区间[0,i],i=0,1,2,3... 能够拼接出最多的字符串
    int len;
    public int findMaxForm(String[] strs, int m, int n) {
        
        len=strs.length;
        memory=new int[m+1][n+1][len];
        for(int i=0;i<memory.length;i++){
            for(int j=0;j<memory[0].length;j++){
                Arrays.fill(memory[i][j],-1);// -1:未出现过 
            }          
        }
        
        return recursion(m,n,len-1,strs);//从末尾开始搜索
    }
    
    private int recursion(int Mrest,int Nrest,int cur,String[] strs){
        if(cur<0){//遍历到数组越界,但m,n有剩余的
            
            return 0;

        }               
        if(memory[Mrest][Nrest][cur]!=-1){
            return memory[Mrest][Nrest][cur];
        }
        int[] count=countZeroAndOne(cur,strs[cur]);//统计字符串的'0'和'1'的数量
        int cost_zero=count[0];
        int cost_one=count[1];
        if(Mrest>=cost_zero&&Nrest>=cost_one){
            int select=1+recursion(Mrest-cost_zero,Nrest-cost_one,cur-1,strs);//选
            int no_pick=recursion(Mrest,Nrest,cur-1,strs);//不选
            memory[Mrest][Nrest][cur]=Math.max(select,no_pick);//选与不选的较大值
        }else{
            //m,n有一个不满足消耗cost的要求,就不能选择
            memory[Mrest][Nrest][cur]=recursion(Mrest,Nrest,cur-1,strs);
        }
        return memory[Mrest][Nrest][cur];
    }

    private int[] countZeroAndOne(int cur,String str){//统计每一个字符串的'0'和'1'的数量
        int[] count=new int[2];
        for(char c:str.toCharArray()){
            count[c-'0']++;
        }
        return count;
    }   
}
```