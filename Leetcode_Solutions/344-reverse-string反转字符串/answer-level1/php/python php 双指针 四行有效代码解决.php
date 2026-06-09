1:用双指针,同时从头部和尾部开始进行`交换2个指针的值`
2:并自增自减的向中间遍历
3:直到触发`基准条件`:2个指针开始中间重合 返回即可
代码如下:

```python []
def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        length = len(s)
        if length < 2:
            return s
        j = length - 1
        i = 0
        while i < j:
            # handle
            s[i], s[j] = s[j], s[i]
            i +=1
            j -=1
        return s
```
```php []
function reverseString(&$s) {
        $length = count($s);
        if($length < 2){
            return $s;
        }
        $i = 0;
        $j = $length - 1;
        while ($i<$j){
            $temp = $s[$i];
            $s[$i] = $s[$j];
            $s[$j] = $temp;
            $i++;
            $j--;  
        }
        return $s;
            
    }
```
