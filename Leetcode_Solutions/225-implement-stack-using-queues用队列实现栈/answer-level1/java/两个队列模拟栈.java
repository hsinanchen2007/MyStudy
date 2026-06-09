### 解题思路

Queue<Integer> inQueue=new LinkedList<Integer>();//用来入栈（指向前面元素的）
Queue<Integer> outQueue=new LinkedList<Integer>();//用来出栈（指向最后一个元素的）

/*push 入栈 1,2,3,4,5*/
inQueue={1,2,3,4,5}
outQueue={}
/*push 入栈 1,2,3,4,5*/

/*pop 出栈*/
inQueue={5}//除了最后一个，全部出队，加入outQueue
outQueue={1,2,3,4}

//交换两个队列，这样outQueue就可以出栈了
inQueue{1,2,3,4}
outQueue{5}

//5出栈
inQueue{1,2,3,4}
outQueue{}
/*pop 出栈*/