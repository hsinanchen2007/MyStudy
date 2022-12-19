![image.png](https://pic.leetcode-cn.com/ebf9cd45eb8ec79cf3d9907d994f55779dfc99540ac3d564c372fb0a5910c298-image.png)

### 解题思路
正常人都应该会暴力破解，但是爆破时候在大数据时候就会出现超时；
在这种情况下，将爆破算法中的循环进行优化，办法就是对ppid/pid数据进行转化
使用Map<key,value>的数据结构，key表示进程id，value表示该进程对应的子进程
然后使用栈结构，把要杀死的进程丢进栈里，每次出栈一个进程，然后将其子进程压入栈中
停止条件是栈为空

### 代码

```java
class Solution {
    public List<Integer> killProcess(List<Integer> pid, List<Integer> ppid, int kill) {
        // <pid, pid children>
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < ppid.size(); i++) {
            if (!map.keySet().contains(ppid.get(i))) {
                List<Integer> temp = new ArrayList<>();
                temp.add(pid.get(i));
                map.put(ppid.get(i), temp);
            } else {
                map.get(ppid.get(i)).add(pid.get(i));
            }
        }
        List<Integer> result = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        stack.push(kill);
        result.add(kill);
        while (stack.size() != 0) {
            int curPid = stack.pop();
            List<Integer> curChildren = map.get(curPid);
            if (curChildren != null) {
                for (int i = 0; i < curChildren.size(); i++) {
                    stack.push(curChildren.get(i));
                    result.add(curChildren.get(i));
                }
            }
        }
        return result;
    }
}
```