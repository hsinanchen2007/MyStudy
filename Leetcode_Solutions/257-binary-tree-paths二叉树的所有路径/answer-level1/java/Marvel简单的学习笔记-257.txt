## String与StringBuilder在本题中的区别
解题思路很简单，通过dfs遍历每个结点，遍历的同时，构造字符串，若遇到叶子结点则将当前字符串添加到结果res中；若不是叶子结点，则递归遍历左右子结点。代码如下：
```java
class Solution {
    private List<String> res;
    public List<String> binaryTreePaths(TreeNode root) {
        res = new LinkedList<>();
        dfs(root, "");
        return res;
    }
    private void dfs(TreeNode root, String path) {
        if(root == null)    return;
        path += String.valueOf(root.val);
        if(root.left == null && root.right == null)
        {
            res.add(path);
            return;
        }
        path += "->";
        dfs(root.left, path);
        dfs(root.right, path);
    }
}
```
阅读完代码后，想借本题讲一下String与StringBuilder，若上述代码中的String全部改为StringBuilder，结果如何？
如果不确定，可自行尝试。
结果是答案错误，若执行题目提供的样例，会得到类似"1->2->53"的答案。原因如下：

首先明确一点：**Java中方法的参数传递方式只有一种，就是值传递**！
即方法中的形参是实参的副本，若实参为primitive基本类型，例如int，则形参就是这个int的复制品；
若实参为引用变量类型，则形参就是这个引用变量的复制品，只不过两个引用变量指向的是同一个对象。本质就是值传递。

至此，若path变量的类型改为了StringBuilder，则每次递归访问一个结点，若非空，当前方法的path引用变量所指向的StringBuilder对象都会改变（添加结点值添加箭头），因为StringBuilder为**可变字符串类型**。这意味着，每次方法结束返回到上一层时，path所指向的StringBuilder对象都已经改变了，已经不是之前的字符串了，且每一层的path都会受到影响，它们都指向同一个StringBuilder对象。所以本题用StringBuilder会出错，除非每次返回前修改字符串对象，即删除当前结点值和箭头。

肯定有人会问，String不也是引用类型，不也得在返回前修改字符串吗？
String确实为引用类型，但它是**不可变字符串类**，这意味着，每递归访问一个结点，若要修改当前path所指向的String字符串对象（添加结点值添加箭头），由于String是不可变的，即String的实例一旦生成就不会再改变，所以经语句`path += String.valueOf(root.val);`修改后，原来的String对象还在，没有改变，但path此时指向的是新的字符串对象了，以此达到修改字符串的目的。所以，当方法结束返回到上一层时，path所指向的字符串对象还是原来的那个不能改变的旧对象，因此本题可以使用String，这就是区别。

综上，String：不可变字符串类；
StringBuilder：可变字符串类，性能较高，但线程不安全；
StringBuffer：可变字符串类，线程安全，性能比StringBuilder略低。