### 解题思路
折半查找，小弟特别菜，勿喷。

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
   var reverse = function(x) {
        let [res, str] = [null, ''];
        str = String( Math.abs(x) );
        res = Number( middleReverse(str.length, str.split('')) );
		if( x > 0 ){
            if(res > ( Math.pow(2, 31) - 1 )){
				return 0;
			}
		    return res
		}else{
		    //x < 0
            if(-res < ( Math.pow(-2, 31) )){
                return 0;
            }
			return -res;
		}
    };
    let middleReverse = function (sumLength, strArr) {
        let [left, right, temp] = [0, sumLength - 1, ''];
        if( sumLength % 2 === 0 ){
		    while(left <  right ){
                temp = strArr[ left ];
                strArr[ left ] = strArr[ right ];
                strArr[right] = temp;
                left++;
                right--;
			}
		}else{
            while(left < right){
                temp = strArr[ left ];
                strArr[ left ] = strArr[ right ];
                strArr[ right ] = temp;
                left++;
                right--;
            }

        }
        return strArr.join('')
    }
```