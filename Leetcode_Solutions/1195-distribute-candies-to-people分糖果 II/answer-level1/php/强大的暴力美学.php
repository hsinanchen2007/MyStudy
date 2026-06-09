class Solution {

    /**
     * @param Integer $candies
     * @param Integer $num_people
     * @return Integer[]
     */
    function distributeCandies($candies, $num_people) {  
        for($i=0; $i<$num_people; $i++){
            $data[] = 0;
        }
        $i = 0;
        while($candies != 0){
            $data[$i % $num_people] += min($i + 1, $candies);
            $candies -= min($i + 1, $candies);
            $i += 1;
        }
        return $data;
    }
}