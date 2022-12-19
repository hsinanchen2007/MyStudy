### 解题思路
应该是深度优先吧，复杂度是n平方，对每一行进行计算。

对第n行进行计算时，使用方法为findNFriend(n);
对计算过的行进行标记。
计算时碰到某一个没有标记的值为1，则对这一行进行重新计算。

原函数中对每一行进行调用，调用发现未被标记，则计数加一。
最后返回计数。即是朋友圈数量。


### 代码

```java
class Solution {
    public int findCircleNum(int[][] M) {
        boolean[] flag = new boolean[M.length];
        int num=0;
        for(int i=0;i<M.length;i++){
            if(!flag[i]){
                num++;
                findNFriend(i,M[i],M,flag);
            }
        }
        return num;
    }
    
    public void findNFriend(int i ,int[] N,int[][] M,boolean[] flag){
        flag[i]=true;
        for(int j=0;j<N.length;j++){
            if(N[j]==1&&!flag[j]){
                findNFriend(j,M[j],M,flag);
            }
        }
    }
}
```