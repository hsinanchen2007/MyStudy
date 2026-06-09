题目条件：
1，传入数组本身有序
2，不要使用额外数组空间
3，必需原地修改输入数组，**不需要考虑数组中超出新长度后面的元素**
4，空间复杂度O(1)
```
function removeDuplicates(&$nums) {
    if(count($nums)<=1) return count($nums);
    $count = 1;
    for($i=1;$i<count($nums);$i++){
        if($nums[$i]==$nums[$i-1]){
            continue;
        }else{
            $nums[$count] = $nums[$i];
            $count++;
        }
    }
    return $count;
}
```
