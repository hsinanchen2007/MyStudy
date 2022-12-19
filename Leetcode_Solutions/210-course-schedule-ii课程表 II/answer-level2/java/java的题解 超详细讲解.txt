**【历史重难点题目】**
* [历史重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)

**【核心思想】**
* 不断删除入度为0的结点，直到无法删除为止

**【数据结构】**
* 数组，链表，队列



**【思路】**
* 将每个课看成一个结点，将各个结点的入度存在数组里
* 将各个结点之间的关系，以邻接链表的形式存储下来
* 不断删除入度为0的结点，直到无法删除为止
* 判断最后是否还剩下结点，若还剩下，则有环，不能完成所有课程的学习；若没有剩下，则无环，能完成所有课程的学习


**【代码】**
```java
public int[] findOrder(int numCourses, int[][] prerequisites) {
    int[] indegree=new int[numCourses];
    List[] list=new ArrayList[numCourses];
    int[] ans=new int[numCourses];

    for(int i=0;i<prerequisites.length;i++){
        indegree[prerequisites[i][0]]++;

        if(list[prerequisites[i][1]]==null) {
            List<Integer> temp=new ArrayList<>();
            temp.add(prerequisites[i][0]);
            list[prerequisites[i][1]]=temp;

        }
        else{
            List temp=list[prerequisites[i][1]];
            temp.add(prerequisites[i][0]);
            list[prerequisites[i][1]]=temp;
        }
    }
    int num=0;
    Queue<Integer> queue=new ArrayDeque<>();
    for(int i=0;i<numCourses;i++){
        if(indegree[i]==0)
            queue.add(i);

    }
    while(!queue.isEmpty()){
        int index=queue.poll();
        ans[num]=index;
        num++;
        while(list[index]!=null && !list[index].isEmpty()){
            if(--indegree[(int)list[index].get(0)]==0)
                queue.offer((int)list[index].get(0));
            list[index].remove(0);
        }

    }
    if(num!=numCourses)
        return new int[0];
    return ans;
}
```



**【关注微信公众号“算法岗从零到无穷”，更多算法知识点告诉你】**

![logo_gif.gif](https://pic.leetcode-cn.com/475e1ac3247b59c6f91026e0b5710d442f6bb2ca46a66933eff053264af44f92-logo_gif.gif)
