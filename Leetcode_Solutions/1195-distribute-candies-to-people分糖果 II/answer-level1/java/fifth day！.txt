### 解题思路
执行用时 :1 ms, 在所有 Java 提交中击败了90.51%的用户
内存消耗 :36.9 MB, 在所有 Java 提交中击败了5.27%的用户
比较暴力的解法了
设置数组存放结果
设置n存放当前分的糖的数目
temp变量存放特殊情况中那个人在数组中的位置（剩余的糖数小于n）
### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans=new int[num_people];
        int n=1;
        int temp=0;
        while(candies>0)
        {
            for(int i=0;i<num_people;i++)
            {
                ans[i]+=n;
                candies-=n;
                n++;
                if(candies<n)//特殊情况跳转
                {   temp=i+1;
                    break;}
            }
            if(candies<n)//将剩余的糖都分配给当前被分配的人
            {
            ans[temp%num_people]+=candies;
            candies=0;
            }
        }
       return(ans);
    }
}
```