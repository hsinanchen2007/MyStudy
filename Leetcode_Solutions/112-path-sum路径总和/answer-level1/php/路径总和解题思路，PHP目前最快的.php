根据题意，计算根据点结点到叶子结点的和，所以使用二叉树的preorder遍历。
注意：遍历之后的路径，向上返回时删除。

function hasPathSum($root, $sum) {
        if($root == null){
            return false;
        }

        $path = [];
        $path_sum = 0;
        $is_find = false;
        $this->pathSum($root,$path_sum,$path, $sum, $is_find);
        return $is_find;


    }

function pathSum($root, &$path_sum, &$path, $sum, &$is_find){

        $path_sum = $path_sum + $root->val;
        $path[] = $root->val;
        if($root->left != null){

            $this->pathSum($root->left, $path_sum, $path, $sum, $is_find);
            $path_sum = $path_sum - $root->left->val;
            array_pop($path);
        }

        if($root->right != null){

            $this->pathSum($root->right, $path_sum, $path, $sum,$is_find);
            $path_sum = $path_sum - $root->right->val;
            array_pop($path);
        }

        if($root->left == null and $root->right == null){
            if($path_sum == $sum) {
                $is_find = true;
            }
            //print_r($path);
            return ;
        }
    }
