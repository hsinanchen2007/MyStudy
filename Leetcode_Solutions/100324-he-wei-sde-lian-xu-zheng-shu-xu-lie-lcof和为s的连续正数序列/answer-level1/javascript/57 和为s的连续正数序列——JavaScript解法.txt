### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target){
				var i = 1,j=1,sum = 1,res = [];
				while(i<target/2){
					if(sum <target){
						j++;
						sum += j;
					}else if(sum > target){
						sum -= i;  //sum
						i++;
					}else{
						var arr = [];
						for(var k = i;k<=j;k++){
							arr[k-i] = k;
						}
						res.push(arr);
						sum -= i;
						i++;
					}
				}
				return res;
			
};
```