```javascript
var findRelativeRanks = function(nums) {
    	const arr = nums.map(key => {return key});
	    const sortArr = arr.sort((a,b) => {return b - a});
		const goldMap = {};
	    sortArr.map((key, index) => {
	    	if(index === 0){
	    		goldMap[key] = "Gold Medal";
	    	}
	    	if(index == 1){
	    		goldMap[key] = "Silver Medal";
	    	}
	    	if(index == 2){
	    		goldMap[key] = "Bronze Medal";
	    	}
	    	if (index > 2){
	    		goldMap[key] = index + 1;
	    	}
	    });
	    const resArr = nums.map(key => {
	        return (
	            goldMap[key] + ""
	        )
	    });
	    return resArr;
	};

```