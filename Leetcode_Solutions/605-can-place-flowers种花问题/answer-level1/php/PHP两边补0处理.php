    /**
     * @param Integer[] $flowerbed
     * @param Integer $n
     * @return Boolean
     */
    function canPlaceFlowers($flowerbed, $n)
    {
        $flowerbedStr = implode('',array_merge([0], $flowerbed , [0]));
        $zeroArr = explode('1',$flowerbedStr);

        $canCount = 0;
        foreach ($zeroArr as $value)
        {
            $canCount += floor((strlen($value)-1)/2);
            if ($canCount >= $n) return true;
        }

        return false;
    }