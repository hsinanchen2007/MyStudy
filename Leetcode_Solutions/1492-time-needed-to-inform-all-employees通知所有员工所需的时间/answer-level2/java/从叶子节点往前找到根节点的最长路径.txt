
解题思路如题所示
```java
class Solution {}
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        int ans = 0;
        //找到叶子节点
        for(int i = 0; i < informTime.length; i++) {
            //等于0不一定是叶子节点
            //但是不等于0一定不是叶子节点  跳过
            if(informTime[i] != 0) continue;
            int temp = 0;
            int m = manager[i];
            while(m != -1) {
                temp += informTime[m];
                m = manager[m];
            }
            //更新答案
            ans = Math.max(ans, temp);
        }

        //返回答案
        return ans;
    }
}
```
