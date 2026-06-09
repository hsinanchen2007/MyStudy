1、直接使用变量保存最小值，和使用ArrayList当作存储
2、使用数组当作存储
3、构建了存储单元Node类
```
public class Node(){
    // 上一个节点
    public Node pre;
    public Integer min;
    public Integer val;
}
```

这三者的速度都过得去，但是内存消耗太大，不优。
