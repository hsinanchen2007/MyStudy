根据题目字面意思递归即可
```
function integerReplacement($n) {
    if($n==1) return 0;
    if($n%2==0){
        return 1+$this->integerReplacement($n/2);
    }else{
        return 1+min($this->integerReplacement($n+1),$this->integerReplacement($n-1));
    }
}
```
