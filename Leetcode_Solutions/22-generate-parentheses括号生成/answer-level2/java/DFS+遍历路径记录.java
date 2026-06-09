### 解题思路
先强调几个事实：
尝试去生成一个有效的括号串时，如果：
1、剩下的做括号个数大于0，可以在前面括号串的基础上再加上一个左括号
2、如果，剩余的右括号<左括号，也就是 字符串中的  右括号>左括号   了，显然是不合理的，无论怎么加括号，该字符串都不会是有效括号串了
3、如果 剩余的 右括号>左括号 ，也就是 字符串中的  右括号<左括号  ，才有可能添加右括号

综上，如果，将添加括号的过程一个生成二叉树的过程，添加子节点生成条件，就有两种情况：
1、剩余左括号个数>0，添加左括号，生成左儿子
2、剩余的右括号>左括号，添加右括号，生成右儿子

如何避免生成重复的字符串，从二叉树的生成过程可以看出，如果是一样的字符串，那就是二叉树的路径会发生完全重合，显然不可能
因此，按照以上两个规则生成二叉树时，就自然完成了去重流程

解题步骤：
（1） 先按照规则生括号二叉树
（2）DFS搜索出末端节点，即为最终的结果
注：生成二叉树的过程，其实就可以看作是 DFS的过程，可以将2步合成1步

### 代码

```java


import java.util.ArrayList;
import java.util.List;


/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。



示例：

输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


先强调几个事实：
尝试去生成一个有效的括号串时，如果：
1、剩下的做括号个数大于0，可以在前面括号串的基础上再加上一个左括号
2、如果，剩余的右括号<左括号，也就是 字符串中的  右括号>左括号   了，显然是不合理的，无论怎么加括号，该字符串都不会是有效括号串了
3、如果 剩余的 右括号>左括号 ，也就是 字符串中的  右括号<左括号  ，才有可能添加右括号

综上，如果，将添加括号的过程一个生成二叉树的过程，添加子节点生成条件，就有两种情况：
1、剩余左括号个数>0，添加左括号，生成左儿子
2、剩余的右括号>左括号，添加右括号，生成右儿子

如何避免生成重复的字符串，从二叉树的生成过程可以看出，如果是一样的字符串，那就是二叉树的路径会发生完全重合，显然不可能
因此，按照以上两个规则生成二叉树时，就自然完成了去重流程

解题步骤：
（1） 先按照规则生括号二叉树
（2）DFS搜索出末端节点，即为最终的结果
注：生成二叉树的过程，其实就可以看作是 DFS的过程，可以将2步合成1步


 */
class Solution {
    public List<String> generateParenthesis(int n) {
        Node root = new Node(Node.LEFT);
        generateTree(n - 1, n, root);

        List<String> result = new ArrayList<>();
        generateRoute(root, new StringBuilder(), result);

        return result;
    }

    private void generateRoute(Node currentNode, StringBuilder route, List<String> result) {
        StringBuilder newRoute = route.append(currentNode.value);

        if (null == currentNode.leftNode && null == currentNode.rightNode) {
            //说明当前是末端节点
            result.add(newRoute.toString());
            System.out.println(newRoute);
//            newRoute.delete(newRoute.length() - 1, newRoute.length());
            return;
        }

        if (null != currentNode.leftNode) {
            generateRoute(currentNode.leftNode, newRoute, result);
            newRoute.delete(newRoute.length() - 1, newRoute.length());//回退到上一层时，同时回退对路径的修改
        }

        if (null != currentNode.rightNode) {
            generateRoute(currentNode.rightNode, newRoute, result);
            newRoute.delete(newRoute.length() - 1, newRoute.length());//回退到上一层时，同时回退对路径的修改
        }


    }


    private void generateTree(int remainedLeft, int remainedRight, Node currentNode) {
        if (0 == remainedLeft && 0 == remainedRight) {
            return;
        }
        if (remainedLeft > 0) {
            //添加左儿子
            currentNode.leftNode = new Node(Node.LEFT);
            generateTree(remainedLeft - 1, remainedRight, currentNode.leftNode);

        }
        if (remainedRight > remainedLeft) {
            //添加右儿子
            currentNode.rightNode = new Node(Node.RIGHT);
            generateTree(remainedLeft, remainedRight - 1, currentNode.rightNode);
        }

    }


    //二叉树节点
    static class Node {
        public static String LEFT = "(";
        public static String RIGHT = ")";

        Node(String value) {
            this.value = value;
        }

        public String value;
        public Node leftNode = null;
        public Node rightNode = null;

        @Override
        public String toString() {
            return "Node{" +
                    "value='" + value + '\'' +
                    ", leftNode=" + leftNode +
                    ", rightNode=" + rightNode +
                    '}';
        }
    }
}

```