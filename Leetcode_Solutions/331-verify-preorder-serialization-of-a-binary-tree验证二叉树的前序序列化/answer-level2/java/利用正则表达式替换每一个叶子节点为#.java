### 思路
前序序列化二叉树, 叶子节点一定是序列化字符串中形如"1,#,#"的子串.
把全部叶子摘掉 ( 即把形如"1,#,#"的子串, 替换为"#" ). 摘掉叶子后, 叶子节点的父节点变为新的叶子节点. 迭代此过程直到只剩根节点或者不存在有效叶子节点.
"#".equals(preorder) 判断是否剩下根节点
matcher.find()       判断是否能找到有效的叶子节点

如果最后只剩下根节点则为有效的前序序列化.<br>
本质上与使用堆栈的原理是一致的, 因为用到正则表达式性能一定不是最好的, 只是觉得这种写法挺有趣的.
### 完整代码
```java
class Solution {
    public boolean isValidSerialization(String preorder) {
        Pattern pattern = Pattern.compile("[^,#]+,#,#");
        Matcher matcher = pattern.matcher(preorder);

        while (!"#".equals(preorder) && matcher.find()) {
            preorder = matcher.replaceAll("#");
            matcher = pattern.matcher(preorder);
        }

        return "#".equals(preorder);
    }
}
```