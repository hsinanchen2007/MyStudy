```
function maxDistToClosest($seats)
    {
        $count = count($seats);
        $zeroCount = 0; // 连续空位数量
        $maxDistance = 0; // 最大距离

        // 假设不坐在两边
        for ($i = 0; $i < $count; $i++) {
            if ($seats[$i]) {
                $zeroCount = 0;
            } else {
                $zeroCount++;
                $maxDistance = max($maxDistance, floor(($zeroCount + 1) / 2)); // 得到两个非空位的中间距离
            }
        }

        // 假设坐在最左边,计算是否存在最大距离
        for ($i = 0; $i < $count; $i++) {
            if ($seats[$i]) {
                $maxDistance = max($maxDistance, $i);
                break;
            }
        }

        // 假设坐在最右边,计算是否存在最大距离
        for ($i = $count - 1; $i >= 0; $i--) {
            if ($seats[$i]) {
                $maxDistance = max($maxDistance, $count - 1 - $i);
                break;
            }
        }
        return $maxDistance;
    }
```
