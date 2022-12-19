一开始也想过，把树序列化成字符串，然后对比是不是字符串的子串，后来发现这种方式不可行
```
[3,4,5,1,2,null,null,0]
[4,1,2]
```
去跑上面这个测试用例就知道了。

__解题思路：__
遍历s，s节点下的子树和t是不是同一颗树
```
var isSame = function(s, t) {
    if (!s && !t) return true;
    if (!s || !t) return false;
    if (s.val != t.val) return false;
    return isSame(s.left, t.left) && isSame(s.right, t.right);
}
var isSubtree = function(s, t) {
    if (!s) return false;
    if (isSame(s, t)) return true;
    return isSubtree(s.left, t) || isSubtree(s.right, t);
};
```