基本思想还是BFS。
总体思想是：先搞清上下级的层级关系，对每一级别做bfs更新全局时间：

步骤：
1.创建一个n维queue数组 vector<queue<int> >manQ。 其中数组下标i表示员工ID，manQ[i]队列中存放员工i的所有直属下属员工ID。

2.建立两个级别队列queue<vector<int> > levelQ, nextlevelQ。 队列元素vector<int> curP均包含两个元素：curP[0]为员工ID，curP[1]为从消息开始传播到当前员工通知完其下属所需要的总时长。levelQ表示当前级别需要完成通知工作的员工队列。nextQ表示下一级别需要完成通知工作的员工队列

3.将员工headID及其通知下属所需要的时间informTime[headID]压入队列levelQ。表示当前级别有一个员工headID需要完成通知工作。

4.初始化一个消息通知全局时间globalinfoTime = 0。

5.当levelQ或nextlevelQ不为空队列时循环
   i)读取levelQ的头结点p,即直到当前员工p[0]完成通知其下属所需要的信息传播总时间为p[1]
      
   ii)更新globalinfoTime = max(globalinfoTime, p[1])

   iii)当员工P[0]的直属下级员工ID队列manQ[p[0]]非空时：
      a)队列头结点表示p[0]的第一个下属员工ID：curID = manQ[p[0]].fornt()，将curP{curID， p[1] + informTime[]}压入nextlevalQ。
      b)弹出队列头结点manQ[p[0]].pop()。表示P[0]已经完成了对这名员工的通知。

   iv)如果当前级别员工队列levelQ为空，就将下一级别的员工队列nextlevelQ交换为levelQ，同时将ans更新为globalinfoTime
6.返回ans
代码：

```
int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
   int ans = 0;
   int manId = 0;
   vector<queue<int>>manQ(n, queue<int>());
   for(int i = 0; i < n; i++){
      manId = manager[i];
      if (manId == -1) continue;
      manQ[manId].push(i);
   }
   queue<vector<int> >levelQ,nextlevelQ;
   vector<int> curP(2,0);
   curP[0] = headID;
   curP[1] = informTime[headID];
   levelQ.push(curP);
   int globalinfoTime = 0;
 
   while(!levelQ.empty() || !nextlevelQ.empty()){
      auto p = levelQ.front();

      levelQ.pop();
      globalinfoTime = max(globalinfoTime, p[1]);
      while(!manQ[p[0]].empty()){
        curP[0] = manQ[p[0]].front();
        curP[1] = p[1] + informTime[curP[0]];
        nextlevelQ.push(curP);
        manQ[p[0]].pop();
      }
      if(levelQ.empty()){
        
        levelQ.swap(nextlevelQ);
        ans = globalinfoTime;
      }
   }
   return ans;
}
```
