#### 方法 1：深度优先搜索 [Time Limit Exceeded]

**算法**

由于杀死一个进程会导致杀死它所有孩子进程，最简单的办法就是遍历 $ppid$ 数组并找出所有需要被杀死的孩子进程。对于每个被杀死的孩子进程，我们递归调用 `killProcess` 函数，将当前孩子作为被杀死的父亲进程，以找到该孩子进程的孩子进程。在每一次调用中，我们都遍历 $ppid$ 数组来找到当前进程的子进程。同时，在调用函数的过程中，我们将被杀死的进程放入列表 $l$ 中，并最终返回这个列表。

```Java []
public class Solution {

    public List < Integer > killProcess(List < Integer > pid, List < Integer > ppid, int kill) {
        List < Integer > l = new ArrayList < > ();
        if (kill == 0)
            return l;
        l.add(kill);
        for (int i = 0; i < ppid.size(); i++)
            if (ppid.get(i) == kill)
                l.addAll(killProcess(pid, ppid, pid.get(i)));
        return l;
    }
}

```

**复杂度分析**

* 时间复杂度：$O(n^n)$。最坏情况下函数调用需要 $O(n^n)$ 的时间。

* 空间复杂度：$O(n)$。递归树的深度最多为 $n$。

#### 方法 2：模拟树 [Accepted]

**算法**

我们可以把进程间的关系看做一棵树，我们构建这样一棵树：每个节点保存它自己的值和它直接孩子节点的信息。一旦构建好这棵树，我们可以直接删除要求的节点，然后递归杀死它的子进程，而不需要像前一种方法一样对每个进程都一遍又一遍地遍历 $ppid$ 数组。

为了实现这个方法，我们使用 $Node$ 类来表示树中的一个节点，每个节点表示一个进程。因此每个节点保存着它自己的值 ($Node.val$) 和它所有直接孩子进程的一个列表 ($Node.children$) 。我们遍历 $pid$ 数组并为每一个元素建立一个节点。然后，我们遍历 $ppid$ 数组并将父节点和子节点通过父节点的 $Node.children$ 联系起来。通过这样的过程，我们把给定的进程构建成了一棵树的结构。

现在我们已经有了树结构，我们可以把要删掉的进程添加到 $l$ 列表中去。我们可以直接获得每个节点在树中的的孩子进程，并添加到返回列表中，我们重复此过程，递归地得到所有的孩子进程。

```Java []
public class Solution {
    class Node {
        int val;
        List < Node > children = new ArrayList < > ();
    }
    public List < Integer > killProcess(List < Integer > pid, List < Integer > ppid, int kill) {
        HashMap < Integer, Node > map = new HashMap < > ();
        for (int id: pid) {
            Node node = new Node();
            node.val = id;
            map.put(id, node);
        }
        for (int i = 0; i < ppid.size(); i++) {
            if (ppid.get(i) > 0) {
                Node par = map.get(ppid.get(i));
                par.children.add(map.get(pid.get(i)));
            }
        }
        List < Integer > l = new ArrayList < > ();
        l.add(kill);
        getAllChildren(map.get(kill), l);
        return l;
    }
    public void getAllChildren(Node pn, List < Integer > l) {
        for (Node n: pn.children) {
            l.add(n.val);
            getAllChildren(n, l);
        }
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n)$。我们需要遍历大小为$n$ 的 $ppid$ 和 $pid$ 数组各一遍。由于一个节点只会有一个父节点，所以函数 `getAllChildren` 最多会调用 $n$ 次。

* 空间复杂度：$O(n)$。使用了大小为 $n$ 的 $map$。

#### 方法 3：哈希表 + 深度优先搜索 [Accepted]

**算法**

与其构建一棵树的结构，我们可以直接使用一个数据结构，保存特定进程的值和它的子节点。我们使用哈希表 $map$ ，它以 ${parent: [list of all its direct children]}$ 的形式保存了数据。

现在遍历一遍 $ppid$ 数组，同时把相应的 $pid$ 值添加到孩子列表，我们可以获得一个更好的保存了 父-子 进程关系的结构。

与前一种方法类似的，我们现在可以把被杀死的进程添加到返回列表中并通过哈希表递归获得孩子节点的信息。

<![image.png](https://pic.leetcode-cn.com/a7a481b58060408563b862b9731d209aa7e8d344ccf108ccf5398f59625a9f9f-image.png),![image.png](https://pic.leetcode-cn.com/b526bb427636fb5600f49388d5d52eba11303c2a42eeae08c3a4ee5ff317d820-image.png),![image.png](https://pic.leetcode-cn.com/e0bda251a8a96a392e7bf60fdb5208808ce96fef47eb373487a5adeef2c3e18e-image.png),![image.png](https://pic.leetcode-cn.com/42609ed2da11073cd64f89e4739b65353003a4503942d659e8becae0f2ed2192-image.png),![image.png](https://pic.leetcode-cn.com/70c7a9ba12051ec7cefc144cbf8bd54ff4f1f209191ec22657ea75e55d55f4f3-image.png),![image.png](https://pic.leetcode-cn.com/1a703cd4a4a259003767ab60ecac21f465023107fef73355de07f246962c5e18-image.png),![image.png](https://pic.leetcode-cn.com/44a976fbde0f010671f53bd8c441d119524eeab1b6c4cdbdb590d3cc7b37c0ce-image.png),![image.png](https://pic.leetcode-cn.com/8ae6d6c7edf21e0f451a2d24c8b51465f69f4dcbcd1ee2e992d6769012e1228f-image.png)>

```Java []
public class Solution {
    public List < Integer > killProcess(List < Integer > pid, List < Integer > ppid, int kill) {
        HashMap < Integer, List < Integer >> map = new HashMap < > ();
        for (int i = 0; i < ppid.size(); i++) {
            if (ppid.get(i) > 0) {
                List < Integer > l = map.getOrDefault(ppid.get(i), new ArrayList < Integer > ());
                l.add(pid.get(i));
                map.put(ppid.get(i), l);
            }
        }
        List < Integer > l = new ArrayList < > ();
        l.add(kill);
        getAllChildren(map, l, kill);
        return l;
    }
    public void getAllChildren(HashMap < Integer, List < Integer >> map, List < Integer > l, int kill) {
        if (map.containsKey(kill))
            for (int id: map.get(kill)) {
                l.add(id);
                getAllChildren(map, l, id);
            }
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n)$。我们需要遍历大小为 $n$ 的数组 $ppid$ 一遍。由于每个节点最多只会是一个节点的孩子节点，函数 `getAllChildren` 最多调用 $n$ 次。

* 空间复杂度：$O(n)$。使用了大小为 $n$ 的 $map$。

#### 方法 4：哈希表 + 宽度优先搜索 [Accepted]

**算法**

我们也可以利用宽度优先搜索来获得某个节点的所有孩子信息 （包括直接的和间接的）。首先我们还是按照方法 3 中 $(process: [list of all its direct children]$ 的结构建立好数据结构。

为了获得某个要被杀死的特定父进程的所有子进程，我们使用宽度优先搜索。我们将要被杀死的进程添加到 $queue$ 中，然后我们从 $queue$ 的头部移出一个元素并把它添加到最终返回列表，然后我们把这个节点的所有直接子进程添加到 $queue$ 中。重复此过程直到 $queue$ 为空。

<![image.png](https://pic.leetcode-cn.com/b6997b6bf2606777951ab7f28287010df8139ebcc2bc768dbb1b6d7081cef19a-image.png),![image.png](https://pic.leetcode-cn.com/e7d3ba32c42515125762330c61caa1f959911dbd89ed9c8636e0757f7854b886-image.png),![image.png](https://pic.leetcode-cn.com/0962db4edec1d58090437830544cfd1fec33ce2535e62af8a045ef786e1fb116-image.png),![image.png](https://pic.leetcode-cn.com/a0958760dd5545369fe8a9f3a7e8ccac4b94c01936edc882918f11dff194ac9a-image.png),![image.png](https://pic.leetcode-cn.com/63a86af07d08e93c1ffad821659623d1d2746f575d86bd85d3bf0c0570623ec0-image.png),![image.png](https://pic.leetcode-cn.com/51e26b6f86ffcc832d1c7fddd04f544975ea7ad892e8b26e1ab2e6567c18f335-image.png),![image.png](https://pic.leetcode-cn.com/64e3c32619d1a9eb7c0a77ba5b4e1e8179bc9e0eb71733799ef8e988358ba6ef-image.png),![image.png](https://pic.leetcode-cn.com/d79135ccadfc4695b0518e4ff11ff076a6afac31fc0eb7c0ffef69a85d1c848b-image.png),![image.png](https://pic.leetcode-cn.com/4e4f7245777e81824384b10cc42f88ec7f4fecf51fd24c187bd7844b4a845521-image.png)>

```Java []
public class Solution {

    public List < Integer > killProcess(List < Integer > pid, List < Integer > ppid, int kill) {
        HashMap < Integer, List < Integer >> map = new HashMap < > ();
        for (int i = 0; i < ppid.size(); i++) {
            if (ppid.get(i) > 0) {
                List < Integer > l = map.getOrDefault(ppid.get(i), new ArrayList < Integer > ());
                l.add(pid.get(i));
                map.put(ppid.get(i), l);
            }
        }
        Queue < Integer > queue = new LinkedList < > ();
        List < Integer > l = new ArrayList < > ();
        queue.add(kill);
        while (!queue.isEmpty()) {
            int r = queue.remove();
            l.add(r);
            if (map.containsKey(r))
                for (int id: map.get(r))
                    queue.add(id);
        }
        return l;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n)$。我们需要遍历大小为 $n$ 的 $ppid$ 数组一次，同时 $queue$ 最多有 $n$ 次添加和删除操作。

* 空间复杂度：$O(n)$。我们使用大小为 $n$ 的 $map$。
