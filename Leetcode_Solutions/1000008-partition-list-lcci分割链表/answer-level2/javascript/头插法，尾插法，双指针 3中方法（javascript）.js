辅助函数
```javascript []
function del(node, prevNode) {
  if (prevNode) {
    prevNode.next = node.next
    node.next = null
  }
  return node
}
```


头插法
```javascript []


// 将小的插入头部
var partition1 = function (head, x) {
  if (!head) return head
  var prev = head,
    post = head.next;
  while (post) {
    log(head)
    if (post.val < x) {
      var n = del(post, prev)
      n.next = head
      head = n
      post = prev.next
    } else {
      prev = post
      post = post.next
    }
  }
  return head
};
```
图解

<![_Users_jiangbonan_dane_test_test.html.png](https://pic.leetcode-cn.com/d365af92429862219e3eff8a6f9b33d40e3715f161ed487ca396cdaceed0befc-_Users_jiangbonan_dane_test_test.html.png),![_Users_jiangbonan_dane_test_test.html (1).png](https://pic.leetcode-cn.com/5632deb8c06d04499370cf644862ef3e37ccf5111b82b655a6b2c39f5927ecb7-_Users_jiangbonan_dane_test_test.html%20\(1\).png),![_Users_jiangbonan_dane_test_test.html (2).png](https://pic.leetcode-cn.com/cbe43132328e8130940d6cb158aa1145c04332255c1d665ab648f226779c0453-_Users_jiangbonan_dane_test_test.html%20\(2\).png),![_Users_jiangbonan_dane_test_test.html (3).png](https://pic.leetcode-cn.com/99273d18fb9d0938206ebf55c0cac594102761740f46bb2850da80288ccec510-_Users_jiangbonan_dane_test_test.html%20\(3\).png),![_Users_jiangbonan_dane_test_test.html (4).png](https://pic.leetcode-cn.com/4c5e0d0b3cc837600c6f367969c6dd18762fa42b1f4355dbe09f18a1afd3d2b5-_Users_jiangbonan_dane_test_test.html%20\(4\).png),![_Users_jiangbonan_dane_test_test.html (5).png](https://pic.leetcode-cn.com/598dcc813405f9e8374365bc08403991783df190d97879068524b6e902d14173-_Users_jiangbonan_dane_test_test.html%20\(5\).png),![_Users_jiangbonan_dane_test_test.html (6).png](https://pic.leetcode-cn.com/844b2f067d8e1ea3cd1bfbb93d76699633b52e5f76389d482891704b68507282-_Users_jiangbonan_dane_test_test.html%20\(6\).png)>

尾插法 （图太难画了，没有了）
```javascript []
// 将大的插入尾部
var partition = function (head, x) {
  if (!head) return head
  // 由于不知道尾巴再哪里,所以将需要移除的节点单独存放在list2
  // 头部移除一起比较麻烦，虚拟一个头部list1,可以简化代码
  var list1 = new ListNode(null),
    list2 = new ListNode(null),
    tail = list2,
    post = head,
    head = prev = list1;
  list1.next = post
  while (post) {
    if (post.val >= x) {
      var node = del(post, prev)
      tail = tail.next = node
      post = prev.next
    } else {
      prev = post
      post = post.next
    }
  }
  if (list1 === prev) {
    return list2.next
  } else {
    prev.next = list2.next
    return list1.next
  }
};

```

双指针 
前指针表示已遍历的节点中最后一个小于X的节点
后指针当前访问的节点

- 当前访问的节点 < X , 将当前节点插入前指针后面
- 当前访问的节点 >= X, 继续遍历

 

``` javascript []
var partition = function (head, x) {
  if (!head) return head
  var
    list = new ListNode(null),
    prev = post = list;
  list.next = head

  while (post && post.next) {
    var cur = post.next
    if (cur.val < x) {
      if (post === prev) {
        post = prev = cur
      } else {
        var node = del(cur, post)
        node.next = prev.next
        prev = prev.next = node
      }
    } else {
      post = post.next
    }
  }
  return list.next
}
```
<![_Users_jiangbonan_dane_test_test.html (1).png](https://pic.leetcode-cn.com/94a1ecd92d76fe5185257c1d0630307a75b0eaba39973eaecda9e8f017753434-_Users_jiangbonan_dane_test_test.html%20\(1\).png),![_Users_jiangbonan_dane_test_test.html (2).png](https://pic.leetcode-cn.com/8ad24dbf65ac212a3d1dc36e9220d2e1c27a5bd7192b8bd22d1b6ac8bc8cbff3-_Users_jiangbonan_dane_test_test.html%20\(2\).png),![_Users_jiangbonan_dane_test_test.html (3).png](https://pic.leetcode-cn.com/719d92505faaa87185ad6261d18c805fb238bbaea0acaba00e2e5eb91cccaca0-_Users_jiangbonan_dane_test_test.html%20\(3\).png),![_Users_jiangbonan_dane_test_test.html (4).png](https://pic.leetcode-cn.com/0e8e4852c50e5545a92ff3a4ac79d80ace8e806c28941194c69bf2ad05aaa57f-_Users_jiangbonan_dane_test_test.html%20\(4\).png),![_Users_jiangbonan_dane_test_test.html (5).png](https://pic.leetcode-cn.com/4866a4ecd41aa0514cd2eff994a9c622de5ac63043f0614154f7ed2d791033ab-_Users_jiangbonan_dane_test_test.html%20\(5\).png),![_Users_jiangbonan_dane_test_test.html (6).png](https://pic.leetcode-cn.com/b5af109ba487a675e428b16c50404aa6b98aa677325f6e7d211ff4bdf593d292-_Users_jiangbonan_dane_test_test.html%20\(6\).png),![_Users_jiangbonan_dane_test_test.html (7).png](https://pic.leetcode-cn.com/6b3fc13a4dd2b229023712457d7a5d7a5b7856af49fcdaef4875fa189b18413d-_Users_jiangbonan_dane_test_test.html%20\(7\).png),![_Users_jiangbonan_dane_test_test.html (8).png](https://pic.leetcode-cn.com/01465407d308ea49bd5ec76525869a1a70b7ec57d2f9099a019e5f8c1acf4a0b-_Users_jiangbonan_dane_test_test.html%20\(8\).png)>
