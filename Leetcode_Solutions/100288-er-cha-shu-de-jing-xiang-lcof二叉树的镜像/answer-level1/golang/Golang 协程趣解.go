### 以一个线程前序遍历二叉树，另一个线程创按照相反的顺序建新的树 <br><br><br>
利用golang中的channel阻塞线程，实现消费者生产者的效果<br><br>

```golang []
var res *TreeNode
var wg sync.WaitGroup
var c chan *TreeNode

func mirrorTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	wg = sync.WaitGroup{}
	c = make(chan *TreeNode)
	wg.Add(2)
	go traverse(root,true)
	go build(true)
	wg.Wait()
	return res
}

func traverse(root *TreeNode,first bool){ //遍历树的线程
	if first{
		defer wg.Done()
	}
	if root == nil {
		c <- root
		return
	}
	c <- &TreeNode{Val:root.Val}
	traverse(root.Left,false)
	traverse(root.Right,false)
}

func build(first bool) *TreeNode {  //新建树
	if first {
		defer wg.Done()
	}
	root := <-c
	if root == nil {
		return root
	}
	root.Right = build(false)
	root.Left = build(false)
	res = root
	return root
}
```
