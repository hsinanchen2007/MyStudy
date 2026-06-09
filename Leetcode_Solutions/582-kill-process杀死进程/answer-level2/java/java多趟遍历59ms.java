写的很直接,本以为会超时,没想到提交过了,后来想想其实在时间复杂度上也没有下降的空间了,每次遍历为n,遍历的趟数为kill结点为根的子树的高度,所以最极端的时间复杂度为O(n^2)
```java
class Solution {
    public List<Integer> killProcess(List<Integer> pid, List<Integer> ppid, int kill) {
        Set<Integer> res = new HashSet<>();
        res.add(kill);
        while (true) {
            int size = res.size();
            for(int i=0;i<ppid.size();i++) {
                if(res.contains(ppid.get(i))) {
                    res.add(pid.get(i));
                }
            }
            if(size==res.size()) break;
        }
        return new ArrayList<>(res);
    }
}
```

