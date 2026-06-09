```js
var numMagicSquaresInside = function(grid) {
    let huanfang = [
	    '[8,1,6,3,5,7,4,9,2]',
	    '[6,1,8,7,5,3,2,9,4]',
	    '[4,9,2,3,5,7,8,1,6]',
	    '[2,9,4,7,5,3,6,1,8]',
	    '[6,7,2,1,5,9,8,3,4]',
	    '[8,3,4,1,5,9,6,7,2]',
	    '[2,7,6,9,5,1,4,3,8]',
	    '[4,3,8,9,5,1,2,7,6]'
    ]
    let count = 0;
    for (let i = 0; i < grid.length - 2; i++) {
    	for (j = 0; j < grid[0].length - 2; j++) {
    		let temp = [];
    		temp.push(grid[i][j])
    		temp.push(grid[i][j+1])
    		temp.push(grid[i][j+2])
    		temp.push(grid[i+1][j])
    		temp.push(grid[i+1][j+1])
    		temp.push(grid[i+1][j+2])
    		temp.push(grid[i+2][j])
    		temp.push(grid[i+2][j+1])
    		temp.push(grid[i+2][j+2])
    		temp = '[' + temp + ']';
    		if (huanfang.includes(temp)) {
    			count++
    		}
    	}
    }
    return count
};
```

