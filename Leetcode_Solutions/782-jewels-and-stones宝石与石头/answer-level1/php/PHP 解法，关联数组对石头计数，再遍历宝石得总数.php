
```php []
function numJewelsInStones($J, $S) {
    $cnt = [];
    for ($i=0; $i < strlen($S); $i++) {
    	if (isset($cnt[$S[$i]])) {
			$cnt[$S[$i]] += 1;
    	} else {
    		$cnt[$S[$i]] = 1;
    	}
    }
    $sum = 0;
    for ($i=0; $i < strlen($J); $i++) { 
    	if (isset($cnt[$J[$i]])) {
    		$sum += $cnt[$J[$i]];
    	}
    }
    return $sum;
}
```
