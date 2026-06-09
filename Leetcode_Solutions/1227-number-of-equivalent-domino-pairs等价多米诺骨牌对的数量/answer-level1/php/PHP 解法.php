### 解题思路
1. 遍历二维数组的每一个元素，进行数组排序，生成唯一的键并将出现的次数存储在 hashMap 中；
2. 遍历 hashMap，累加每一个组合 (n * (n - 1))

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $dominoes
     * @return Integer
     */
    function numEquivDominoPairs($dominoes) {
        if (count($dominoes) <= 1) {
            return 0;
        }

        $map = [];
        $count = 0;
        foreach ($dominoes as $item) {
            sort($item);
            $hash = $item[0] * 10 + $item[1];
            if (!isset($map[$hash])) {
                $map[$hash] = 1;
            } else {
                $count += $map[$hash];
                $map[$hash]++;
            }
        }

        return $count;
    }
}
```