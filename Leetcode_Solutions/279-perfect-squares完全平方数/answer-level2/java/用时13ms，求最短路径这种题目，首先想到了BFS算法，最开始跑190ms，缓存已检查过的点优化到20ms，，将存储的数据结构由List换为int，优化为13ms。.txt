### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numSquares(int n) {
        if(n ==0)return 0;
        
        // 存储已检查过的点
        boolean record[] = new boolean[n];

        Queue<Bean> queue = new ArrayDeque<>();
        queue.offer(new Bean(n,1));
        
        while (!queue.isEmpty()) {
            final Bean val = queue.poll();

            // 计算最大值
            int size = (int) Math.floor(Math.sqrt(val.val));
            int nextVal = val.val - (int) Math.pow(size, 2);
            
            if (nextVal == 0) {
                return val.cnt;
            }
            
            for (int i = 0; i < size; i++) {
                nextVal = val.val - (int)Math.pow(size-i, 2);
                if(record[nextVal])continue;
                
                final Bean bean = new Bean(nextVal, val.cnt+1);
                record[nextVal] = true;
                queue.offer(bean);
            }
        }
        return 0;
    }

      public static class Bean{
        public int val;
        public int cnt; 

        public Bean(int val, int cnt) {
            this.val = val;
            this.cnt = cnt;
        }
    }
}
```