
```
        foreach($nums as $k=>$v){
        
			if($v == $val){
		
				unset($nums[$k]);
			}
		 }
        return count($nums);
```

   遍历数组->判断值如果等于$val->移除对应的键  