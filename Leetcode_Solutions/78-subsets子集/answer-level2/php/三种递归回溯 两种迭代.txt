
# 看到解决问题的方法五花八门这里总结一下
光递归就有 三种
## 第一种  回溯

```
/**
     * 子集问题 第一种递归
     * @param $nums
     * @return array
     */
    function subsets($nums) {
        $res = [];
        $this->dfs($nums, [], 0, $res);
        return $res;
    }

    function dfs($nums, $list, $start, &$res) {
        $res[] = $list;
        for ($i = $start; $i < count($nums); $i++) {
            array_push($list, $nums[$i]);
            $this->dfs($nums, $list, $i + 1, $res);
            array_pop($list);
        }
    }

```

## 第二种  回溯

```
/**
     * 子集问题第二种递归
     * @param $nums
     * @return array
     */
    function subsets2($nums) {
        if (count($nums) == 0) return [];
        $res = [[], [$nums[0]]];
        //$res = [];
        $this->dfs2(1, $nums, $res);
        return $res;
    }

    function dfs2($start, $nums, &$res) {
        if ($start == count($nums)) {
            return;
        }

        $tmpall = [];
        for ($i = 0; $i < count($res); $i++) {
            $tmp = $res[$i];
            array_push($tmp, $nums[$start]);
            $tmpall[] = $tmp;
        }

        $res  = array_merge($res, $tmpall);
        $this->dfs2($start + 1, $nums, $res);
    }

```
## 第三种  回溯

```
/**
     * 子集问题第三种递归
     * @param $nums
     * @return array
     */
    function subsets3($nums){
        // 画出递归树，答案是遍历递归树的所有节点
        $res[] = [];
        $this->dfs3($nums, [], 0, $res);
        return $res;
    }

    private function dfs3($nums, $list, $start, &$res) {
        if (count($list) == count($nums)) {
            return;
        }
        for ($i = $start; $i < count($nums); ++$i) {
            $list[] = $nums[$i];
            // 在这里，递归中途添加，而不是递归终止条件处添加
            $res[] = $list;
            $this->dfs3($nums, $list, $i + 1, $res);
            array_pop($list);
        }
    }

```


## 第一种迭代

```
    function subsets($nums) {
        $res = [];
        if (count($nums) < 1)  {
            return [[]];
        }

        $head = array_shift($nums);
        $other_sets = $this->subsets1($nums);
        foreach ($other_sets as $other_set) {
            $res[] = array_merge((array)$head, (array)$other_set);
        }

        return array_merge($res, $other_sets);
    }
```


## 第二种迭代

```
/**
     * 子集问题(迭代)
     * @param $nums
     * @return array
     */
    function subsetsIteration($nums) {
        if (is_null($nums)) return [];
        $result = [[]];
        if (empty($nums)) return $result;
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

