### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
       
    public int numberOfBoomerangs(int[][] points) {
        int res = 0;
        for(int i = 0;i < points.length;i++){

            Map<Integer,Integer> record = new HashMap<>();
            for( int j = 0; j < points.length; j++){
                if(j != i){
                    int temp=dis(points[i],points[j]);
                    record.put(temp,record.getOrDefault(temp,0)+1);
                }
            }

            for(Map.Entry entry : record.entrySet()){
                int x=(int)entry.getValue();
                res += (x*(x-1));
            }

        }
        return res;
    }

    private int dis(int[] pa,int[] pb){
        return (pa[0]-pb[0])*(pa[0]-pb[0])+(pa[1]-pb[1])*(pa[1]-pb[1]);
    }
}
- 找出所有2个点的距离平方，加入map中，对值做更改。
- TreeMap会比HashMap消耗更多时间
- 时间o n2
- 空间o n