参考这个视频：https://www.bilibili.com/video/av9830088?from=search&seid=5967589139650667616


```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function permute($nums) {
        $this->perm($nums,0,count($nums)-1);
      
        return $this->result;
    }


function swap(&$arr,$p,$q){
    $temp=$arr[$p];
    $arr[$p]=$arr[$q];
    $arr[$q]=$temp;
}
function perm($arr,$p,$q){
    if($p==$q){
        $this->result[]=$arr;
        return;
    }
    for($i=$p;$i<=$q;$i++){
        $this->swap($arr,$p,$i);//交换 ，第一回，数组0号元素当首位；第二回p=1，第一号元素当首位
        $this->perm($arr,$p+1,$q);//后面的1号元素 到 n-1个元素，继续排列组合；后面的2号元素 到最后一个元素，继续排列组合
        $this->swap($arr,$p,$i);//复原数组
    }
}

}
```
