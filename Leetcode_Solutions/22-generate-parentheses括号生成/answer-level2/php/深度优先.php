### 解题思路
根据
https://leetcode-cn.com/problems/generate-parentheses/solution/hui-su-suan-fa-by-liweiwei1419/
提供的思路，因为有n对，所以就会有n个'('和n个')'，每次去使用这些括号来递归组成一个有效括号字符串

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return String[]
     */
    public $all = [];
    function generateParenthesis($n) {
        if ($n == 0) {
        	return $n;
        }
        $this->dfs('',$n,$n);
        return $this->all;
    }

    public function dfs($str,$left,$right)
    {
    	//都为0说明走到了终点
    	if ($left == 0 && $right == 0) {
    		print_r($str);
    		$this->all[] = $str;
    	}

    	//剩余左边大于右边的话
    	if ($left > $right) {
    		return ;
    	}
    	if ($left > 0) {
    		//左分支
    		$this->dfs($str.'(' , $left - 1, $right);
    	}
    	if ($right > 0 && $right > $left) {
    		//右分支
    		$this->dfs($str.')' , $left , $right - 1);
    	}

    }
}
```