![微信截图_20191031182724.png](https://pic.leetcode-cn.com/b7ddf312c09b7f3bb32b0dedf8fbad168d6d7439b27c7d2bd6f8fbddd8c6e2a4-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191031182724.png)

```
class Solution {
    
    private $op = []; // 运算符数组
    private $nums = []; // 数字数组

    /**
     * @param String $input
     * @return Integer[]
     */
    function diffWaysToCompute($input) {
        for($i=0;$i<strlen($input);$i++)
            if($input[$i]=='+' || $input[$i]=='-' || $input[$i]=='*')
                $this->op[] = $input[$i];
        $this->nums = preg_split("/[\+\-\*]/", $input);
        return $this->helper(0, count($this->nums)-1);
    }
    
    function helper($start, $end){
        $res = [];
        if($start == $end){
            $res[] = (int) $this->nums[$start];
            return $res;
        }
        for($i=$start;$i<$end;$i++){
            foreach($this->helper($start, $i) as $left){
                foreach($this->helper($i+1, $end) as $right){
                    if($this->op[$i]=='+'){
                        $res[] = $left + $right;
                    }else if($this->op[$i]=='-'){
                        $res[] = $left - $right;
                    }else if($this->op[$i]=='*'){
                        $res[] = $left * $right;
                    }
                }
            }
        }
        return $res;
    }
}
```
