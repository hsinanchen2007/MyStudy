function sortArrayByParity($A)
    {
        for ($i = 0; $i < count($A); $i++) {
            if ($A[$i] % 2 != 0) {
                $tmp = $A[$i];
                unset($A[$i]);
                $A[] = $tmp;
            }
        }
        return $A;
    }