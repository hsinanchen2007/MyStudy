### 解题思路
此处撰写解题思路
一个人不可能同时出现在两个朋友圈，所以找过一个人后，记录一下，下次就不用找了。如果找到了一个人的朋友然后找与他的朋友相关的所有朋友，组成一个朋友圈。
### 代码

```java
class Solution {
    public int findCircleNum(int[][] M) {
        int n=M.length;
        int ret=0;
        boolean[]hashfind=new boolean[n];
        for(int i=0;i<n;i++){
            if(!hashfind[i]){
                dfs(M,i,hashfind);
                ret++;
            }
        }
        return ret;
    }
    private void dfs(int[][]M,int i,boolean[]hashfind){
        hashfind[i]=true;
        int n=M.length;
        for(int k=0;k<n;k++){
            if(M[i][k]==1&&!hashfind[k]){
                dfs(M,k,hashfind);
            }
        }
    }
} 
```