### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] highFive(int[][] items) {
        int n=items.length;
        Map<Integer,int []> m=new HashMap<>();
        for(int i=0;i<n;i++)
        {
            int idx=items[i][0],  score=items[i][1];
            int [] cur;
            if(!m.containsKey(idx)){
                cur=new int[]{0,0,0,0,0};
                m.put(idx,cur);
            }
            else
            {
                cur=m.get(idx);
            }
            //维护一个长度为5的升序序列并记录最大的5个数
            if(score<=cur[0])
                continue;
            cur[0]=score;
            if(cur[0]>cur[1])  swap(cur,0,1);
            if(cur[1]>cur[2])  swap(cur,1,2);
            if(cur[2]>cur[3])  swap(cur,2,3);
            if(cur[3]>cur[4])  swap(cur,3,4);
        }
        int [][] res=new int[m.size()][2];
        for(int i=1;i<=m.size();i++)
        {
            int sum=0;
            for(int e:m.get(i))
                sum+=e;
            res[i-1][0]=i;
            res[i-1][1]=sum/5;
        }
        return res;
    }

    void swap(int []a ,int x,int y)
    {
        int t=a[x];
        a[x]=a[y];
        a[y]=t;
    }
}
```