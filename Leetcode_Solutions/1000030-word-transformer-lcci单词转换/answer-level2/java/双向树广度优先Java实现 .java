
 1.将beginWord创建为根节点
 2.遍历wordList，添加子节点，直到找到endWord节点，并返回
 3. 由于为双向树，根据endWord节点，反推到beginWord， 即可得到逆序的转换序列
 4. 再逆序，得到转换序列

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class FindLadders {
    public List<String> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<String> result = new ArrayList<String>();

        if (!wordList.contains(endWord)) {
            return result;
        }

        // 1.将beginWord创建为根节点
        wordList.remove(beginWord);
        MulTreeNode root = new MulTreeNode();
        root.setName(beginWord);

        // 2.遍历wordList，添加子节点，直到找到endWord节点，并返回
        MulTreeNode endNode = addChildren(root, endWord, wordList);
        
        //3. 由于为双向树，根据endWord节点，反推到beginWord， 即可得到逆序的转换序列
        if (endNode != null) {
            result.add(endNode.getName());
            MulTreeNode parent = endNode.getParent();
            while (parent.getParent() != null) {
                result.add(parent.getName());
                parent = parent.getParent();
            }
            result.add(parent.getName());
        }

        //4. 再逆序，得到转换序列
        Collections.reverse(result);
        return result;
    }

    //
    private MulTreeNode addChildren(MulTreeNode root, String endWord, List<String> wordList) {
        String rootName = root.getName();
        for (String word : wordList) {
            if (satisfy(rootName, word)) {
                MulTreeNode node = new MulTreeNode();
                node.setName(word);
                node.setParent(root);
                root.addChildren(node);
                if (word.equals(endWord)) {
                    return node;
                }
            }
        }

        for (MulTreeNode node : root.getChildren()) {
            wordList.remove(node.getName());
        }

        if (root.getChildren().size() > 0) {
            for (MulTreeNode node : root.getChildren()) {
                MulTreeNode endNode = addChildren(node, endWord, wordList);
                if (null != endNode) {
                    return endNode;
                }
            }
        }

        return null;
    }

    private boolean satisfy(String rootName, String word) {
        int len = rootName.length();
        if (len != word.length()) {
            return false;
        }
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (rootName.charAt(i) != word.charAt(i)) {
                cnt++;
            }
        }
        return cnt == 1;
    }
}

class MulTreeNode {
    private String name;
    private MulTreeNode parent;
    private List<MulTreeNode> children = new ArrayList<MulTreeNode>();

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<MulTreeNode> getChildren() {
        return children;
    }

    public void addChildren(MulTreeNode node) {
        this.children.add(node);
    }

    public MulTreeNode getParent() {
        return parent;
    }

    public void setParent(MulTreeNode parent) {
        this.parent = parent;
    }
}

