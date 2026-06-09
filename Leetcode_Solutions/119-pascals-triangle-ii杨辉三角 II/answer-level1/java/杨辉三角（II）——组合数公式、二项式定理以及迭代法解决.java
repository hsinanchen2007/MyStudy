### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> getRow(int rowIndex) {
        /*/方法1：和118题思路一样，采用递归法
        List<Integer> pre=new ArrayList<>();
        List<Integer> cur=new ArrayList<>();
        for(int i=0;i<=rowIndex;i++)
        {
            cur=new ArrayList<>();
            for(int j=0;j<=i;j++)
            {
                if(j==0||j==i)
                    cur.add(1);
                else
                    cur.add(pre.get(j-1)+pre.get(j));
            }
            pre=cur;
        }
        return cur; */
        
        //方法2：采用组合数公式，杨辉三角是二项式系数的展开
        List<Integer> ans=new ArrayList<>();
        int N=rowIndex;
        for(int k=0;k<=N;k++)
            ans.add(Combination(N,k));
        return ans;
    }
    private int Combination(int N,int K)  //组合数计算出来的阶乘可能非常大，这里res存储累乘之积需要用到long型
    {
        long res=1;
        for(int i=1;i<=K;i++)
        {
            res=res*(N-K+i)/i;
        }
        return (int)res;
    }
}
```