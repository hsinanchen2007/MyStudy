### 解题思路
考虑使用两个数 small和big表示序列的最小值和最大值，初始化为1和2。如果从small到big的和大于target，去掉最小值，也就是增加small，如果和小于target，增加big。因为序列至少包含两个数，我们增加small一直到(1+target)/2为止。
### 代码

```java
class Solution {
    List<List<Integer>> list = new ArrayList<>();
    public void addList(int small,int big){
        List<Integer> res = new ArrayList<>();
        for(int i = small;i<=big;i++){
            res.add(i);
        }
        list.add(res);
    }
    public int[][] findContinuousSequence(int target) {
        if(target<3) return null;
        int small = 1,big = 2;
        int middle = (1+target)/2;
        int curSum = small+big;
        while(small<middle){
            if(curSum==target){
                addList(small,big);
            }
            while(small<middle&&curSum>target){
                curSum-=small;
                small++;
                if(curSum==target){
                    addList(small,big);
                }
            }
            big++;
            curSum+=big;
        }
        int [][] res = new int[list.size()][];
        for(int i = 0;i<list.size();i++){
            int [] tmp = new  int[list.get(i).size()];
            for(int j = 0;j<tmp.length;j++){
                tmp[j] = list.get(i).get(j);
            }
            res[i] = tmp;
        }
        return res;
    }
}
```