### 解题思路
![1104.二叉树寻路.png](https://pic.leetcode-cn.com/67e2543c3480d4096ce9b76ae5441940a70f605dbdc7009e5ab7d079450c786e-1104.%E4%BA%8C%E5%8F%89%E6%A0%91%E5%AF%BB%E8%B7%AF.png)

通过数学规律来得到节点的值，时间复杂度还行，代码已经写了注释，直接看代码即可

### 代码

```java
class Solution {

    //Solution的实例变量，用来动态的存储 当前 想要求得的 节点 的位置，下面注释有对nowLoc的详细解释
    int nowLoc;

    public List<Integer> pathInZigZagTree(int label) {
        //定义必要的参数
        int depth, maxNum = 0;
        LinkedList<Integer> res = new LinkedList();

        //通过for循环来得到label所在的层数（depth）、所在层的最大值（maxNum）
        //例如，label == 14 时，depth == 3，maxNum == 15
        for(depth = 0; label > maxNum; depth++) {
            maxNum = maxNum + (int)Math.pow(2, depth);
        }
        depth--;

        //根据label所在的层数（depth）的奇偶性来得到label在这一层中 从左往右数 是第几个
        //(例如，label == 14 时，nowLoc == 2)
        if(depth % 2 == 0) {
            nowLoc = label - (maxNum - (int)Math.pow(2, depth));
        }
        else {
            nowLoc = maxNum - label + 1;
        }

        //头差法先将label插入结果中
        res.addFirst(label);

        //每一次迭代都会找到 上一个 插入到结果（res）中的 节点 的 父节点，并将之头插法插入res链表中
        while(depth > 0) {
            maxNum = maxNum - (int)Math.pow(2, depth);
            depth--;
            res.addFirst( findNode(depth, maxNum, (depth % 2 != 0)) );
        }

        return res;
    }

    /*
        *这个函数的功能是:通过这个节点所在的深度、该节点所在层的最大值（例如：深度为2的层中最大的值是“7”）、该层是否为奇数层
        *来得到这一层的目标节点的值
    */
    private int findNode(int depth, int maxNum, boolean isOddLevel) {
        nowLoc = (nowLoc % 2) == 0 ? (nowLoc / 2) : (nowLoc / 2 + 1);

        return isOddLevel ? (maxNum - nowLoc + 1) 
            : (maxNum - (int)Math.pow(2, depth) + nowLoc);
    }
}
```