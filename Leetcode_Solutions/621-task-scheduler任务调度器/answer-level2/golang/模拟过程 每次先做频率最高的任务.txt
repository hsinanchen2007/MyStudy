func leastInterval(a []byte, n int) int {
    if n==0 {   return len(a)}
	task1:=make([]int,26)
	for  i:=0;i<len(a);i++{
		task1[a[i]-'A']++
	}
	var task arr1
	task=task1 //存 任务次数 的map
	
	couont:=0
	all:=len(a)
	for  all>0					{//任务总数
        w:=n+1					 //一次最多能做n+1个
	for  i:=0;i<len(task);i++	{//去做任务
		
		if task[i]>0&&w>0		{
			task[i]--			//完成任务 次任务次数-1
			all--				//任务总数 -1
			w--					//剩余任务 -1
			
         if all==0{w=n+1-w }	//最后一轮 不一定做满了
	}
	}
	sort.Sort(task)			//每次先做出现次数最高的 做完了重新排列
    couont++		
    if all==0{return (couont-1)*(n+1)+w }//最后一轮之前 +上最后一轮的
 	}
     
	return 0

}

 type arr1 []int
 
 func (p arr1) Len() int           { return len(p) }
 func (p arr1) Less(i, j int) bool { return p[i] > p[j] }
 func (p arr1) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }