### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        //最终结果
        int res = 0;

        for(int i =0;i<manager.length;i++){
            //判断是否为结束点，剪枝
            if(informTime[i]==0){
                //临时值
                int temp = 0;
                int index=i;
                //向上遍历
                while(index!=-1){
                    temp+=informTime[index];
                    index=manager[index];
                }
                res = Math.max(res,temp);
            }
        }
        return res;
    }
}
```