 public function heightChecker($heights) {
        $arr = $heights;
        sort($heights);
        return count($heights)-count(array_intersect_assoc($arr,$heights));

    }