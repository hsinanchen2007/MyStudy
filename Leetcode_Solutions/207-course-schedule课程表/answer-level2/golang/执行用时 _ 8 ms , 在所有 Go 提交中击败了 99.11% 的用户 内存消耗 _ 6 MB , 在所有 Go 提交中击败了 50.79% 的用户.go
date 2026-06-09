这里必须要吐槽一下，题意非常扯，这题提示比题意有用！！！。

总结：这题的意思就是找有没有回路，不要听题意在那里扯皮，最好的证明就是我最终实现的代码通过了，但都没有使用numsCourse这个变量了，这题的输出并不关心numsCourse！这题的输出并不关心numsCourse！这题的输出并不关心numsCourse！说三遍！！！

吐槽完了，放代码：
```
func canFinish(numCourses int, prerequisites [][]int) bool {
	if numCourses==0||len(prerequisites)==0 {
		return true
	}
	//出入度，两个map，一个用来存后继结点，一个用来存点的入度
	inDeg:=make(map[int]int)
	neNodes:=make(map[int][]int)
	var stack []int
	for i:=0;i<len(prerequisites);i++{
		inDeg[prerequisites[i][0]]++
		if _,ok:=inDeg[prerequisites[i][1]]; !ok {
			inDeg[prerequisites[i][1]]=0
		}
		neNodes[prerequisites[i][1]]=append(neNodes[prerequisites[i][1]], prerequisites[i][0])
	}

	for k,v:=range inDeg {
		if v==0 {
			stack= append(stack, k)
		}
	}

	for len(stack)!=0{
		for _,v:=range neNodes[stack[0]]{
			if inDeg[v]==1 {
				stack= append(stack, v)
			}
			inDeg[v]--
		}
		delete(inDeg,stack[0])
		stack=stack[1:]
	}

	if len(inDeg)==0{
		return true
	}

	//if res==numCourses {
	//	return true
	//}
	return false
}
```
你们可以看到，这题里我最后都没有用numCourses，直接判断有没有回路就完了，如果我真的去判断了numCourses，那么按照我的思路，这里反而会写错