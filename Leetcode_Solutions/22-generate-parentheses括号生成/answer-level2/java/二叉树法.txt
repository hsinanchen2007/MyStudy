思路：有效括号组数就是给定入栈序列求所有入栈出栈序列，比如入栈序列[1,2]可得[1122][1221]，
这些序列可以用二叉树来求得，以下是代码：
```
代码块
//树节点
class TreeNode{
		//值
		String val;
		//生成节点的步骤
		String ops;
		/*
		 * 空节点用val = "*"的节点代替
		 */
		TreeNode right;
		TreeNode left;
		//父节点
		TreeNode parent;
		//右侧叶节点
		TreeNode next;
		public TreeNode(String val) {
			this.val = val;
		}
		@Override
		public String toString() {
			return val;
		}
		
		public void print() {
			TreeNode temp = this;
			StringBuffer stringBuffer = new StringBuffer();
			while(temp != null) {
				stringBuffer.append(temp.val);
				stringBuffer.append("->");
				temp = temp.next;
			}
			System.out.println(stringBuffer);
		}
	}
//给定一个正整数，由叶节点组成的链表
public TreeNode buildTree(int n) {
		if (n == 0) {
			return new TreeNode("*");
		}else {
			//存放入栈序列
			List<Integer> arr = new ArrayList<>();
			for (int i = 1; i <= n; i++) {
				arr.add(i);
			}
			//工具栈
			Stack<Integer> stack = new Stack<>();
			//回溯工具栈
			Stack<Integer> stack2 = new Stack<>();
			int arrIndex = 0; 
			int temp = arr.get(arrIndex++);
			stack.push(temp);
			TreeNode root = new TreeNode(String.valueOf(temp)+",");
			TreeNode tempNode = root;
			TreeNode leaf = null;
			TreeNode head = null;
			root.ops = "s1,a0";
			while (true) {
				if (tempNode == root) {
					if (root.left != null && root.right != null) {
						break;
					}
				}
				TreeNode cNode = null;
				String pString = tempNode.val;
				if (!stack.empty()) {
					if (tempNode.left == null) {
						temp = stack.pop();
						stack2.push(temp);
						cNode = new TreeNode(pString + String.valueOf(temp)+ ",");
						cNode.ops = "s0,a1";
						tempNode.left = cNode;
						cNode.parent = tempNode;
						tempNode = cNode;
					}else if(tempNode.right == null){
						if (arrIndex == n) {
							cNode = new TreeNode("*");
							tempNode.right = cNode;
							String opString = tempNode.ops;
							tempNode = tempNode.parent;
							String[] strings = opString.split(",");
							String sop = strings[0];
							String aop = strings[1];
							switch (sop) {
							case "s0":
								temp = stack2.pop();
								stack.push(temp);
								break;
							case "s1":
								temp = stack.pop();
								if ("a0".equals(aop)) {
									arrIndex--;
								}
								break;
							default:
								break;
							}
						}else{
							temp = arr.get(arrIndex++);
							stack.push(temp);
							cNode = new TreeNode(pString + String.valueOf(temp)+ ",");
							cNode.ops = "s1,a0";
							tempNode.right = cNode;
							cNode.parent = tempNode;
							tempNode = cNode;
						}
					}else {
						String opString = tempNode.ops;
						tempNode = tempNode.parent;
						String[] strings = opString.split(",");
						String sop = strings[0];
						String aop = strings[1];
						switch (sop) {
						case "s0":
							temp = stack2.pop();
							stack.push(temp);
							break;
						case "s1":
							temp = stack.pop();
							if ("a0".equals(aop)) {
								arrIndex--;
							}
							break;
						default:
							break;
						}
					}
				}else {
					if (tempNode.right != null) {
						String opString = tempNode.ops;
						tempNode = tempNode.parent;
						String[] strings = opString.split(",");
						String sop = strings[0];
						String aop = strings[1];
						switch (sop) {
						case "s0":
							temp = stack2.pop();
							stack.push(temp);
							break;
						case "s1":
							temp = stack.pop();
							if ("a0".equals(aop)) {
								arrIndex--;
							}
							break;
						default:
							break;
						}
					}else {
						if (tempNode.left == null) {
							cNode = new TreeNode("*");
							tempNode.left = cNode;
							cNode.parent = tempNode;
						}
						if (arrIndex != n) {
							temp = arr.get(arrIndex++);
							stack.push(temp);
							cNode = new TreeNode(pString + String.valueOf(temp) + ",");
							cNode.ops = "s1,a0";
							tempNode.right = cNode;
							cNode.parent = tempNode;
							tempNode = cNode;
						}else {
							String opString = tempNode.ops;
							cNode = new TreeNode("*");
							tempNode.right = cNode;
							if (leaf != null) {
								leaf.next = tempNode;
								leaf = leaf.next;
							}else {
								head = tempNode;
								leaf = head;
							}
							tempNode = tempNode.parent;
							String[] strings = opString.split(",");
							String sop = strings[0];
							String aop = strings[1];
							switch (sop) {
							case "s0":
								temp = stack2.pop();
								stack.push(temp);
								break;
							case "s1":
								temp = stack.pop();
								if ("a0".equals(aop)) {
									arrIndex--;
								}
								break;
							default:
								break;
							}
						}
					}
				}
			}
			return head;
		}
	}
//最终方法
public List<String> generateParenthesis(int n) {
		if (n == 0) {
			return null;
		}else if (n == 1) {
			return Arrays.asList("()");
		}else {
			long start = System.currentTimeMillis();
			TreeNode head = buildTree(n);
			List<String> result = new ArrayList<>();
			while (head != null) {
				StringBuffer stringBuffer = new StringBuffer();
				String[] chars = head.val.split(",");
				Stack<String> stack = new Stack<>();
				stack.push(chars[0]);
				stringBuffer.append("(");
				for (int i = 1; i < chars.length; i++) {
					String c = chars[i];
					if (stack.isEmpty()) {
						stringBuffer.append("(");
						stack.push(c);
					}else {
						String temp = stack.pop();
						if (temp.equals(c)) {
							stringBuffer.append(")");
						}else {
							stack.push(temp);
							stack.push(c);
							stringBuffer.append("(");
						}
					}
				}
				result.add(stringBuffer.toString());
				head = head.next;
			}
			long end = System.currentTimeMillis();
			System.out.println("运行时间："+ (end - start) + "ms");
			return result;
		}
	}
```

