```
public class ZigzagIterator {

    int[] ids = new int[2];
    int f = 0;
    List<List<Integer>> l = new ArrayList<>(); 

    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        l.add(new ArrayList<>(v1));
        l.add(new ArrayList<>(v2));
    }

    public int next() {
        if(ids[f] == l.get(f).size())
            f ^= 1;
        int r = l.get(f).get(ids[f]);
        // move one forward
        ids[f] ++;
        // change line
        f ^= 1;
        return r;
    }

    public boolean hasNext() {
        return !(ids[f] == l.get(f).size() && ids[(f^1)] == l.get((f^1)).size());
    }
}

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i = new ZigzagIterator(v1, v2);
 * while (i.hasNext()) v[f()] = i.next();
 */
```
