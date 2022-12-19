```

  function moveZeroes(&$nums) {
       foreach($nums as $key => $num){
			if($num==0){
				unset($nums[$key]);
				$nums[] = 0;
			}
		}
		return $nums;
  }


```