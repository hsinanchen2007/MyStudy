```
  public function singleNumber($nums)
    {
        // 统计每个值出现的次数
        $valNums = array_count_values($nums);
        foreach ($valNums as $key => $value) {
            if ($value === 1) {
                return $key;
            }
        };
    }
```