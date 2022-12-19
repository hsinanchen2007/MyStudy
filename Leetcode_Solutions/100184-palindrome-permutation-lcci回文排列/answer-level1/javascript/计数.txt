先去重，再累计基数个数，不能大于1
```
var canPermutePalindrome = function(s) {
		//console.log(s)
	    var arr = [];
	    var arrS = s.split('');
	    var odd = 0;
	    for(var i = 0;i < arrS.length;i++){
	        if(arr.indexOf(arrS[i]) < 0){
	            arr.push(arrS[i])
	        }
	    }
	    //console.log(arr);
	    for (var j = 0; j < arr.length; j++) {

	    	var count = 0;
	    	for(var q = 0;q < arrS.length;q++){
	    		if (arr[j] === arrS[q]) {
	    			count += 1;
	    		}
	    	}
	    	if (count % 2 !== 0) {
	    		odd += 1;
	    	}

	    }
	    if (odd > 1) {
	    	return false
	    }
	    return true

	};
```
