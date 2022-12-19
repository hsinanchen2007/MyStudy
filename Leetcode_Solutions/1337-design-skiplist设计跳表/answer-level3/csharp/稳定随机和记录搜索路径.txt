### 解题思路
稳定随机保证每次测试结果相同，方便对分层结果验证
记录搜索路径用于 设置多层设置
随机需要真随机可分层

### 代码

```csharp



public class ListNode {
    public int index = 0;
    public int depth = 0;
    public int layer = 0;
    public int data;
    // public ListNode next, pre;
    public List<ListNode> nextLayer = new List<ListNode>();
    public List<ListNode> preLayer = new List<ListNode>();
     
}
public class Skiplist {
    public ListNode headNode;
    public ListNode tailNode;
    // private Random random;
    private int myRandom = 1;
    public int maxId = 0;
    public Skiplist() {
        // random = new Random(0);
        headNode = new ListNode()
        {
            data = Int32.MinValue,
            index = maxId++,
        };
        tailNode = new ListNode()
        {
            data = Int32.MaxValue,
            index = maxId++,
        };
        headNode.nextLayer.Add(tailNode);
        tailNode.preLayer.Add(headNode);
    }
    
    public bool Search(int target) {
        ////Console.WriteLine("Search:" + target);
        var curNode = headNode;
        var curLayer = curNode.nextLayer.Count-1;
    Find:
        totalFindCount++;
        if(curLayer >= 0){
            var next = curNode.nextLayer[curLayer];
            // //Console.WriteLine("Search:"+next.data+":"+target);
            if(next.data == target) return true;
            if (next.data > target)
            {
                curLayer--;
                goto Find;
            }
            //小于继续查找 下一个节点最后一层
            curNode = next;
            curLayer = curNode.nextLayer.Count - 1;
            goto Find;
        }
        return false;
    }
    public void Dump2(){
        for (var i = 0; i < headNode.nextLayer.Count; i++){
            var cur = -1;
            var cn = headNode;
            Console.WriteLine("Layer:"+i);
            var sb = new StringBuilder();
            sb.Append(cur);
            while(cn != null){
                // //Console.WriteLine(cur + "->" + cn.data);
                sb.Append("->" + cn.data+":"+cn.index);
                if(cn.nextLayer.Count <= i) break;
                cur = cn.data;
                cn = cn.nextLayer[i];
            }
            Console.WriteLine(sb.ToString());
        }
    }
    public void Dump(){
        var curNode = headNode;
        var openQueue = new Queue<ListNode>();
        openQueue.Enqueue(headNode);
        var curDepth = 0;
        while(openQueue.Count > 0){
            var fir = openQueue.Dequeue();
            if(fir.depth != curDepth) {
                //Console.WriteLine();
                curDepth = fir.depth;
            }
            //Console.WriteLine(fir.layer+":"+fir.depth+"->"+fir.data+":"+fir.nextLayer.Count);
            var l = 0;
            foreach (var n in fir.nextLayer)
            {
                n.depth = fir.data;
                n.layer = l;
                openQueue.Enqueue(n);
                l++;
            }
        }
    }
    public int totalInsertCOunt = 0;
    public int totalFindCount = 0;
    public void Add(int num) {
        ////Console.WriteLine("Add:" + num);
        //从查找位置插入
        var eachLayerLastNode = new Dictionary<int, ListNode>();
        var curNode = headNode;
        var curLayer = curNode.nextLayer.Count-1; 
    Find:
        totalInsertCOunt++;
        if(curLayer >= 0){
            var next = curNode.nextLayer[curLayer];
            if(next.data == num){ //插入在我前面
                // eachLayerLastNode[curLayer] = curNode;
                eachLayerLastNode[curLayer] = next; //向后移动 最后一个
                //插入到前面
                // InsertAfter(curNode, num, eachLayerLastNode);
                //继续向后移动
                curNode = next;
                curLayer = curNode.nextLayer.Count - 1;
                goto Find;
            }else if(next.data > num) { //降低层
                // if(curLayer > 0) {
                eachLayerLastNode[curLayer] = curNode;
                curLayer--;
                goto Find;
                // }
                //第一层了 直接插入结课
                // InsertAfter(curNode, num, eachLayerLastNode);
            }else { //小于继续向后
                eachLayerLastNode[curLayer] = next;
                curNode = next;
                curLayer = curNode.nextLayer.Count - 1;
                goto Find;
            }
        }else { //最大元素插入在 结尾前面
            InsertAfter(curNode, num, eachLayerLastNode);
        }
    }
    private int coff = 4;
    private void InsertAfter(ListNode node, int num, Dictionary<int, ListNode> dict){
        ////Console.WriteLine("InsertAfter:"+node.data+":"+num+":"+dict.Count);
        var newNode = new ListNode()
        {
            data = num,
            index = maxId++,
        };
        // if (node.nextLayer.Count > 0)
        //第0层肯定存在
        {
            var oldNext = node.nextLayer[0];
            node.nextLayer[0] = newNode;
            newNode.preLayer.Add(node);

            newNode.nextLayer.Add(oldNext);
            oldNext.preLayer[0] = newNode;
        }
        // return;
        // }else { //到结尾了
        //     node.nextLayer.Add(newNode);
        //     newNode.preLayer.Add(node);
        // }
        var lastInsertPos = node;
        var nextPLayer = 1;
        //进行概率计算 直到插入到最高层
        var curCoff = coff;
        var curRandom = myRandom++;
    UpInsert:
        totalInsertCOunt++;
        // var mod = random.Next() % 2;
        var mod = (curRandom) % (curCoff);
        curCoff *= coff;
        // myRandom = myRandom % coff;
        // //Console.WriteLine("modV:" + mod);
        //插入到上一层中
        if(mod == 0){
            var insertPos = headNode;
            if(dict.ContainsKey(nextPLayer)){ //存在则用
                insertPos = dict[nextPLayer];
            }
            if(insertPos == lastInsertPos) return;
            //可以插入
            if(insertPos.nextLayer.Count >= nextPLayer){
                if(insertPos.nextLayer.Count == nextPLayer){
                    insertPos.nextLayer.Add(newNode);
                    newNode.preLayer.Add(insertPos);

                    //新扩张的一层
                    newNode.nextLayer.Add(tailNode);
                    tailNode.preLayer.Add(newNode);
                }else {
                    var oldNext = insertPos.nextLayer[nextPLayer];
                    insertPos.nextLayer[nextPLayer] = newNode;
                    newNode.preLayer.Add(insertPos);

                    //替换掉某一层而不是
                    oldNext.preLayer[nextPLayer] = newNode;
                    newNode.nextLayer.Add(oldNext);
                    nextPLayer++;
                    goto UpInsert;
                }
            }
        }
    }
    public int eraseCOunt = 0;
    public bool Erase(int num) {
        ////Console.WriteLine("Erase:" + num);
        var curNode = headNode;
        var curLayer = curNode.nextLayer.Count-1;
    Find:
        eraseCOunt++;
        if(curLayer >= 0){
            var next = curNode.nextLayer[curLayer];
            //Console.WriteLine("Erase:"+curNode.data+":" + next.data + ":" + curLayer + ":" + num+":"+curLayer);
            if (next.data == num)
            {
                RemoveNode(next);
                return true;
            }
            if (next.data > num)
            {
                curLayer--;
                goto Find;
            }
            //小于继续查找 下一个节点最后一层
            curNode = next;
            curLayer = curNode.nextLayer.Count - 1;
            goto Find;
        }
        return false;
    }
    private void RemoveNode(ListNode node){
        //Console.WriteLine("RemoveNode:" + node.data);
        for (var i = 0; i < node.preLayer.Count; i++){
            eraseCOunt++;
            var pre = node.preLayer[i];
            ListNode next = null;
            // if(i < node.nextLayer.Count){
            next = node.nextLayer[i];
            // }
            // if(next != null) {
            pre.nextLayer[i] = next;
            next.preLayer[i] = pre;
            // }else {
            //     pre.nextLayer[i] = tailNode;

            // }
        }
    }
}


/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist obj = new Skiplist();
 * bool param_1 = obj.Search(target);
 * obj.Add(num);
 * bool param_3 = obj.Erase(num);
 */
```