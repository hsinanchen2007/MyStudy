1、先序遍历BST   
结果集的第一个元素是root，从左往右，第一个比root大的元素是root.right；   
那么，root和root.right之间就是左子树的节点个数，root.right到最后一个元素就是右子树节点个数；  


2、后续遍历BST    
结果集的最后一个元素是root，从右往左，第一个比root小的元素是root.left；    
那么，root.left和root之间就是元素的右子树的节点数，0到root.left就是左子树的节点数；  