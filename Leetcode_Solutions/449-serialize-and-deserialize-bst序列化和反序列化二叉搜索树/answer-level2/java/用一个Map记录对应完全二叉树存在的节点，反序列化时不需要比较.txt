速度和空间都一般
最近提交结果：
通过
显示详情 
执行用时 :
58 ms
, 在所有Java提交中击败了
9.59%
的用户
内存消耗 :
47.4 MB
, 在所有Java提交中击败了
24.30%
的用户
```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

   int h;
	int max;
	int size;
	int realSize;

	// Encodes a tree to a single string.
	// size + exist + data
	public String serialize(TreeNode root) {
		if (root == null)
			return "";
		calHight(root, 0);
		System.out.println("hight:" + h);
		System.out.println("max:" + max);
		System.out.println("realSize:" + realSize);
		size = (2 << h) - 1;
		System.out.println("size:" + size);
		// byte[] exist = new byte[size];
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();

		System.out.println("dd11:");

		// exist[0]=1;
		map.put(0, root.val);

		pro(root, map, 0);

		StringBuffer sb1 = new StringBuffer();
		StringBuffer sb2 = new StringBuffer();
		for (Integer i : map.keySet()) {
			sb1.append(i);
			sb1.append(",");
			sb2.append(map.get(i));
			sb2.append(",");
		}
		String sb11 = sb1.substring(0, sb1.length() - 1);
		String sb22 = sb2.substring(0, sb2.length() - 1);

		StringBuffer sbres = new StringBuffer();
		sbres.append(size);
		sbres.append("|");
		sbres.append(sb11);
		sbres.append("|");
		sbres.append(sb22);

		System.out.println("dd22:");
		System.out.println(sbres);
		return sbres.toString();
	}

	// Decodes your encoded data to tree.
	public TreeNode deserialize(String data) {
		if (data == null || data.length() == 0)
			return null;
		System.out.println(data);
		String[] s = data.split("\\|");

		int size = Integer.valueOf(s[0]);
		String[] kk = s[1].split(",");
		String[] dd = s[2].split(",");
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		for (int i = 0; i < kk.length; i++) {
			map.put(Integer.valueOf(kk[i]), Integer.valueOf(dd[i]));
		}

		TreeNode root = new TreeNode(map.get(0));
		setNode(map, 0, root);
		return root;

	}

	private void setNode(Map<Integer, Integer> map, int loc,
			TreeNode currentNode) {
		if ((loc * 2 + 2) >= size)
			return;

		if (map.containsKey(loc * 2 + 1)) {
			currentNode.left = new TreeNode(map.get(loc * 2 + 1));
			setNode(map, loc * 2 + 1, currentNode.left);
		}
		if (map.containsKey(loc * 2 + 2)) {
			currentNode.right = new TreeNode(map.get(loc * 2 + 2));
			setNode(map, loc * 2 + 2, currentNode.right);
		}

	}

	private void pro(TreeNode node, Map<Integer, Integer> map, int loc) {

		if (node.left != null) {
			map.put(2 * loc + 1, node.left.val);

			pro(node.left, map, 2 * loc + 1);
		}

		if (node.right != null) {
			map.put(2 * loc + 2, node.right.val);

			pro(node.right, map, 2 * loc + 2);
		}
	}

	private void calHight(TreeNode node, int ph) {

		if (ph > h)
			h = ph;
		if (node.val > max)
			max = node.val;
		realSize++;
		if (node.left != null) {
			calHight(node.left, ph + 1);
		}

		if (node.right != null) {
			calHight(node.right, ph + 1);
		}

		// return rh>lh?rh:lh;
	}
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```