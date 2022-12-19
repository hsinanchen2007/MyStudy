
同时易懂就是剥洋葱！
最终目的是找到一个节点，这个节点 距离叶子界面最远，那么**我们每次减叶子，叶子剪完了，留下来的就是 树根了**。

![image.png](https://pic.leetcode-cn.com/c732de71df54cc7da61b5139feef994d3b24ae66a29232db28cd15ad95046623-image.png)
### 邻接链表
```
func findMinHeightTrees(_ n: Int, _ edges: [[Int]]) -> [Int] {
	if n == 1{
		return [0]
	}else if n == 2{
		return [0,1]
	}else if n==0{
		return [Int]()
	}

	var arr = Array(repeating: Set<Int>(), count: n)
	var duCount = Array(repeating: 0, count: n)
	//构造邻接链表
	for i in 0..<edges.count {
		let i0 = edges[i][0],i1 = edges[i][1]
		duCount[i0] += 1
		duCount[i1] += 1
		arr[i0].insert(i1)
		arr[i1].insert(i0)
	}
	//记录节点 度=1的的节点
	var delArr = [Int]()
	var nextDelArr = delArr
	
	for i in 0..<duCount.count{
		if duCount[i] == 1 {
			delArr.append(i)
		}
	}
	while true {
		nextDelArr.removeAll()
		for i in delArr{
			guard let d = arr[i].popFirst() else {
				continue
			}
			arr[d].remove(i)
			if arr[d].count == 1{
				nextDelArr.append(d)
			}
		}
		if nextDelArr.count == 0 {
			return delArr
		}else if nextDelArr.count == 1{
			return nextDelArr
		}else{
			delArr = nextDelArr
		}
	}
	
	return [0]
}
```
### 邻接矩阵
```
func findMinHeightTrees(_ n: Int, _ edges: [[Int]]) -> [Int] {
   if n < 1 {
	   return [Int]()
   }else if n == 1{
	   return [0]
   }else if n == 2{
	   return [0,1]
   }
   
   var duCount = Array(repeating: 0, count: n)
   var v = Array(repeating: Array(repeating: 0, count: n), count: n)
   
   //统计度 《出度和入度》
   for i in 0..<edges.count {
	   let i0 = edges[i][0]
	   let i1 = edges[i][1]
	   duCount[i0] += 1
	   duCount[i1] += 1
	   
	   v[i0][i1] = 1
	   v[i1][i0] = 1//邻接矩阵 表示无向图
   }

	var values = Dictionary<Int,Int>()
	var needDelPoint = [Int]()
	for i in 0..<duCount.count {
		if duCount[i] == 1  {
			values[i] = 1//需要处理的节点
			needDelPoint.append(i)
		}
	}
	while true {
		var nextNeedDeleteP = [Int]()//第二次处理的 节点集合
		for i in 0..<needDelPoint.count{
			let g = needDelPoint[i]
			for k in 0..<n {//去节点
				if v[g][k] == 1 {
					v[g][k] = 0 //剪枝
					v[k][g] = 0
					
					duCount[g] -= 1
					duCount[k] -= 1
					if duCount[k] == 1{
						nextNeedDeleteP.append(k)
					}
					break
				}
			}
		}
		if nextNeedDeleteP.count < 2 {
			if nextNeedDeleteP.count == 0 {
				return needDelPoint;
			}
			return nextNeedDeleteP;
		}else{
			needDelPoint = nextNeedDeleteP
		}
		
	}
}
```
![sf (1).png](https://pic.leetcode-cn.com/4d3413897b51b7112490542cc07f044ef938ec84adfa6a89b24b4dc06d83b9a5-sf%20\(1\).png)

**[跟多代码题解 在github 欢迎start！！！](https://github.com/ifgyong/SF#310-%E6%9C%80%E5%B0%8F%E9%AB%98%E5%BA%A6%E6%A0%91)
[跟多代码题解 在github 欢迎start！！！](https://github.com/ifgyong/SF#310-%E6%9C%80%E5%B0%8F%E9%AB%98%E5%BA%A6%E6%A0%91)
[跟多代码题解 在github 欢迎start！！！](https://github.com/ifgyong/SF#310-%E6%9C%80%E5%B0%8F%E9%AB%98%E5%BA%A6%E6%A0%91)**