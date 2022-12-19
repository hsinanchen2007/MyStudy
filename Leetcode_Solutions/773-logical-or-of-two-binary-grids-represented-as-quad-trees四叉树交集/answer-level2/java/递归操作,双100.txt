
![2_100.jpg](https://pic.leetcode-cn.com/a2867fdcc630e4028f4026038b8a776fc57ba181e47ee2e8efd0ffaf305422d7-2_100.jpg)

```
public Node intersect(Node quadTree1, Node quadTree2) {

        return or(quadTree1, quadTree2);
    }

    private Node or(Node quadTree1, Node quadTree2) {
        if (quadTree1 == null && quadTree2 == null) {
            return null;
        }
        if (quadTree1 == null) {
            return quadTree2;
        }
        if (quadTree2 == null) {
            return quadTree1;
        }

        if (quadTree1.isLeaf || quadTree2.isLeaf) {
            if ((quadTree1.val && quadTree1.isLeaf) || (quadTree2.val && quadTree2.isLeaf) || (quadTree1.isLeaf && quadTree2.isLeaf)) {
                return new Node(quadTree1.val | quadTree2.val, true);
            } else {
                Node node = new Node();
                node.isLeaf = false;
                node.topLeft = or(quadTree1.topLeft, quadTree2.topLeft);
                node.topRight = or(quadTree1.topRight, quadTree2.topRight);
                node.bottomLeft = or(quadTree1.bottomLeft, quadTree2.bottomLeft);
                node.bottomRight = or(quadTree1.bottomRight, quadTree2.bottomRight);
                return node;
            }
        } else {

            Node node = new Node();
            node.isLeaf = false;
            node.topLeft = or(quadTree1.topLeft, quadTree2.topLeft);
            node.topRight = or(quadTree1.topRight, quadTree2.topRight);
            node.bottomLeft = or(quadTree1.bottomLeft, quadTree2.bottomLeft);
            node.bottomRight = or(quadTree1.bottomRight, quadTree2.bottomRight);
            if (node.topLeft.isLeaf && node.topRight.isLeaf && node.bottomLeft.isLeaf && node.bottomRight.isLeaf) {
                int sum = val(node.topLeft.val) + val(node.topRight.val) + val(node.bottomLeft.val) + val(node.bottomRight.val);
                if (sum == 4 || sum == 0) {
                    node.isLeaf = true;
                    node.val = (sum == 4);
                    node.topLeft = node.topRight = node.bottomLeft = node.bottomRight = null;
                }
            }
            return node;
        }

    }

    private int val(boolean b) {
        return b ? 1 : 0;
    }
```
