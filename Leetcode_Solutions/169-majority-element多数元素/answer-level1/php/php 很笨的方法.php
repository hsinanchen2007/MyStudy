![图片.png](https://pic.leetcode-cn.com/03867fc362052a4aa13b5be4f4505905728e50a02a2a49159a9c8b4da439d482-%E5%9B%BE%E7%89%87.png)

```
$count = count($nums);
        $nu = ceil($count/2);
        $newArr = [];

        foreach ($nums as $key=>$value) {
            if (!array_key_exists($value, $newArr)) {
                $temp = $value;
                $time = 0;
                for ($i=0; $i<$count; $i++) {
                    if ($temp == $nums[$i]) {
                        $time++;
                    }
                }
                $newArr[$temp] = $time;
            }

        }

        foreach ($newArr as $key=>$value) {
            if ($value >= $nu) {
                return $key;
            }
        }
```
