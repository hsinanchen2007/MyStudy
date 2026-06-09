```
function numberOfLines($widths, $S) {
        $sum = 0;
     	$line = 0;
     	$end = 0;
     	for ($i=0; $i < strlen($S) ; $i++) { 
     		# code...
     		$sum += $widths[ord($S[$i])-97];
     		if($sum > 100){
     			$i--;
     		}
     		if($sum >= 100){
     			$sum = 0;
     			$line++;
     		}

     	}
     	return [++$line,$sum];
    }
```
