**AC的代码**
```java []
import java.util.HashMap;
import java.util.Map;

class SnapshotArray {
    private Map<Integer, Map<Integer, Integer>> snaps = null;
    private int snapId = 0;

    public SnapshotArray(int length) {
        snaps = new HashMap<>(length);
        while (length-- > 0) {
            snaps.put(length, new HashMap<Integer, Integer>());
        }
    }

    public void set(int index, int val) {
        snaps.get(index).put(snapId, val);
    }

    public int snap() {
        return snapId++;
    }

    public int get(int index, int snap_id) {
        while(snap_id>-1){//关键在这，因为在snap()生成新快照，没有为每个新生成的快照添加数据
            if (snaps.get(index).get(snap_id) != null) {
                return snaps.get(index).get(snap_id);
            }
            --snap_id;
        }
        return 0;
    }

    public static void main(String[] args) {
        SnapshotArray s = new SnapshotArray(1);
        s.set(0, 15);
        s.snap();
        s.snap();
        s.snap();
        System.out.println(s.get(0, 2));
    }

}
```
**超时的代码**

```java[]
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class SnapshotArray {
    private Map<Integer, List<Integer>> snaps = null;
    private int snapId = 0;
    private List<Integer> data = null;

    public SnapshotArray(int length) {
        snaps = new HashMap<Integer, List<Integer>>();
        this.data = new ArrayList<Integer>(length);
        while (length-- > 0) {
            data.add(0);
        }
    }

    public void set(int index, int val) {
        data.set(index, val);
    }

    public int snap() {
        snaps.put(snapId, new ArrayList<Integer>(data));//为每个新生成的快照，复制一份数据进去
        return snapId++;
    }

    public int get(int index, int snap_id) {
        if (snap_id > snapId) {
            return 0;
        }
        return (int) snaps.get(snap_id).get(index);
    }

    /*
     * public static void main(String[] args) { SnapshotArray s=new
     * SnapshotArray(3); s.set(0,5); s.snap(); System.out.println(s.get(0, 0));
     * }
     */
}

```