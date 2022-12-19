```
class Solution {

    /**
     * @param String $text
     * @return Integer
     */
    function maxNumberOfBalloons($text) {
        $comp = 'balloon';
        $newText = array_count_values(str_split($text, 1));
        $newComp = array_count_values(str_split($comp, 1));

        $num = 10000;
        foreach ($newComp as $key => $item) {
            if (isset($newText[$key])) {
                $tempNum = floor($newText[$key] / $newComp[$key]);
                if ($num >= $tempNum) {
                    $num = $tempNum;
                }
            } else {
                return 0;
            }
        }
        return $num;
    }
}
```
