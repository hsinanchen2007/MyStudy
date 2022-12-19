### 解法一 迭代法

1. 初始化结果为 二维空数组
2. 遍历给定数组中的每一个元素，在每一次遍历中，处理结果集。结果集中的每个元素添加遍历到的数字，结果集的长度不断增加。

```php
function subsets($nums)
{
    if (is_null($nums)) {
        return [];
    }

    // 1. 迭代法
    $result = [[]];
    if (empty($nums) {
        return $result;
    }
    foreach ($nums as $num) {
        foreach ($result as $item) {
            $tmp = $item;
            $tmp[] = $num;
            $result[] = $tmp;
        }
    }

    return $result;
}
```

### 解法二 递归法（分治）

注意递归终止条件。以 [1, 2, 3] 为例，画出递归树就很好理解了。

```php
function subsets($nums)
{
    if (empty($nums)) {
        return [];
    }

    $result = [];
    // 2. 递归回溯法
    $this->helper($nums, 0, [], $result);
    return $result;
}

function helper($nums, $index, $current, &$result)
{
    // terminator
    if ($index == count($nums)) {
        $result[] = $current;
        return;
    }

    // split and drill down
    // 不选 not pick the number in this index
    $this->helper($nums, $index + 1, $current, $result);
    // 选
    $current[] = $nums[$index];
    $this->helper($nums, $index + 1, $current, $result);

    // merge
//        $result[] = $current;
    // revert
}
```

### 回溯法

画出递归树，答案是遍历递归树的所有节点

```php
class Solution
{
    protected $result;
    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function subsets($nums)
    {
        // 画出递归树，答案是遍历递归树的所有节点
        $this->result[] = [];
        $this->sub($nums, [], 0);
        return $this->result;
    }

    private function sub($nums, $list, $start)
    {
        if (count($list) == count($nums)) {
            return;
        }
        for ($i = $start; $i < count($nums); ++$i) {
            $list[] = $nums[$i];
            // 在这里，递归中途添加，而不是递归终止条件处添加
            $this->result[] = $list;
            $this->sub($nums, $list, $i + 1);
            array_pop($list);
        }
    }
}
```
