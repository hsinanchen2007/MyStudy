### 解题思路
简单用一个数组来存储所有的人物信息，分几种情况，第一种相信别人的则标记之后再也不会被标记为法官，第二种被相信的人若相信别人则被标记为平民，一直未相信别人的人可能是法官，存好被相信的人的个数，遍历一遍数组，最后判断条件是不相信别人的人，不被相信的人不存在，只能有一个法官；
未考虑边界情况，即当N=1时，表示是法官

### 代码

```java
class Solution {
    public int findJudge(int N, int[][] trust) {
        if(N==0){
            return -1;
        }
        if(N==1&&trust.length==0){
            return 1;
        }
        int[] person=new int[N];
        for(int i=0;i<trust.length;i++){
            person[trust[i][0]-1]=-1;
            if(person[trust[i][1]-1]!=-1)
                person[trust[i][1]-1]++;
        }
        int fa=0;
        int which=0;
        int no=0;
        for(int i=0;i<N;i++){
            if(person[i]>0){
                fa++;
                which=i+1;
            } else if(person[i]==0){
                no++;
            }
        }
        if(no==0&&fa==1&&person[which-1]==(N-1)){
            return which;
        } 
        return -1;
    }
}
```