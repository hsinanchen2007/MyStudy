![image.png](https://pic.leetcode-cn.com/692777f52ee59f7c3e189205e50082e2478ec338e7872fa223d4c34978367af3-image.png)

```
public class Solution
    {
        public Node CloneGraph(Node node)
        {
            if (node == null) return null;
            Dictionary<int, Node> cloneMap = new Dictionary<int, Node>();
            Queue<Node> protoNodes = new Queue<Node>();
            protoNodes.Enqueue(node);
            cloneMap.Add(node.val, new Node(node.val, new List<Node>()));
            while (protoNodes.TryDequeue(out Node protoNode))
            {
                Node cloneNode = cloneMap.GetValueOrDefault(protoNode.val);
                foreach (Node n in protoNode.neighbors)
                {
                    if (!cloneMap.ContainsKey(n.val))
                    {
                        Node nb = new Node(n.val, new List<Node>());
                        protoNodes.Enqueue(n);
                        cloneMap.Add(n.val, nb);
                        cloneNode.neighbors.Add(nb);
                    }
                    else
                    {
                        cloneNode.neighbors.Add(cloneMap.GetValueOrDefault(n.val));
                    }
                }
            }
            return cloneMap.GetValueOrDefault(node.val);

        }
    }

```
