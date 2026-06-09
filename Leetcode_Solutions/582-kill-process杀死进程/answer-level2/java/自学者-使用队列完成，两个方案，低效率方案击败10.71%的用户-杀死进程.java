### 解题思路
* 队列代替递归
* 边检索，边删除提升效率

### 代码

```java []
// 方案一、自己摸索的方案，边检索边删除
class Solution {
    public List<Integer> killProcess(List<Integer> pid, List<Integer> ppid, int kill) {
        List<Integer> ans = new ArrayList<>(pid.size());
        Deque<Integer> parentQueue = new LinkedList<>();
        parentQueue.add(kill);
        ans.add(kill);
        while (!parentQueue.isEmpty()) {
            Integer crawlParent = parentQueue.removeFirst();
            Iterator<Integer> itProcess = pid.iterator();
            Iterator<Integer> itParent = ppid.iterator();
            while (itProcess.hasNext() && itParent.hasNext()) {
                Integer process = itProcess.next();
                Integer parent = itParent.next();
                //System.out.printf("crawl:%d,%d,%d\n",crawlParent,process,parent);
                if(parent.equals(crawlParent)) {
                    //找到所有parent是要被kill掉的父进程，根据该父进程所在索引，找到对应的子进程
                    ans.add(process);
                    parentQueue.add(process); 
                    
                    itProcess.remove();
                    itParent.remove();
                }
            }
        }
        
        return ans;
    }
}
```

```java []
// 方案二、改进的高效率队列方案
class Solution {
     public List < Integer > killProcess(List < Integer > pid, List < Integer > ppid, int kill) {
        HashMap < Integer, List < Integer >> map = new HashMap < > ();
        for (int i = 0; i < ppid.size(); i++) {
            if (ppid.get(i) > 0) {
                List < Integer > l = map.getOrDefault(ppid.get(i), new ArrayList < Integer > ());
                l.add(pid.get(i));
                map.put(ppid.get(i), l);
            }
        }
        Queue <Integer> queue = new LinkedList <> ();
        List <Integer> ans = new ArrayList <> ();
        queue.add(kill);
        while (!queue.isEmpty()) {
            // 取出第一个要删除的进程
            int toKill = queue.remove();
            //如果自己是单独的进程，则map中不会有任何记录信息
            ans.add(toKill);
            if (map.containsKey(toKill)) {
                // 当前进程还有子进程，每个子进程还可能有子进程
                for (int id: map.get(toKill)) {
                    queue.add(id);
                }
            }
        }
        return ans;
    }
    
}
```