### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public static int openLock(String[] deadends, String target) {
        int ret = 0;
        Queue<String> queue = new LinkedList<>();
        HashSet<String> deadSet = new HashSet<>();
        int[] acts = {-1, 1};

        for (String deadend : deadends) {
            deadSet.add(deadend);
            if(deadend.equals("0000")){
                return -1;
            }
        }
        
        deadSet.add("0000");
        queue.offer("0000");
        
        while (!queue.isEmpty()) {

            int size = queue.size();
            
            while (size-->0){
                final String data = queue.poll();
                
                if (target.equals(data)) {
                    return ret;
                }

               char[] newCache = data.toCharArray();

                for (int i = 0; i < data.length(); i++) {
                    for (int act : acts) {
                        int dift = newCache[i] - '0';
                        int dift2 = dift + act;
                      
                        if (dift2 < 0) {
                            dift2 += 10;
                        } else if (dift2 > 9) {
                            dift2 = 0;
                        }
                        newCache[i] = (char)('0' + dift2);
                        final String temStr = new String(newCache);
                        if (!deadSet.contains(temStr)) {
                            queue.offer(temStr);
                            deadSet.add(temStr);
                        }
                        newCache[i] = (char)('0' + dift);
                    }
                }
            }
            ret++;

        }
        return -1;
    }
    
}
```