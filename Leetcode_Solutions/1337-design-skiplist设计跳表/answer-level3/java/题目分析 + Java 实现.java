跳表其实就是加了几层索引的链表，一共有 N 层，以 0 ~ N-1 层表示，设第 0 层是原链表，抽取其中部分元素，在第 1 层形成新的链表，上下层的相同元素之间连起来；再抽取第 1 层部分元素，构成第 2 层，以此类推。
具体选哪些元素呢？题目给的是coinFlip，也就是每次插入元素的时候，都进行一次 50% 概率的判断，如果 true 则向上层添加一个索引，如果 false 就不加了。
#    【查找】
在查找的时候，从最上层开始找，因为最顶层元素最少，比较次数也少，如果在较上层找到了，直接返回 true ；如果在较上层比较时发现了更大的元素，或者到头了，说明再往后是找不见的，直接向下层跳即可（所以这里需要记录访问的前一个元素是什么以进行向下的跳跃，可以多加一个元素在循环的时候记录前次访问的元素，或者使用双链表实现）。直到跳到最后一层还是没到，那就是找不到了，返回 false 。
#    【添加和删除】
添加和删除的时候，存在**数据重复**的问题，经过我的测试，发现题目要求的是，将重复的数据当做不同的值来对待，即存了一个元素 9 ，再存一个 9 ，此时表里有俩 9 ，相互独立，删除一个 9 ，表里应该还剩余有一个9。

由于添加和删除元素都是从底层开始，而在查找的时候是从顶层开始查找的，因此可以使用一个数组记录每层的“跳跃节点”的位置，就不必反复的从顶层开始查找每层的位置了。

在添加的时候，首先是查找到添加位置，过程与查找类似，首先找到表中 >= 插入元素 的最小节点位置，然后插入节点， 50% 概率判别，如果需要添加索引，就添加索引，继续 50% 概率判别，直到结束。

在删除的时候，首先也是查找，找到表中所有 = 插入元素的节点位置（每层只找一个，找到直接跳层即可），然后挨个删除。


Java 实现的代码如下。运行时间 83 ms，内存消耗 45.8MB
```
import java.util.ArrayList;
import java.util.List;

public class Skiplist {

    private List<Node> heads;
    // 使用 ArrayList 保存每层链表的表头，表头不存储元素，值为 -i ， i为层数，从 1 开始。

    private class Node{
        int val;
        // 使用双链表方便操作
        Node left,right,down;

        public Node(int val) {
            this.val = val;
            this.left = null;
            this.down = null;
            this.right = null;
        }
    }

    public Skiplist() {
        Node head0 = new Node(-1);
        heads = new ArrayList<>();
        heads.add(head0);
    }

    public boolean search(int target){
        int level = heads.size()-1;
        Node searchingStart = heads.get(level);
        while(level != -1){
            boolean jump = false;
            while(searchingStart.right!=null){
                searchingStart = searchingStart.right;
                if(searchingStart.val==target)
                    return true;
                else if(searchingStart.val>target){
                    if(level == 0)
                        return false;
                    else {
                        level --;
                        searchingStart = searchingStart.left.down;
                        jump = true;
                        break;
                    }
                }
            }
            if(jump)
                continue;
            level --;
            searchingStart = searchingStart.down;
        }
        return false;
    }

    public void add(int num){
        // 在底层添加元素
        Node n0 = new Node( num);
        Node[] jumpingNodes = searchNodes(num);
        Node lefter = jumpingNodes[0];
        n0.right = lefter.right;
        n0.left = lefter;
        if(lefter.right!=null)
            lefter.right.left=n0;
        lefter.right = n0;

        // 添加索引
        int levelToAddIndex = 1;
        while(throwCoin()){
            Node hi;
            if(jumpingNodes.length <= levelToAddIndex){
                hi= new Node(-levelToAddIndex-1);
                heads.add(hi);
                hi.down = heads.get(levelToAddIndex-1);
            }
            else
                hi = jumpingNodes[levelToAddIndex];
            Node ni = new Node(num);
            // 连接上下层相同的元素，用于跳
            ni.down = n0;
            ni.right = hi.right;
            ni.left = hi;
            if(hi.right!=null)
                hi.right.left = ni;
            hi.right = ni;
            n0 = ni;
            levelToAddIndex++;
        }
    }

    public boolean erase(int num) {
        Node[] jmpt = searchNodes(num);
        boolean exist = false;
        for (Node n:jmpt)
            if(n.val==num){
                exist = true;
                del(n);
            }
        return exist;
    }

    private Node[] searchNodes(int target){
        // 本函数也能实现 public boolean search(int target)的功能，但是由于是直到底层才停止的，效果不如在中间层找到就直接返回 true 的好。
        Node[] jumps = new Node[heads.size()];
        int level = heads.size()-1;
        Node searchingStart = heads.get(level);
        while(level!=-1){
            boolean jump = false;
            while(searchingStart.right!=null){
                searchingStart = searchingStart.right;
                if(searchingStart.val==target) {
                    while(level!=-1){
                        jumps[level] = searchingStart;
                        searchingStart=searchingStart.down;
                        level --;
                    }
                    return jumps;
                }
                else if(searchingStart.val>target){
                    jumps[level] = searchingStart.left;
                    level --;
                    searchingStart = searchingStart.left.down;
                    jump = true;
                    break;
                }
            }
            if(jump)
                continue;
            jumps[level] = searchingStart;
            level --;
            searchingStart = searchingStart.down;
        }
        return jumps;
    }

    private void del(Node n){
        n.left.right = n.right;
        if(n.right != null ) {
            n.right.left = n.left;
        }
    }

    private boolean throwCoin(){
        // 抛硬币， 50% 概率
        return Math.random()<0.5f;
    }

}
```

另外还用HashMap和ArrayList实现了一下存储，不是跳表，试了一下时间和空间。LinkedList超时了。代码和消耗附上。
```

// 使用HashMap 替代
// 时间：71ms  空间：44.1MB
import java.util.HashMap;

public class Skiplist {

    private HashMap<Integer,Integer> map;

    public Skiplist() {
        map = new HashMap<>();
    }

    public boolean search(int target){
        return map.containsKey(target);
    }

    public void add(int num){
        if(map.containsKey(num))
            map.put(num,map.get(num)+1);
        else 
            map.put(num,1);
    }

    public boolean erase(int num) {
        Integer va = map.get(num);
        if(va==null){
            return false;
        }
        if(va==1)
            map.remove(num);
        else
            map.put(num,va-1);
        return true;
    }

}
```

```
// 使用ArrayList
// 时间：193ms  空间：58MB

import java.util.ArrayList;

public class Skiplist {

    private ArrayList<Integer> array;
    public Skiplist() {
        array = new ArrayList<>();
    }

    public boolean search(int target){
        return array.contains(target);
    }

    public void add(int num){
        array.add(num);
    }

    public boolean erase(int num) {
        int p = -1;
        for (int i = 0; i < array.size(); i++) {
            if(array.get(i)==num)
                p=i;
        }
        if(p!=-1){
            array.remove(p);
            return true;
        }
        return false;            
    }
}

```