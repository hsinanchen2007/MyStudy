### 解题思路
虽然时间空间复杂度很垃圾，但是也是自己的一个想法，而且是最容易想到的，所以记录一下，大家可以指点一下
创建<距离，坐标>的哈希表，然后逐个坐标遍历，用treemap可以对key排序
然后依次输入，个人感觉空间绝对爆表果然是5%
时间是25%
大家看看就行

### 代码

```java
class Solution {
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        int [][] res =new int [R*C][2];
        Map<Integer,List<int []>> map = new TreeMap<>();
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                int dis = Math.abs(i-r0) + Math.abs(j-c0);
                int pos[] = new int[]{i,j};
                if(map.containsKey(dis))
                {
                     map.get(dis).add(pos);
                }
                else
                {
                    List<int []>list = new ArrayList<>();
                    list.add(pos);
                    map.put(dis,list);
                }
            }
        }
        int cnt = 0;
        for(int d:map.keySet())
        {
            for(int[] a:map.get(d))
            {
                res[cnt] = a;
                cnt++;
            }
        }
        return res;
    }
}


```