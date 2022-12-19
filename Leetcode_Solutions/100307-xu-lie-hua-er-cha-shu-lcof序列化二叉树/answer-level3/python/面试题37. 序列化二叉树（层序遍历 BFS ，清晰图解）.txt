> 观察题目示例，序列化的字符串实际上是二叉树的 “层序遍历”（BFS）结果，本文也采用层序遍历。
> 通常使用的前序、中序、后序、层序遍历记录二叉树的信息不完整，即可能对应着多种二叉树结果。

- 题目要求的 “序列化” 和 “反序列化” 是 **可逆** 操作。因此，序列化的字符串应携带 “完整的” 二叉树信息，即拥有单独表示二叉树的能力。
- 为使反序列化可行，考虑将越过叶节点后的 $null$ 也看作是节点。在此基础上，通过层序遍历生成序列化列表，若任意选择列表中某节点 $node$ ，则其左子节点 $node.left$ 和右子节点 $node.right$ 在序列中的位置都是 **唯一确定** 的。

![Picture1.png](https://pic.leetcode-cn.com/131a4120f1948c8a282508095b0aedc652d1ad932e907bf39b3f804b065fa3ee-Picture1.png){:width=500}

| $node$ 在列表中的索引 | $node.left$ 在列表中的索引 | 节点 $node.right$ 在列表中的索引 |
| :-------------------: | :------------------------: | :------------------------------: |
|          $0$          |            $1$             |               $2$                |
|          $1$          |            $3$             |               $4$                |
|          $2$          |            $5$             |               $6$                |
|       $\cdots$        |          $\cdots$          |             $\cdots$             |
|          $n$          |           $2n+1$           |              $2n+2$              |

#### 序列化 serialize ：

- 借助队列，对二叉树做层序遍历，并将越过叶节点的 $null$ 也打印出来。

##### 算法流程：

1. **特例处理：** 若 $root$ 为空，则直接返回空列表 `"[]"` ；
2. **初始化：** 队列 $queue$ （包含根节点 $root$ ）；序列化列表 $res$ ；
3. **层序遍历：** 当 $queue$ 为空时跳出；
   1. 节点出队，记为 $node$ ；
   2. 若 $node$ 不为空：① 打印字符串 $node.val$ ，② 将左、右子节点加入 $queue$ ；
   3. 否则（若 $node$ 为空）：打印字符串 `"null"` ；
4. **返回值：** 拼接列表（用 `','` 隔开，首尾添加中括号）。

##### 复杂度分析：

- **时间复杂度 $O(N)$ ：** $N$ 为二叉树的节点数，层序遍历需要访问所有节点，最差情况下需要访问 $N + 1$ 个 $null$ ，总体复杂度为 $O(2N + 1)$ ，因此还是线性的 $O(N)$ 。
- **空间复杂度 $O(N)$ ：** 最差情况下，队列 $queue$ 同时存储 $\frac{N + 1}{2}$ 个节点（或 $N+1$ 个 $null$ ），因此使用 $O(N)$ 额外空间。

<![Picture2.png](https://pic.leetcode-cn.com/417ca370a75961a07a0681056b711e0a5dd9339d8053d0e2dcfa7f97baa2bc6a-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/ce572b3847074076771238b990bd7a14765f6979f4eff96da066f3f2cdc57be3-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/47b849d995022681daf642a5df11579f5fe1c59f7d2f1a723a48b2a93317ef11-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/e957ae4981057ceeec883154adf49029a6365ee1b342bc09db35cad2e78c50a5-Picture5.png),![Picture6.png](https://pic.leetcode-cn.com/6c2f50bf47de22cd549376e423e26dee5d6d8e91da61dca59fad65b49205eab8-Picture6.png),![Picture7.png](https://pic.leetcode-cn.com/6bdca5ccd4be1d5551eaa0fd8bbc8e9b5add9d737a139f5113618552422e5c4b-Picture7.png),![Picture8.png](https://pic.leetcode-cn.com/711a8680b145ca26093ed8332c9f921bb9f95123e25e917d6aa890f01b0cc3fc-Picture8.png),![Picture9.png](https://pic.leetcode-cn.com/07c43c0633838e6cb056e017641e16099efb4ae7b0f217b0c27a689b00862b93-Picture9.png),![Picture10.png](https://pic.leetcode-cn.com/b82ff760816fb1d8ba574e147695a616f0c4fcbea9bd64a732e23e49cf7412ca-Picture10.png),![Picture11.png](https://pic.leetcode-cn.com/0b42a7ceef5364ba5260f8d4fb5853044c78936d4f638734ed8cc0f99af8602e-Picture11.png),![Picture12.png](https://pic.leetcode-cn.com/3d64cd51d402130c34bb565f3e78180ed600cdc43acd690df7e9360696c53ea0-Picture12.png),![Picture13.png](https://pic.leetcode-cn.com/952b04407332b96a639761585fc0a3facc0d6916450fcd0af85a646ad0893148-Picture13.png),![Picture14.png](https://pic.leetcode-cn.com/cbf8219a00b04842b2b6c0b0611e312c4c48af10f5c51a91d1cc856a838058d1-Picture14.png)>

#### 反序列化 deserialize ：

- 基于本文一开始分析的 “ $node$ , $node.left$ , $node.right$ ” 在序列化列表中的位置关系，可实现反序列化。
- 利用队列按层构建二叉树，借助一个指针 $i$ 指向节点 $node$ 的左、右子节点，每构建一个 $node$ 的左、右子节点，指针 $i$ 就向右移动 $1$ 位。

##### 算法流程：

1. **特例处理：** 若 $data$ 为空，直接返回 $null$ ；
2. **初始化：** 序列化列表 $vals$ （先去掉首尾中括号，再用逗号隔开），指针 $i = 1$ ，根节点 $root$ （值为 $vals[0]$ ），队列 $queue$（包含 $root$ ）；
3. **按层构建：** 当 $queue$ 为空时跳出；
   1. 节点出队，记为 $node$ ；
   2. 构建 $node$ 的左子节点：$node.left$ 的值为 $vals[i]$ ，并将 $node.left$ 入队；
   3. 执行 $i+=1$ ；
   4. 构建 $node$ 的右子节点：$node.left$ 的值为 $vals[i]$ ，并将 $node.left$ 入队；
   5. 执行 $i+=1$ ；
4. **返回值：** 返回根节点 $root$ 即可。

##### 复杂度分析：

- **时间复杂度 $O(N)$ ：** $N$ 为二叉树的节点数，按层构建二叉树需要遍历整个 $vals$ ，其长度最大为 $2N+1$ 。
- **空间复杂度 $O(N)$ ：** 最差情况下，队列 $queue$ 同时存储 $\frac{N + 1}{2}$ 个节点，因此使用 $O(N)$ 额外空间。

<![Picture15.png](https://pic.leetcode-cn.com/a372d9c99fecd301e82a34fbe417264c4c09629df2a75c9fea564653f2aa4d6c-Picture15.png),![Picture16.png](https://pic.leetcode-cn.com/279936eb04ae459c9bc8e87e6dc967b21dca2603648b161a52a93510a3916c1a-Picture16.png),![Picture17.png](https://pic.leetcode-cn.com/0d118b74490c624afbb18fbf82cd4fc844bce7aea4246efe6c599df9d1e005ca-Picture17.png),![Picture18.png](https://pic.leetcode-cn.com/6762b541459782314176442011b699913085b7d34ab2598d6044374fe8ee9c6d-Picture18.png),![Picture19.png](https://pic.leetcode-cn.com/ce3d8c2f587f6f384784b9915f301115ece35dcc8f18aa9c4120e40972e43594-Picture19.png),![Picture20.png](https://pic.leetcode-cn.com/cb179bc30eab589fc4ce90f7ebdf4269a330e87e1bb5498f241c4634b00c0dc1-Picture20.png),![Picture21.png](https://pic.leetcode-cn.com/00b3903a3e296ffdd91da6fce33ac9b81ee6d43a5171589cb43d15ba64d61dd8-Picture21.png),![Picture22.png](https://pic.leetcode-cn.com/8180b8a750c32af66868f7550547effed37d77602c1d4347674bef4803270b82-Picture22.png),![Picture23.png](https://pic.leetcode-cn.com/455c33478d9236a851313e402f1ef7453686001263ca1002c146923c9d0a1033-Picture23.png),![Picture24.png](https://pic.leetcode-cn.com/8d207a75cf994e0762b2a420c593553355f1e31ab0b08eaa6245bb5b6a6697b4-Picture24.png),![Picture25.png](https://pic.leetcode-cn.com/76fe0ddf83303622aa4d954fec53f663c9a5bad3187afbe9c586ec127fd0e8f0-Picture25.png),![Picture26.png](https://pic.leetcode-cn.com/3180c5691fe13aa9d94f352fef42a1e14f931e9327f6041dadb8da3e450b6de1-Picture26.png),![Picture27.png](https://pic.leetcode-cn.com/dc493c0a7f30e042ee563e13a16bc4c60964d7f4c9d6e52f14625b9b14672f67-Picture27.png),![Picture28.png](https://pic.leetcode-cn.com/0351597bfa8ec0fa9e715d2182d5166498df3de35b53668fc121115e2478ffc8-Picture28.png),![Picture29.png](https://pic.leetcode-cn.com/4abbdbb9ee212f3e89515c8909265df08b641dc389a076064ef71bfe8d9b53bd-Picture29.png),![Picture30.png](https://pic.leetcode-cn.com/f3a8767a785cf7d384e0be4e607593f800fc8822cdfae0ce54290748a82f511b-Picture30.png),![Picture31.png](https://pic.leetcode-cn.com/2dde0419c3d7a134e6fb8fcc38c85a5180df04b197f8b6cd37137d38da33e8f5-Picture31.png)>

#### 代码：

```python []
class Codec:
    def serialize(self, root):
        if not root: return "[]"
        queue = collections.deque()
        queue.append(root)
        res = []
        while queue:
            node = queue.popleft()
            if node:
                res.append(str(node.val))
                queue.append(node.left)
                queue.append(node.right)
            else: res.append("null")
        return '[' + ','.join(res) + ']'

    def deserialize(self, data):
        if data == "[]": return
        vals, i = data[1:-1].split(','), 1
        root = TreeNode(int(vals[0]))
        queue = collections.deque()
        queue.append(root)
        while queue:
            node = queue.popleft()
            if vals[i] != "null":
                node.left = TreeNode(int(vals[i]))
                queue.append(node.left)
            i += 1
            if vals[i] != "null":
                node.right = TreeNode(int(vals[i]))
                queue.append(node.right)
            i += 1
        return root
```

```java []
public class Codec {
    public String serialize(TreeNode root) {
        if(root == null) return "[]";
        StringBuilder res = new StringBuilder("[");
        Queue<TreeNode> queue = new LinkedList<>() {{ add(root); }};
        while(!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if(node != null) {
                res.append(node.val + ",");
                queue.add(node.left);
                queue.add(node.right);
            }
            else res.append("null,");
        }
        res.deleteCharAt(res.length() - 1);
        res.append("]");
        return res.toString();
    }

    public TreeNode deserialize(String data) {
        if(data.equals("[]")) return null;
        String[] vals = data.substring(1, data.length() - 1).split(",");
        TreeNode root = new TreeNode(Integer.parseInt(vals[0]));
        Queue<TreeNode> queue = new LinkedList<>() {{ add(root); }};
        int i = 1;
        while(!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if(!vals[i].equals("null")) {
                node.left = new TreeNode(Integer.parseInt(vals[i]));
                queue.add(node.left);
            }
            i++;
            if(!vals[i].equals("null")) {
                node.right = new TreeNode(Integer.parseInt(vals[i]));
                queue.add(node.right);
            }
            i++;
        }
        return root;
    }
}
```