    class Solution {

        /**
        * @param Integer[][] $intervals
        * @return Integer
        */
        function eraseOverlapIntervals($intervals) {
            usort($intervals, [$this, 'sort']);
            $tag = null;
            $cnt = 0;
            foreach($intervals as $interval) {
                if(is_null($tag) || $tag <= $interval[0]) {
                    $cnt++;
                    $tag = $interval[1];
                }
            }
            return count($intervals) - $cnt;
        }

        function sort($a, $b) {
            if ($a[1] < $b[1]) return -1;
            if ($a[1] > $b[1]) return 1;
            if ($a[0] > $b[0]) return -1;
            if ($a[0] < $b[0]) return 1;
            return 0;
        }
    }