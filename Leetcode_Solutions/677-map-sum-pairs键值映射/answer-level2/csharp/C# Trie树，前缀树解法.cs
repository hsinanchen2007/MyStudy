```
public class MapSum {
    class Node
    {
        public int Value { get; set; }

        public Dictionary<char, Node> Nodes = new Dictionary<char, Node>();

        public Node(int _value)
        {
            Value = _value;
        }
    }

    /** Initialize your data structure here. */
    public MapSum()
    {
        Root = new Node(0);
    }

    Node Root;

    public void Insert(string key, int val)
    {
        Node curr = Root;

        for (int i = 0; i < key.Length; i++)
        {
            var char_key = key[i];

            if (curr.Nodes.ContainsKey(char_key))
            {
                if (i == key.Length - 1)
                    curr.Nodes[char_key].Value = val;

                curr = curr.Nodes[char_key];
                continue;
            }

            curr.Nodes.Add(char_key, new Node(i == key.Length - 1 ? val : 0));
            curr = curr.Nodes[char_key];
        }
    }

    public int Sum(string prefix)
    {
        Node curr = Root;
        for (int i = 0; i < prefix.Length; i++)
        {
            var char_key = prefix[i];
            if (curr.Nodes.ContainsKey(char_key))
                curr = curr.Nodes[char_key];
            else
                return 0;
        }

        sum = 0;
        doSum(curr);

        return sum;
    }

    int sum = 0;

    private void doSum(Node node)
    {
        sum += node.Value;
        foreach (var item in node.Nodes)
        {
            doSum(item.Value);
        }
    }
}
```
