

```php []
  /**
     * @param Integer[] $nums
     * @return Integer[][]
     */

    function permuteUnique($nums) {
        sort($nums);
        $res=[];
        $out=[];
        $visitied=[];
        $this->helper($nums,0,$visitied,$out,$res);
        return $res;
    }
    
    function helper($nums,$index,&$visitied,&$out,&$res)
    {
        if($index==count($nums)){
            array_push($res,$out);
            return ;
        }
        for($j=0;$j<count($nums);$j++){
            if($visitied[$j]==1) continue;
            if($j>0 && $nums[$j]==$nums[$j-1] && $visitied[$j-1]==0) continue;
            $visitied[$j]=1;
            array_push($out,$nums[$j]);
            $this->helper($nums,$index+1,$visitied,$out,$res);
            array_pop($out);
             $visitied[$j]=0;
        }
    }
```
Github:[https://github.com/wuqinqiang/leetcode-php](https://github.com/wuqinqiang/leetcode-php)
