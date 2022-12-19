

` return strrev($x) == $x;`

当然你也可以用下面这种方法

```
        $n = $x;       
        $reverse = 0;
        while ($n > 0) {
            $reverse = $reverse * 10;
            $reverse = $reverse + $n % 10;
            $n = (int)($n/10);
        }
        
        return ($x === $reverse);
```

