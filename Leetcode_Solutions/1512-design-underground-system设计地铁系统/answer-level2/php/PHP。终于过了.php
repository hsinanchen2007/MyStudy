### 解题思路
进站：存进站信息
出站：存地铁路线行程信息

### 代码

```php
class UndergroundSystem {
    /**
     */
    public $people = [];
    public $underground = [];
    function __construct() {

    }

    /**
     * @param Integer $id
     * @param String $stationName
     * @param Integer $t
     * @return NULL
     */
    function checkIn($id, $stationName, $t) {
        $this->people[$id] = [$stationName,$t];
    }

    /**
     * @param Integer $id
     * @param String $stationName
     * @param Integer $t
     * @return NULL
     */
    function checkOut($id, $stationName, $t) {
        if ($this->people[$id]){
            $way = $this->people[$id][0] .'-'. $stationName;
            $this->underground[$way]["time"] = ($this->underground[$way]["time"] ?? 0) + ($t - $this->people[$id][1]);
            $this->underground[$way]["num"] = ($this->underground[$way]["num"] ?? 0) + 1;
        }
    }

    /**
     * @param String $startStation
     * @param String $endStation
     * @return Float
     */
    function getAverageTime($startStation, $endStation) {
        $way = $startStation .'-'. $endStation;
        return isset($this->underground[$way]) ? $this->underground[$way]["time"]/$this->underground[$way]["num"] : null;
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * $obj = UndergroundSystem();
 * $obj->checkIn($id, $stationName, $t);
 * $obj->checkOut($id, $stationName, $t);
 * $ret_3 = $obj->getAverageTime($startStation, $endStation);
 */
```