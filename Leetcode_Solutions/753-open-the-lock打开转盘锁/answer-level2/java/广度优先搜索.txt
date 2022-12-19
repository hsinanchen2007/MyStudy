### 解题思路
使用广度优先搜索，把字符串转成int类型进行操作，加快速度。

### 代码

```java
class Solution {
    public int openLock(String[] deadends, String target) {

        HashSet<Integer> seeHashSet = new HashSet<>();
        for(String s : deadends) {
            seeHashSet.add(Integer.valueOf(s));
        }
        
        Integer targetInt = Integer.valueOf(target);

        LinkedList<Integer> queue = new LinkedList<>();
        
        if (seeHashSet.contains(0)) {
            return -1;
        }
        queue.add(0);
        seeHashSet.add(0);
        
        int step = 0;
        
        while (!queue.isEmpty()) {
            
            int queueSize = queue.size();

            for (int k = 0; k < queueSize; k++) {
                Integer curStepInt = queue.pop();

                if (targetInt.intValue() == curStepInt) {
                    return step;
                } else {
                    int temp;
                    temp = curStepInt + 1 - ((curStepInt % 10) == 9 ? 10 : 0);

                    if (!seeHashSet.contains(temp)) {
                        queue.add(temp);
                        seeHashSet.add(temp);
                    }
                    
                    temp = curStepInt + 10 - ((curStepInt / 10 % 10) == 9 ? 100 : 0);
                    if (!seeHashSet.contains(temp)) {
                        queue.add(temp);
                        seeHashSet.add(temp);
                    }
                    
                    temp = curStepInt + 100 - ((curStepInt / 100 % 10) == 9 ? 1000 : 0);
                    if (!seeHashSet.contains(temp)) {
                        queue.add(temp);
                        seeHashSet.add(temp);
                    }
                    
                    temp = curStepInt + 1000 - ((curStepInt / 1000 % 10) == 9 ? 10000 : 0);
                    if (!seeHashSet.contains(temp)) {
                        queue.add(temp);
                        seeHashSet.add(temp);
                    }
                    
                    temp = curStepInt - 1 + ((curStepInt % 10) > 0 ? 0 : 10);
                    if (!seeHashSet.contains(temp)) {
                        queue.add(temp);
                        seeHashSet.add(temp);
                    }
                    
                    temp = curStepInt - 10 + ((curStepInt / 10 % 10) > 0 ? 0 : 100);
                    if (!seeHashSet.contains(temp)) {
                        queue.add(temp);
                        seeHashSet.add(temp);
                    }
                    
                    temp = curStepInt - 100 + ((curStepInt / 100 % 10) > 0 ? 0 : 1000);
                    if (!seeHashSet.contains(temp)) {
                        queue.add(temp);
                        seeHashSet.add(temp);
                    }
                    
                    temp = curStepInt - 1000 + ((curStepInt / 1000 % 10) > 0 ? 0 : 10000);
                    if (!seeHashSet.contains(temp)) {
                        queue.add(temp);
                        seeHashSet.add(temp);
                    }
                }
            }
            
            
            step++;
        }
        
        
        return -1;
    
    }
}
```