class Solution {

    /**
     * @param Integer $candies
     * @param Integer $num_people
     * @return Integer[]
     */
    function distributeCandies($candies, $num_people) {
        $i = 0;
        $peopleCandies = [];

        while (true) {
            for ($j = 1; $j <= $num_people; $j++) {
                if ($i == 0 and !isset($peopleCandies[$j])) {
                    $peopleCandies[$j] = 0;
                }

                $getNum = $i * $num_people + $j;

                if ($candies > $getNum) {
                    $peopleCandies[$j] += $getNum;
                    $candies -= $getNum;
                } else {
                    $peopleCandies[$j] += $candies;
                    $candies = 0;
                }
            }

            if ($candies == 0) {
                break;
            }

            $i++;
        }

        return $peopleCandies;
    }
}