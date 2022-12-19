```java
	/**
	 * 【显然】本题是个递归的判断过程
	 * 	PS:本题与剑指offer的【第28题镜像对称二叉树】的写法一样
	 * 		那就是，【只判断当前两个参数自身，而不是去判断两个参数的子节点】
	 * 
	 * @param A
	 * @param B
	 * @return
	 */
    public static boolean isSubStructure(TreeNode A, TreeNode B) {
    	if(B==null) return false;//空树不是任何树的子结构
    	return helper(A, B, A.val==B.val);//初始情况，将A是否和B点匹配作为参数传入
    }
    /**
     * 	方法的作用：判断【以当前节点nodeB为根节点的子树B】是否匹配【以当前节点nodeA为根节点的子树A】
     * 	【难点】在于何时判断【是已经开始匹配了至少一个节点】还是【处于正在寻找第一个匹配点的过程中】
	 * 	注：关于【处于正在寻找第一个匹配点的过程中】，有点需要额外说明
	 * 	1.可能是一次还未开始配对过
	 * 	2.可能之前已经配对了部分，但是未能成功完全匹配-->我们称此情况为never Match
	 * 		因此继续重新寻找第一个匹配点-->我们称此情况为ever Match
	 * 因此，【最关键点】即为：能否想到在递归函数中添加一个boolean flag变量
	 * 【作用】
	 * 	flag为true时，说明已经至少匹配到一个节点了
	 * 	flag为false时，说明当前没有匹配到任何一个节点
	 * 		（同样，也有可能在这之前就配对到B的部分，但是未能完全匹配，
	 * 		从而使得flag从true变为false）
	 * 【逻辑】
	 * 假设nodeA,nodeB为对应树中的某个节点。
	 * helper方法的作用：
	 * 	判断【以当前节点nodeB为根节点的子树B】是否匹配【以当前节点nodeA为根节点的子树A】
	 * 1.flag==true
	 * 	此时说明正在判断原B的其余结构中的某个节点nodeB过程中
	 * 	(1)如果nodeA==null而nodeB!=null，则nodeB子树不是nodeA子树的子结构
	 * 	(2)如果nodeA==null而nodeB==null 则return true;
	 * 	(3)如果nodeA!=null而nodeB==null 则return true;
	 * 	(4)如果nodeA!=null而nodeB!=null 则
	 * 		(i) 如果nodeA.val==B.val
	 * 			则可以继续向下判断nodeA的左右子节点和nodeB的左右【子树】是否匹配
	 * 		(ii)否则，return false;
	 * 2.flag==false
	 * 此时说明正在寻找合适的第一个匹配点
	 * 如果nodeB为null则按照题目说明，不匹配
	 * 否则，就是nodeB!=null
	 * 	此时再继续细分情况：
	 * 	1.nodeA==null 说明A一直在找第一个匹配点，但直到为空都没找到，则不匹配
	 * 	2.nodeA!=null 
	 * 		(1)nodeA.val==nodeB.val 则说明开始匹配了。往下继续判断左右子树是否匹配
	 * 			当然，进入递归判断子树时，别忘将flag为true的参数传入
	 * 		(2)nodeA.val!=nodeB.val 则继续往nodeA的【左右子树】寻找和【nodeB自身节点】匹配的点。
     * @param nodeA
     * @param nodeB
     * @param flag
     * @return
     */
    public static boolean helper(TreeNode nodeA, TreeNode nodeB, boolean flag) {
    	if(flag) {//处于已经配对中
    		if(nodeA==null&&nodeB!=null) return false;
    		//说明nodeB树不为空，nodeA为空，则不匹配
    		else if(nodeA!=null&&nodeB!=null) {
    			if(nodeA.val==nodeB.val) {
    				//当前nodeB子树的根和当前子树nodeA的根匹配
    				//则继续往下判断其左右子树是否匹配
    				return helper(nodeA.left, nodeB.left, true)
							&&helper(nodeA.right,nodeB.right,true);
    					//【注意】
    					//此处是且&&的关系。必须左右子树同时匹配，当前两子树才匹配
    			}else return false;//两子树的根节点都不相同，则肯定不匹配
    		}else return true;//对应nodeA、nodeB均为空树，则匹配
    			
    	}else {//还未寻找到配对的起点
    		if(nodeB==null) return false;//空树不是任何树的子结构
    		else {
    			if(nodeA==null) return false;
    			//说明A一直在找第一个匹配点，但直到为空都没找到，则不匹配
    			else {
    				if(nodeA.val==nodeB.val) {
    					//则说明开始匹配了。往下继续判断左右子树是否匹配
    					//当然，进入递归判断子树时，别忘将flag为true的参数传入
    					//【注意】是且的关系
    					return helper(nodeA.left, nodeB.left, true)
    							&&helper(nodeA.right,nodeB.right,true);
    				}else {
    					//说明此时还是不匹配，则继续往A的左右子树寻找。 
    					//【注意】此时false依然为false,且左右子树的关系是或	||的关系
    					//当然，此处特别应该知道的事，当在左子树发生匹配时，就不会再进入右子树判断了
    					//这是 || 的特性。节省了效率
    					//PS：千万别一激动写成注释掉的那种形式
    					//因为是往nodeA的【左右子树】寻找和【nodeB自身节点】匹配的点。
						return helper(nodeA.left, nodeB/* .left */, false)
								|| helper(nodeA.right, nodeB/* .right */,false);
    				}
				}
			}
    	}
    }
```
