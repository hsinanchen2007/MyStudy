**【历史重难点题目】**
* [历史重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)

**【核心思想】**
* 不断删除【入度，出度和】为1的结点，直到剩下两个或者一个结点为止

**【数据结构】**
* 数组，链表，队列



**【思路】**
* 将各个结点的【入度，出度和】存在数组里
* 将各个结点之间的关系，以邻接链表的形式存储下来（注意这道题是无向图，所以要对称着存，这里不理解没关系，看下面的代码就理解了）
* 不断删除【入度，出度和】为1的结点，直到剩下两个或者一个结点为止



**【代码】**
```java
public List<Integer> findMinHeightTrees(int n, int[][] edges) {
    if (n == 1) {
        List<Integer> ans = new ArrayList<>();
        ans.add(0);
        return ans;
    }
    if(n==0)
        return new ArrayList<>();

    int[] degree=new int[n];//存放【入度，出度和】
    List[] list=new ArrayList[n];//邻接链表
    List<Integer> ans=new ArrayList<>();

	//下面的for循环生成【入度出度表】和【邻接链表】
   for(int i=0;i<edges.length;i++){
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
        if(list[edges[i][0]]==null) {
            List<Integer> temp=new ArrayList<>();
            temp.add(edges[i][1]);
            list[edges[i][0]]=temp;
        }
        else{
            list[edges[i][0]].add(edges[i][1]);
        }

        if(list[edges[i][1]]==null) {
            List<Integer> temp=new ArrayList<>();
            temp.add(edges[i][0]);
            list[edges[i][1]]=temp;
        }
        else{
            list[edges[i][1]].add(edges[i][0]);
        }
    }

    Queue<Integer> queue=new ArrayDeque<>();
    int num=0;
    
	//将【入度，出度和】为1的结点放进队列
    for(int i=0;i<n;i++){
        if(degree[i]==1)
            queue.add(i);
    }
    
	//处理结点
    while(!queue.isEmpty()){
        int len=queue.size();
        //判断跳出条件
        if(n-num==2 || n-num==1){
            ans.add(queue.poll());
            continue;
        }

        for(int i=0;i<len;i++){
            int index=queue.poll();
            num++;
            while(list[index]!=null && !list[index].isEmpty()){
                if(--degree[(int)list[index].get(0)]==1)
                    queue.add((int)list[index].get(0));   
                list[index].remove(0);    
            }        
        }
    }
    return ans;
}
```

** 【关注微信公众号“算法岗从零到无穷”，更多算法知识点告诉你】
![logo_gif.gif](https://pic.leetcode-cn.com/7c4b37a463b76397b44f6cf00e61743731f3e0aecb727ef6b819f07766f4a6d0-logo_gif.gif)

