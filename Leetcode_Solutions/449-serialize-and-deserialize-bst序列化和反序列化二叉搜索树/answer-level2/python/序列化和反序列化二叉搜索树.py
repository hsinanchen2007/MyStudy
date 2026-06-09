####  序列化一个二叉树表示：
- 对树的结构编码
- 对树节点的值编码
- 利用分隔符分隔字符串中的值

![在这里插入图片描述](https://pic.leetcode-cn.com/338dd8fbe5e9b81f3a874fb75e389c9beb6ac2f6ad318d2d832592d880d3155f-file_1576477181656){:width=500}
{:align=center}


####  方法一：后序遍历优化树结构的空间
**算法：**

二叉搜索树能只够通过前序序列或后序序列构造，是因为以下两个因素：
- [二叉树可以通过前序序列或后序序列和中序序列构造](https://leetcode.com/articles/construct-binary-tree-from-postorder-and-inorder-t/)。
- [二叉搜索树的中序序列是递增排序的序列，`inorder = sorted(preorder)`](https://leetcode.com/articles/delete-node-in-a-bst/)。

说明我们只需要直到了前序序列或后序序列相当于我们也知道了中序序列，可以通过排序获得。

序列化可以很容易的实现，但是对于反序列化我们选择后续遍历会更好。
![在这里插入图片描述](https://pic.leetcode-cn.com/09d70ebfbf5f7f3c81ff83c2fbb08fc730040b4e6b3758ac2e7fb041e5279454-file_1576477181691){:width=500}
{:align=center}

```python [solution1-Python]
class Codec:
    def serialize(self, root):
        """
        Encodes a tree to a single string.
        """
        def postorder(root):
            return postorder(root.left) + postorder(root.right) + [root.val] if root else []
        return ' '.join(map(str, postorder(root)))

    def deserialize(self, data):
        """
        Decodes your encoded data to tree.
        """
        def helper(lower = float('-inf'), upper = float('inf')):
            if not data or data[-1] < lower or data[-1] > upper:
                return None
            
            val = data.pop()
            root = TreeNode(val)
            root.right = helper(val, upper)
            root.left = helper(lower, val)
            return root
        
        data = [int(x) for x in data.split(' ') if x]
        return helper()
```

```java [solution1-Java]
public class Codec {
  public StringBuilder postorder(TreeNode root, StringBuilder sb) {
    if (root == null) return sb;
    postorder(root.left, sb);
    postorder(root.right, sb);
    sb.append(root.val);
    sb.append(' ');
    return sb;
  }

  // Encodes a tree to a single string.
  public String serialize(TreeNode root) {
    StringBuilder sb = postorder(root, new StringBuilder());
    sb.deleteCharAt(sb.length() - 1);
    return sb.toString();
  }

  public TreeNode helper(Integer lower, Integer upper, ArrayDeque<Integer> nums) {
    if (nums.isEmpty()) return null;
    int val = nums.getLast();
    if (val < lower || val > upper) return null;

    nums.removeLast();
    TreeNode root = new TreeNode(val);
    root.right = helper(val, upper, nums);
    root.left = helper(lower, val, nums);
    return root;
  }

  // Decodes your encoded data to tree.
  public TreeNode deserialize(String data) {
    if (data.isEmpty()) return null;
    ArrayDeque<Integer> nums = new ArrayDeque<Integer>();
    for (String s : data.split("\\s+"))
      nums.add(Integer.valueOf(s));
    return helper(Integer.MIN_VALUE, Integer.MAX_VALUE, nums);
  }
}
```

**复杂度分析**

* 时间复杂度：序列化和反序列都使用了 $\mathcal{O}(N)$ 的时间。
* 空间复杂度：$\mathcal{O}(N)$，我们存储了整个树。编码序列：需要 $(N - 1)$ 个分隔符和 $N$ 个节点的值。树的结构和顺序不占用空间。


####  方法二：将节点值转换为四个字节的字符串优化空间
**算法：**
- 方法一在若节点值较小时消耗的空间较小，若节点值较大则会消耗较大的空间。
- 举个例子，树 `[2,null,3,null,4]` 被编码为 `"4 3 2"`，使用了 `5` 个字节存放节点值和分隔符。节点值和分隔符各需要一个字节。这种情况下消耗的空间较小。
- 若树是 `[12345,null,12346,null,12347]`，则它被编码为 `"12347 12346 12345"`，消耗了 `17` 字节的空间存放 `3` 个整数和 `2` 个分隔符。仅仅存放节点的值就消耗了 `15` 字节。然而存放一个整数只需要 `4` 个字节就够了，所以 `12` 个字节就足够存放 `3` 个整数。所以我们可以优化节点值所使用的空间。
- 将节点值转换为四个字节字符串。
- 
![在这里插入图片描述](https://pic.leetcode-cn.com/735384b0c44b667085f13776a53e396c5ceb9853370ce34b4eff81d80041cac9-file_1576477181679){:width=500}
{:align=center}

```python [solution2-Python]
class Codec:
    def postorder(self, root):
        return self.postorder(root.left) + self.postorder(root.right) + [root.val] if root else []
        
    def int_to_str(self, x):
        """
        Encodes integer to bytes string.
        """
        bytes = [chr(x >> (i * 8) & 0xff) for i in range(4)]
        bytes.reverse()
        bytes_str = ''.join(bytes)
        return bytes_str
        
    def serialize(self, root):
        """
        Encodes a tree to a single string.
        """
        lst = self.postorder(root)
        lst = [self.int_to_str(x) for x in lst]
        return 'ç'.join(map(str, lst))
    
    def str_to_int(self, bytes_str):
        """
        Decodes bytes string to integer.
        """
        result = 0
        for ch in bytes_str:
            result = result * 256 + ord(ch)
        return result
        
    def deserialize(self, data):
        """
        Decodes your encoded data to tree.
        """
        def helper(lower = float('-inf'), upper = float('inf')):
            if not data or data[-1] < lower or data[-1] > upper:
                return None
            
            val = data.pop()
            root = TreeNode(val)
            root.right = helper(val, upper)
            root.left = helper(lower, val)
            return root
        
        data = [self.str_to_int(x) for x in data.split('ç') if x]
        return helper() 
```

**复杂度分析**

* 时间复杂度：序列化和反序列化都使用了 $\mathcal{O}(N)$ 的时间。
* 空间复杂度：$\mathcal{O}(N)$，我们存储了整个树。编码序列：分隔符需要 $2(N - 1)$ 字节和 节点值需要 $4 N$ 字节。树的结构和顺序不占用空间。

####  方法三：不使用分隔符
**算法：**
- 方法二可以在不使用分隔符的情况下完成工作。
- 因为所有节点的值为 `4` 个字节，因此我们可以把编码序列 `4` 个字节当作一个块，将每个块转换为整数，因此可以不使用分隔符。

![在这里插入图片描述](https://pic.leetcode-cn.com/9754c2528dd43e5fc669103c42148e5b14ca3a5c5ef3f39cc0eb468e8cde18c6.png){:width=500}
{:align=center}

```python [solution3-Python]
class Codec:
    def postorder(self, root):
        return self.postorder(root.left) + self.postorder(root.right) + [root.val] if root else []
        
    def int_to_str(self, x):
        """
        Encodes integer to bytes string
        """
        bytes = [chr(x >> (i * 8) & 0xff) for i in range(4)]
        bytes.reverse()
        bytes_str = ''.join(bytes)
        return bytes_str
        
    def serialize(self, root):
        """
        Encodes a tree to a single string.
        """
        lst = [self.int_to_str(x) for x in self.postorder(root)]
        return ''.join(map(str, lst))
    
    def str_to_int(self, bytes_str):
        """
        Decodes bytes string to integer.
        """
        result = 0
        for ch in bytes_str:
            result = result * 256 + ord(ch)
        return result
        
    def deserialize(self, data):
        """
        Decodes your encoded data to tree.
        """
        def helper(lower = float('-inf'), upper = float('inf')):
            if not data or data[-1] < lower or data[-1] > upper:
                return None
            
            val = data.pop()
            root = TreeNode(val)
            root.right = helper(val, upper)
            root.left = helper(lower, val)
            return root
        
        n = len(data)
        # split data string into chunks of 4 bytes
        # and convert each chunk to int
        data = [self.str_to_int(data[4 * i : 4 * i + 4]) for i in range(n // 4)]
        return helper() 
```

```java [solution3-Java]
public class Codec {
  // Encodes a tree to a list.
  public void postorder(TreeNode root, StringBuilder sb) {
    if (root == null) return;
    postorder(root.left, sb);
    postorder(root.right, sb);
    sb.append(intToString(root.val));
  }

  // Encodes integer to bytes string
  public String intToString(int x) {
    char[] bytes = new char[4];
    for(int i = 3; i > -1; --i) {
      bytes[3 - i] = (char) (x >> (i * 8) & 0xff);
    }
    return new String(bytes);
  }

  // Encodes a tree to a single string.
  public String serialize(TreeNode root) {
    StringBuilder sb = new StringBuilder();
    postorder(root, sb);
    return sb.toString();
  }

  // Decodes list to tree.
  public TreeNode helper(Integer lower, Integer upper, ArrayDeque<Integer> nums) {
    if (nums.isEmpty()) return null;
    int val = nums.getLast();
    if (val < lower || val > upper) return null;

    nums.removeLast();
    TreeNode root = new TreeNode(val);
    root.right = helper(val, upper, nums);
    root.left = helper(lower, val, nums);
    return root;
  }

  // Decodes bytes string to integer
  public int stringToInt(String bytesStr) {
    int result = 0;
    for(char b : bytesStr.toCharArray()) {
      result = (result << 8) + (int)b;
    }
    return result;
  }

  // Decodes your encoded data to tree.
  public TreeNode deserialize(String data) {
    ArrayDeque<Integer> nums = new ArrayDeque<Integer>();
    int n = data.length();
    for(int i = 0; i < (int)(n / 4); ++i) {
      nums.add(stringToInt(data.substring(4 * i, 4 * i + 4)));
    }

    return helper(Integer.MIN_VALUE, Integer.MAX_VALUE, nums);
  }
}
```

**复杂度分析**

* 时间复杂度：序列化和反序列化都使用了 $\mathcal{O}(N)$ 的时间。
* 空间复杂度：$\mathcal{O}(N)$，存储了整个树。编码序列：没有分隔符，没有使用额外的空间，仅仅使用了每 $4 N$ 字节存放节点值。