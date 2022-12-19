

昨天晚上误打误撞提交通过了，晚上睡觉总觉得不对，辗转反侧一夜，果然有逻辑不对；


重新看题解后，找到正确的检查方法；


/* 先判断本次节点的值是否相同，如果不同flag为false，flag&&dfs(t1,t2) 决定dfs(t1, t2)不启动 */

/* 搜索到匹配的节点，就保障他的右边和左边绝对一致，否则dfs会返回false，表示不匹配 */    

/* dfs(t1, t2)不匹配则先往t1左边搜索和t2相同的节点，搜索到（即flag为true），启动dfs */    

/* dfs(t1, t2)不匹配 + checkSubTree(t1->left, t2)也没找到，则启动右边搜索和t2相同的节点checkSubTree(t1->right, t2) */

return  (flag && dfs(t1, t2) || checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2)); 

![image.png](https://pic.leetcode-cn.com/d47f6666f17732b989c187002e4a1d06e89857b84d0e1e771724eaf720866e34-image.png)
