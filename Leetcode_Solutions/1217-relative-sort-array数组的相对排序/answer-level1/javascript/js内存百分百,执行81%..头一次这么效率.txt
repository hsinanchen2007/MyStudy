### 解题思路

### 代码

```javascript
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number[]}
 */
var relativeSortArray = function(arr1, arr2) {
    
    	let obj = {};
				let lgh = arr1.length;
				let lgh2 = arr2.length;
				let myshow = [];
				let count = 0;
				for (let i = 0; i < lgh; i++) {
					if (!obj[arr1[i]]) {
						obj[arr1[i]] = 1;
						count++;
					} else {
						obj[arr1[i]] = obj[arr1[i]] +1;
					}
				}
				// console.log(obj);
				// console.log(count);
					for(let i = 0;i<lgh2;i++){
						for(let j =0;j< obj[arr2[i]];j++){
							myshow.push(arr2[i]);
						}
						
					}
					// console.log(myshow);
					for(let pro in obj){
						// console.log(typeof +pro);
						if(myshow.indexOf(+pro) == -1)
						{   for(let k =0;k< obj[pro];k++){
							myshow.push(+pro);
						}
							
						}
					}
						return myshow;
};
```