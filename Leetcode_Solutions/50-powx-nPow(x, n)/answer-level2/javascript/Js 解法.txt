```
var myPow = function(x, n) {
	x = n> 0? x: 1/x
	n = Math.abs(n)
	let map = new Map()
	let pow = (x,n)=>{
		let result
		if(map.has(n)){
			return map.get(n)
		}else if(n == 0){
            return 1;
		}else if(n == 1){
			result= x
		}else{
			const m = Math.floor(n/2)
			result= pow(x,m) * pow(x,n-m)
		}
		map.set(n,result)
		return result;
	}
	return pow(x,n)
};
```
