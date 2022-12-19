
![倒层输出树.png](https://pic.leetcode-cn.com/caf525783204da7086f9943c27e393ed4723dfba5e559814ecea40c76b64af9d-%E5%80%92%E5%B1%82%E8%BE%93%E5%87%BA%E6%A0%91.png)


借鉴了上一题求最大深度一位朋友的 @西瓜皮 写的
![image.png](https://pic.leetcode-cn.com/6c86220baa2104368f99231f2693c2750763e6c2e5619be15bb4007912f8e4ad-image.png)


用map做了缓存,遍历到当前元素是哪个层的就把值存到map中，最后根据最大层，倒着拿出来即可。

```java []

class Solution {

     int deep = 0;
     int maxDeep;

     //层--[值1，值2]
     HashMap<Integer, List<Integer>> map = new HashMap<Integer, List<Integer>>();

    public  List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (root == null) {
            return res;
        }

        fun(root);//遍历这个树

        //从最大层取到第一层
        for (int i = maxDeep; i > 0; i--) {
            res.add(map.get(i));
        }
        return res;
    }

    private  void fun(TreeNode root) {

        if (root != null) {
            deep++;
            maxDeep = maxDeep > deep ? maxDeep : deep;
            List<Integer> list = map.get(deep);
            if (list == null) {
                list = new ArrayList<>();
            }
            list.add(root.val);
            map.put(deep, list);
            fun(root.left);
            fun(root.right);
            deep--;
        }

    }
}
```

