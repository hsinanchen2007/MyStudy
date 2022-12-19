var convert = function(s, numRows) {
    if (numRows == 1) return s;
	var resultArr = []
	for(var i = 0; i < numRows; i++) {
		resultArr.push([])
	}
	s.split('').forEach(function (value, index, arr) {
		var remainder = index % (numRows * 2 - 2);
		if (remainder >= numRows) {
			resultArr[(numRows - 2) - remainder % numRows].push(arr[index])
		} else {
			resultArr[remainder].push(arr[index]);
		}
	})
	return resultArr.map(function (item, index) {
		return item.join('');
	}).join('');
};