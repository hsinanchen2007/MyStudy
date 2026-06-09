[[0,3],[1,3],[2,3],[4,3],[5,4]] 根据这组数，可以得出以下图

![image.png](https://pic.leetcode-cn.com/f0c4f7ad33ac56d79acd881bc140e95fcc91dac50518cdfe7043a169f248a8ac-image.png)

1、找出每个节点的度数
定义degree[n]的数组，用来存储每个节点的度数，n为节点个数
degree[0]=1，degree[1]=1,degree[2]=1,degree[3]=4,degree[4]=2,degree[5]=1

2、找出每个节点连接的节点
0:{3},1:{3}，2:{3}, 3:{0,1,2}，4:{3,5} ，5:{4}

3、度数为1的节点入队列
(0,1,2,5)

4、循环砍掉加粗部分，砍到不能再砍

![image.png](https://pic.leetcode-cn.com/9fa1ecddab1e7fbb383b8f277ca9ea9cbfa2328ee1576a07eef48720bec38765-image.png)

***degree[0]=1***，degree[1]=1,degree[2]=1,degree[3]=3,degree[4]=2,degree[5]=1

![image.png](https://pic.leetcode-cn.com/731fdaa6a2703111c74b1d6a6c941933bf421a3b16484f5b28d681cda74e04c2-image.png)

***degree[0]=1，degree[1]=1***,degree[2]=1,degree[3]=2,degree[4]=2,degree[5]=1

![image.png](https://pic.leetcode-cn.com/c5a381c6f1b546da30917a4543a9b3b92640bca3826d195b63707b1859e59605-image.png)


***degree[0]=1，degree[1]=1,degree[2]=1***,degree[3]=1,degree[4]=2,degree[5]=1

![image.png](https://pic.leetcode-cn.com/a71dcaf51225e15d1f6276afb26652c4efa9ab56956dccd6d4e2f993939edd3e-image.png)

**degree[0]=1，degree[1]=1,degree[2]=1**,degree[3]=1,degree[4]=1,**degree[5]=1**

结果是，队列为空之后，剩下的节点就是期望的结果，以该结果为根节点得到的树就是最小高度树
```
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> ans = new ArrayList<>();
//      1.条件判断（边界判断，其他要求的判断）
        if (n == 1){
            ans.add(0);
            return ans;
        }
        int[] degree = new int[n];//每个节点的度数
        List<List<Integer>> map = new ArrayList<>();//每个节点
        for (int i=0;i<n;i++) {
            map.add(new ArrayList<>());
        }
        for (int[] edge:edges){
            degree[edge[0]]++;//计算edge[0]节点的度数
            degree[edge[1]]++;//计算edge[1]节点的度数
            map.get(edge[0]).add(edge[1]);//跟edge[0]相邻的节点
            map.get(edge[1]).add(edge[0]);//跟edge[1]相邻的节点
        }
//      2.创建队列
        Queue<Integer> queue = new LinkedList<>();

//      3.在队列中加入第一个满足条件的元素
        for (int i = 0;i < n;i++){
            if (degree[i] == 1){//度数为1，说明是叶子结点,入队列
                queue.offer(i);
            }
        }
//      4.while(队列不为空) {
//            取出队列头部元素
//            操作
//            根据头部元素，往队列中再次加入满足条件的元素
//        }
        while (!queue.isEmpty()){
            ans=new ArrayList<>();
            int size = queue.size();
            for (int i=0;i<size;i++){
                int cur = queue.poll();
                ans.add(cur);
                List<Integer> nexts = map.get(cur);
                for (Integer next:nexts){
                    degree[next]--;//删除叶子节点后，跟其相邻的节点的度数要减少
                    if (degree[next] == 1){
                        queue.offer(next);
                    }
                }
            }
        }

        return  ans;
    }
```

		
