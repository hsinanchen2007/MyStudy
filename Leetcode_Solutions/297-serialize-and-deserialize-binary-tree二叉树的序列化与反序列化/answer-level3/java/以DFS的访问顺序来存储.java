只要做好存储的string中能反应边界条件，那么ser与deser一定能相互转化

```
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

import javafx.util.Pair;
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Codec {
    final private char TreeStrHeaderChar = '[';
    final private char TreeStrTailChar = ']';
    final private char NodeSplitterChar = ',';
    final private String NodeSplitter = ",";
    final private String NodeNULLStr = "null";

    private void setArrayVal(ArrayList<Integer> array, int index, Integer val) {
        while (array.size() < (1 + index))
            array.add(null);
        array.set(index, val);
    }

    private String genTreeStr(ArrayList<Integer> array) {
        StringBuilder strBuilder = new StringBuilder();

        strBuilder.append(TreeStrHeaderChar);

        boolean isFirstOne = true;
        for (Integer i : array) {
            if (isFirstOne) {
                isFirstOne = false;
            } else {
                strBuilder.append(NodeSplitterChar);
            }

            if (i == null) {
                strBuilder.append(NodeNULLStr);
            } else {
                strBuilder.append(i);
            }
        }

        strBuilder.append(TreeStrTailChar);

        return strBuilder.toString();
    }

    private Integer[] genTreeIntArray(String treeStr) {
        if (treeStr ==null || treeStr=="[]" || treeStr.length() <2)
            return null;

        int headIndex = treeStr.indexOf(TreeStrHeaderChar, 0);
        int tailIndex = treeStr.indexOf(TreeStrTailChar, 0);
        String data = treeStr.substring(headIndex+1, tailIndex);
        String[] intStrArray = data.split(NodeSplitter);

        if( intStrArray==null || intStrArray.length<1)
            return null;

        Integer[] intArray = new Integer[intStrArray.length];
        int i = 0;
        for (String s : intStrArray) {
            if (s.equals(NodeNULLStr)) {
                intArray[i++] = null;
            } else {
                intArray[i++] = Integer.valueOf(s);
            }
        }
        return intArray;
    }

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {

        // special cases
        //
        if (root == null)
            return "[]";
        if (root.left == null && root.right == null)
            return TreeStrHeaderChar + String.valueOf(root.val) + TreeStrTailChar;

        // typical cases
        //
        ArrayList<Integer> nodeArray = new ArrayList<>();
        LinkedList<Pair<TreeNode, Integer>> nodeStack = new LinkedList<>();
        nodeStack.add(new Pair<TreeNode, Integer>(root, 0));
        while (!nodeStack.isEmpty()) {

            // get current (not null) node
            Pair<TreeNode, Integer> element = nodeStack.pollLast();
            TreeNode cNode = element.getKey();
            int cIndex = element.getValue();

            // handle current node
            this.setArrayVal(nodeArray, cIndex, cNode.val);

            if (cNode.right != null) {
                nodeStack.add(new Pair<TreeNode, Integer>(cNode.right, 2 * cIndex + 2));
            }
            if (cNode.left != null) {
                nodeStack.add(new Pair<TreeNode, Integer>(cNode.left, 2 * cIndex + 1));
            }
        }

        return genTreeStr(nodeArray);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        // special cases
        //
        if (data == null || data == "[]")
            return null;

        // typical cases
        //

        // prepare
        Integer[] nodeValArray = this.genTreeIntArray(data);
        final int nodeCount = nodeValArray.length;
        TreeNode[] nodeArray = new TreeNode[nodeCount];
        Arrays.fill(nodeArray, null);

        //
        for (int index = nodeCount - 1; index >= 0; index--) {
            // already generated
            if (nodeArray[index] != null)
                continue;

            Integer nodeVal = nodeValArray[index];
            if ( nodeVal!= null) {
                TreeNode node = new TreeNode((int)nodeVal);
                if (index * 2 + 1 < nodeCount) {
                    node.left = nodeArray[index * 2 + 1];
                }else{
                    node.left = null;
                }

                if (index * 2 + 2 < nodeCount) {
                    node.right = nodeArray[index * 2 + 2];
                }else{
                    node.right = null;
                }

                nodeArray[index] = node;
            }
        }

        return nodeArray[0];
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```