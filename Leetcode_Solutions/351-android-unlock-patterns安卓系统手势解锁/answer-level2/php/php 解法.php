![微信截图_20191112154007.png](https://pic.leetcode-cn.com/d73805a45cfd2b9884a433a6799630db9d64c192e354089fe46547eb990ccd74-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191112154007.png)

由于镜像对称，分别从1，3，7，9开始的手势方案数是相等的，分别从2，4，6，8开始的也是相等的。
所以原先1~9for循环的方案600多ms优化到200多ms。
```
class Solution {

    /**
     * @param Integer $m
     * @param Integer $n
     * @return Integer
     */
    function numberOfPatterns($m, $n) {
        $this->path[1][9]=$this->path[9][1]=5;
        $this->path[2][8]=$this->path[8][2]=5;
        $this->path[3][7]=$this->path[7][3]=5;
        $this->path[4][6]=$this->path[6][4]=5;
        $this->path[1][3]=$this->path[3][1]=2;
        $this->path[1][7]=$this->path[7][1]=4;
        $this->path[3][9]=$this->path[9][3]=6;
        $this->path[7][9]=$this->path[9][7]=8;
        $ans = 0;
        $visited = array_fill(0,10,false);
        for($len=$m;$len<=$n;$len++){
            $ans += $this->dfs(1,$len,$visited)*4;
            $ans += $this->dfs(2,$len,$visited)*4;
            $ans += $this->dfs(5,$len,$visited);
        }
        return $ans;
    }
    
    private $path = [];
    
    function dfs($num, $len, $visited){
        if($len == 1) return 1;
		$count = 0;
        $visited[$num] = true;
        for($i=1;$i<=9;$i++){
            if($this->isValidPath($num, $i, $visited) && !$visited[$i]){
                $count += $this->dfs($i, $len-1, $visited);
            }
        }
        $visited[$num] = false;
        return $count;
    }
    
    function isValidPath($num1, $num2, $visited){
        return isset($this->path[$num1][$num2])?$visited[$this->path[$num1][$num2]]:true;
    }
}
```
