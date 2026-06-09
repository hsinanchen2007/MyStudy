每次发coins，维护当前点及祖先节点的coins数
- 第一种类型的，遍历所有祖先，都加operation[2]的coins
- 第二种类型的，先更新每个孩子节点，每个加operation[2]的coins，并返回总共增加了多少coins，把总的增加的coins更新到祖先节点
- 查询时直接查询
所以 每次第一、二种类型的操作，复杂度为OlogN，查询为O1
关于int溢出问题，偷懒直接存的long，get的时候取模再返回

```java
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;

class Solution {
    public int[] bonus(int n, int[][] leadership, int[][] operations) {

        HashMap<Integer, Node> map = new HashMap<>((int)(n/3.0*4)+1);
        for(int i=0; i<n; i++) map.put(i+1, new Node(i+1));
        for (int[] ints : leadership) {

            Node c = map.get(ints[1]);
            Node p = map.get(ints[0]);
            c.p = p;
            p.child.add(c);
        }

        LinkedList<Integer> rs = new LinkedList<>();
        for (int[] operation : operations) {

            Node node = map.get(operation[1]);
            if(operation[0] == 1) {

                node.n += operation[2];
                Node t = node;
                while(t.p != null) {
                    t.p.n += operation[2];
                    t = t.p;
                }
            } else if (operation[0] == 2) {
                int update = update(node, operation[2]);
                while(node.p != null) {
                    node.p.n += update;
                    node = node.p;
                }
            } else {

                rs.add((int)(node.n%1000000007));
            }
        }
        Iterator<Integer> iterator = rs.iterator();
        int[] arr = new int[rs.size()];
        for(int i=0; iterator.hasNext(); i++) {
            arr[i] = iterator.next();
        }
        return arr;
    }

    int update(Node node, int c) {
        if(node == null)
            return 0;
        int n = c;
        for (Node ch : node.child) {
            n += update(ch, c);
        }
        node.n += n;
        return n;
    }

    class Node {
        int num;
        int n;
        Node p;
        LinkedList<Node> child = new LinkedList<>();

        public Node(int num) {
            this.num = num;
        }
    }

}
```
