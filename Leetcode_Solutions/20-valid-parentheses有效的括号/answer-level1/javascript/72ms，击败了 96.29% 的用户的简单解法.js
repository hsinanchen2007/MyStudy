将string转化为数组，遍历数组判断是否有一对()/{}/[]，若有则在数组中删除，i值减一再次检索。
若最后的数组为空，则返回true

	`var isValid = function(s) {
		var arr = new Array();
		arr = s.split('');
		for(let i=0;i<arr.length;){
			if(check(arr[i],arr[i+1])==true){
				arr.splice(i,2);
				i--
			}
			else{
				i++
			}
		}
		console.log(arr)
		if(arr.length>0){
			return false;
		}
		else{
			return true;
		}

	};

	function check(m,n){
		if(m == '('&& n == ')'){
			return true;
		}
		else if(m == '['&& n == ']'){
			return true;
		}
		else if(m == '{'&& n == '}'){
			return true;
		}
		else{
			return false;
		}
	}`