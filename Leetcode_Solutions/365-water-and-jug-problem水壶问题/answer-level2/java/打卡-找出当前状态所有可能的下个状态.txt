### 解题思路
用一个叫visited的map保存处理过的状态，当前状态x瓶tx水，y瓶ty水，有6个可能的下个状态，分别是将x瓶装满；将y瓶装满；将x瓶清空；将瓶清空；将x瓶水倒入y瓶；将y瓶水倒入x瓶；注意互倒水时要么将倒出的瓶倒光，要么将倒入的瓶倒满
当x瓶的水为z，或y瓶的水为z，或x,y瓶水之和为z时，返回true，当所有状态都处理完了返回false

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        Map<Long, Integer> visited = new HashMap<>();
        Queue<Long> q = new LinkedList<>();
        long temp;
        int tx, ty;

        q.offer((long)x<<32);
        q.offer((long)y);
        while(!q.isEmpty()){
            temp = q.poll();
            visited.put(temp, 1);
            ty = (int)(temp & 0xffffffff);
            tx = (int)(temp>>32);

            if(tx + ty == z || tx == z || ty == z){
                return true;
            }

            temp = ((long)x<<32) + ty;
            if(null == visited.get(temp)){
                q.offer(temp);
            }
            temp = ((long)tx<<32) + y;
            if(null == visited.get(temp)){
                q.offer(temp);
            }
            temp = (long)tx<<32;
            if(null == visited.get(temp)){
                q.offer(temp);
            }
            temp = ty;
            if(null == visited.get(temp)){
                q.offer(temp);
            }
            temp = ((long)(tx+ty >= x ? x : tx + ty)<<32) + (tx+ty > x ? tx + ty - x : 0);
            if(null == visited.get(temp)){
                q.offer(temp);
            }
            temp = ((long)(tx+ty > y ? tx + ty - y : 0)<<32) + (tx + ty >= y ? y : tx + ty);
            if(null == visited.get(temp)){
                q.offer(temp);
            }
        }

        return false;
    }
}
```