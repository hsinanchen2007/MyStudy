        public int RangeSumBST(TreeNode root, int L, int R)
        {
            //输入：root = [10,5,15,3,7,null,18], L = 7, R = 15
            //输出：32
            if (root == null)//判断二叉搜索树是否为空，为空输出0
            {
                return 0;
            }
            if (root.val < L)//判断值是否小于L
            {
                return RangeSumBST(root.right, L, R);//如果小于L，取右节点值进行递归
            }
            if (root.val > R)//判断值是否大于R
            {
                return RangeSumBST(root.left, L, R);//如果大于R，取左节点进行递归
            }
            int res = 0;//储存总数
            if (root.val >= L && root.val <= R)
            {
                int left = RangeSumBST(root.left, L, R);//遍历左节点
                res += root.val;
                int right = RangeSumBST(root.right, L, R);//遍历右节点
                res += (left + right);
            }
            return res;
        }

首先将节点左右节点分别遍历
左节点值与范围值LR进行对比
如果范围值L大于节点值则向左节点遍历
如果范围值R小于节点值则向右节点遍历
如果符合条件重新进行左右遍历
（请大家指出问题，或述说自己的思路，共同进步）