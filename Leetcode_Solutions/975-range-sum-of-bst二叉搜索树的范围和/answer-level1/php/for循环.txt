        执行用时 :100 ms, 在所有 php 提交中击败了97.06%的用户
        内存消耗 :22.4 MB, 在所有 php 提交中击败了21.05%的用户

      `  function rangeSumBST($root, $left, $right) {
            $sum = 0;
            $current = [$root];
            
            for ($i = 0; $i < count($current); $i++) {
                $node = $current[$i];
                if ($node) {
                    if ( $left <= $node->val && $node->val <= $right) {
                        $sum += $node->val;
                    }
                    if ($left < $node->val) {
                        $current[] = $node->left;
                    }
                    if ($node->val < $right) {
                        $current[] = $node->right;
                    }
                }
            }
            
            return $sum;
        }`