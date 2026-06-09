### 解题思路
实际上就是简单的等差数列求和公式的逆运用。已知 S=n*a1+n*(n-1)*d/2，本题中S=target，d=1。因此求解出a1，再使用a1列出an序列放入链表中即可。最后在返回之前将链表逆序。
### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        //等差数列求和公式为 S=n*a1+n*(n-1)*d/2  d=1
        int a1=0;
        int temp=0;
        List<int[]> res = new ArrayList<>();
        for(int n=2;;n++){
            temp=target-(n*(n-1)/2 );
            if(temp<=0)break;
            if(temp%n==0){
                a1=temp/n;
                int [] ans=new int[n];
                for(int i=0;i<n;i++){
                    ans[i]=a1+i;
                }
                res.add(ans);
            }
        }
        Collections.reverse(res);
        return res.toArray(new int[res.size()][]);
    }
}
```