class Solution {

    /**
     * @param Integer $n
     * @return String[]
     */
    function fizzBuzz($n) {
        $num = array();
        for($i = 1;$i<=$n;$i++)
        {
            if($i%3 == 0 && $i%5 == 0)
            {
                $num[$i] = 'FizzBuzz';
            }
            elseif($i%5 == 0)
            {
                $num[$i] = 'Buzz';
            }
            elseif($i%3 == 0)
            {
                $num[$i] = 'Fizz';
            }
            else
            {
                $num[$i] = ''.$i.'';
            }
        }
        return $num;
    }
}