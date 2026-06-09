二叉搜索树的第K小的元素，就是二叉树中序遍历的第k个节点。
总体思想是moris 中序遍历整颗二叉树，使用一个变量index保存当前节点是第几小的元素，当index==k时，找到了第k小的元素返回即可。整个算法空间复杂度O(1),时间复杂度O(k).
关于Moris遍历 ，详情见https://blog.csdn.net/e01528/article/details/86666386
执行用时 :
1 ms, 在所有 Java 提交中击败了
99.62%的用户
内存消耗 :
40.3 MB, 在所有 Java 提交中击败了33.17%的用户
```

public int findKMinElement(TreeNode root,int k){
    int index =0;
    TreeNode cur =root;
    int ans =0;
    while(cur!=null){
        if(cur.left==null){
            index++;
            if(index==k){
              ans =cur.val;
              break;
            }
            cur =cur.right;
        }else{
            TreeNode temp =cur.left;
            while(temp.right!=null&&temp.right!=cur){
                temp =temp.right;
            }
            if(temp.right==null){
                temp.right =cur;
                cur =cur.left;
            }
            if(temp.right==cur){
                index++;
                if(index==k){
                    ans=cur.val;
                    break;
                }
                temp.right =null;
                cur = cur.right;
            }

        }   

    }
    return ans; 
}
```
