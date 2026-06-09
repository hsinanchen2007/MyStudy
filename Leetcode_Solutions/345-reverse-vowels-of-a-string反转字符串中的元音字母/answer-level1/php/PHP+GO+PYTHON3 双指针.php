- 先要知道元音字母有哪些
- 两头查找元音字母并且交换
- # php是最没有底线的, 但是写起来没那么绕

```php []
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function reverseVowels($s) {
        $arr = ['a','A','e','E','i','I','o','O','u','U'];
        
        $l = 0;
        $r = strlen($s)-1;
        
        while ($l<$r) {
            if (!in_array($s[$l],$arr)) {
                $l++;
                continue;
            }
            if (!in_array($s[$r],$arr)) {
                $r--;
                continue;
            }
            
            $tmp = $s[$l];
            $s[$l] = $s[$r];
            $s[$r] = $tmp;
            $l++;$r--;
        }
        return $s;
    }
}
```
```python []
class Solution:
    def reverseVowels(self, s: str) -> str:
        need = 'aeiouAEIOU'
        arr = list(s)
        
        l,r = 0,len(arr)-1
        
        while (l<r):
            if arr[l] not in need:
                l+=1
                continue
            if arr[r] not in need:
                r-=1
                continue
            
            arr[l],arr[r] = arr[r],arr[l]
            l+=1;r-=1
        
        return "".join(arr)
```
```go []
func reverseVowels(s string) string {
    arr := map[string]int{"a":1,"A":1,"e":1,"E":1,"i":1,"I":1,"o":1,"O":1,"u":1,"U":1}
    out := []rune(s)
    l,r := 0,len(out)-1
    for l < r {
        if _,ok := arr[string(out[l])]; !ok {
            l++
            continue
        }
        
        if _,ok := arr[string(out[r])]; !ok {
            r--
            continue
        }
        
        out[l],out[r] = out[r],out[l]
        l++
        r--
    }
    
    return string(out)
}
```
