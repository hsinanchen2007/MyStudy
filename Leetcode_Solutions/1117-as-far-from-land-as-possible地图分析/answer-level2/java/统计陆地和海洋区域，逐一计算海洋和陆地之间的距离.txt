![l.png](https://pic.leetcode-cn.com/1ee19aaf3fe6fe6b583a5c4eef8e31c2df21dde32203fbbd35b4890362705434-l.png)


### 解题思路
1、先统计所有的陆地和海洋区域
2、对于每一个海洋区域，计算它和所有陆地区域之间的距离，保留最小值
3、所有海洋区域对应的最小值取最大值即为题目所求

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        List<Integer[]> lands=new ArrayList();
        List<Integer[]> seas=new ArrayList();
        //统计所有的陆地和海洋
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==0){
                    seas.add(new Integer[]{i,j});
                }else{
                    lands.add(new Integer[]{i,j});
                }
            }
        }
        if(lands.size()==0||seas.size()==0){
            return -1;
        }
        int tmpMin=grid.length*2,ans=0;
        Integer[] sea,land;
        //检查每一个海洋区域
        for(int i=0;i<seas.size();i++){
            tmpMin=grid.length*2;
            sea=seas.get(i);
            //检查当前海洋区域到每一个陆地区域的距离，取其中的最小距离
            for(int j=0;j<lands.size();j++){
                land=lands.get(j);
                tmpMin=Math.min(tmpMin,Math.abs(sea[0]-land[0])+Math.abs(sea[1]-land[1]));
            }
            //所有海洋区域对应的最小距离中的最大值为所求
            ans=Math.max(ans,tmpMin);
        }
        return ans;
    }
}
```