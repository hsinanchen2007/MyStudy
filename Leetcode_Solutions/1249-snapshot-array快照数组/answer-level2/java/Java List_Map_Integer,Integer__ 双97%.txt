### 解题思路
题意是要构建一个带有不同版本信息的数组，一种方法是每个版本都保存一个数组，但是这样显然产生了太多的冗余
只需要记录每个版本之间有区别的值即可
详细内容见注释


### 代码

```java
class SnapshotArray {
    
    //list.get(index)应为数组下标为index处的值
    //每一个Map记录的是当前下标位置的值的变动，<版本号，新值>
    private List<Map<Integer,Integer>> list;
    private int snapId;

    public SnapshotArray(int length) {
        list = new ArrayList<>();
        for(int i = 0; i < length; i++){
            list.add(new HashMap<Integer,Integer>());
        }
        snapId = 0;
    }
    
    public void set(int index, int val) {
        //在index处放入此次版本更新的值
        list.get(index).put(this.snapId,val);
    }
    
    public int snap() {
        return snapId++;
    }
    
    public int get(int index, int snap_id) {
        //寻找snap_id版本前，最后一次更新的值
        for(int i = snap_id; i >= 0; i--) {
            if (list.get(index).containsKey(snap_id)) {
                return list.get(index).get(snap_id);
            }
            --snap_id;
        }
        return 0;
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray obj = new SnapshotArray(length);
 * obj.set(index,val);
 * int param_2 = obj.snap();
 * int param_3 = obj.get(index,snap_id);
 */
```

![QQ截图20200224140153.png](https://pic.leetcode-cn.com/53f3878af2bd059c3ae38fd4fb1a0c436f031f58934bacf7a74ddf475f4d682a-QQ%E6%88%AA%E5%9B%BE20200224140153.png)