**【重点&&难点】**：如何保存并利用某一层的所有节点？
我们都知道，对树的一般层序遍历需要借助队列，是简单的。
但此题不是简单的层序遍历。
因此，我们可以不使用队列。
**思路**
1. 注意到java版本的返回类型为：List<List<Integer>>
    因此我们需要设置三个变量：
    1. List<TreeNode> pre = new ArrayList<>();作用：**记录上一层的所有节点**
    2. List<TreeNode> now;作用：**根据pre记录本层的所有节点**
    3. List<Integer> finalList = new ArrayList<>();作用：**根据now创造出对应值的列表**
    思考：为什么需要三个而不是两个？
        注意看本函数要返回的返回值类型。内层的List的泛型参数时Integer的
        而我们在保存pre、now时，只能泛型时TreeNode的。
        因此，我们额外再申请一个泛型为Integer的列表
2. 处理第一层根节点
    首先加入根节点到pre中，finalList直接加入此节点的值。然后再加入到最终结果res中
3. 处理其它层
    while()循环{
        1. 循环开始处，初始化/清空now与finalList
        2. 遍历pre。pre存储了上一层的【所有】节点
        3. 将pre的所有子节点加入到now中，同时将节点的值加入到finalList中
        4. **循环更新条件：**
        5. 若now.size()==0.说明到树的最后一层的下一层了。break;
        6. 否则，让**pre=now**,即：在进入下一轮循环时，当前的now层则即为下一轮的pre层
    }

```java
    public List<List<Integer>> levelOrder(TreeNode root) {
    	List<List<Integer>> res = new ArrayList<>();
    	if (root == null) return res;
    	TreeNode temp = null;
    	List<TreeNode> pre = new ArrayList<>();//记录上一层的所有节点
    	List<TreeNode> now;//根据pre记录本层的所有节点
    	List<Integer> finalList = new ArrayList<>();//根据now创造出对应值的列表
    	//【回答疑问】:为啥要申请三个而不是两个
    	//注意看本函数要返回的返回值类型。内层的List的泛型参数时Integer的
    	//而我们在保存pre、now时，只能泛型时TreeNode的。
    	//因此，我们额外再申请一个泛型为Integer的列表
    	
    	pre.add(root);//首先加入根节点
    	finalList.add(root.val);//取出pre存储的节点的值加入到fi列表中
    	res.add(finalList);//加入到最终结果中
    	
    	while(true) {
    		now = new ArrayList<>();//循环开始时，将now置空
    		//now是用来存放下一层的所有子节点的
    		finalList = new ArrayList<>();//这个也置空
    		
			for(int i=0;i<pre.size();i++) {//遍历pre。pre存储了上一层的【所有】节点
				temp=pre.get(i);//获取上层的某个节点
				if(temp.left!=null) {//添加左子节点
					now.add(temp.left);
					finalList.add(temp.left.val);//同时立马可以加入到finalList中
				}
				if(temp.right!=null) {//添加右子节点
					now.add(temp.right);
					finalList.add(temp.right.val);
				}
			}
			if(finalList.size()!=0) res.add(finalList);
			else break;//当finalList为空时，说明什么？说明pre为最后一层了
					   //而now层为空。就是毕竟遍历完所有树的节点了的意思
			
			pre = now;//在进入下一轮循环时，当前的now层则即为下一轮的pre层了
    	}
    	return res;
    }
```

