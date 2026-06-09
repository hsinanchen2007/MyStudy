### 解题思路
 1. 找状态
       第i次运算完之后，能够产生的结果的所有情况为 arr[i] = obj{0:1, 1:y, ...} 
       这个对象 key 为运算结果，value为 key这个运算结果出现的次数。
       这个obj 依赖于上一次的运算结果，上一次运算结果为 obj[i-1] = obj2{k1:v1, k2:v2,....}
  
       那么此次的运算结果一定是 
       k1-nums[i] 次数为 v1，
       k1+nums[i] 次数也为 v1,
  
       k2 - nums[i]，次数 v2,
       k2 + nums[i] 次数为v2...
  
       这当中很可能会有重复的结果， 
       例如当前nums = 1， 上一次 k1 = 2 --->>> k1 + 1 = 3,  k2 = 4  --->>> k2-1 = 3,
       出现这种重复的时候， 
           第一次出现的时候:  
```
            arr[i][key] = arr[i-1][k1]  //因为JS为动态语言，不出现的话key我就不赋值，可以节省空间，只有出现的时候，
                                        //我赋值为 arr[i-1][key]
```
            之后每次出现: 
```
                arr[i][key] += arr[i-1][k2] 
```
 2. 转移方程
```
                n = nums[i]
                arr[i][k2 - n] += arr[i-1][k2]    
                arr[i][k2 + n] += arr[i-1][k2]   
```
 3. 初始条件及边界值

```
                let sum = nums[0];
                let subt = -nums[0]
                arr[0].[sum]  = 1;
                arr[0].[subt] = 1;

                //特殊情况
                如果加减都为一样的，也就是 0 ,
                arr[0] = {0：2}
```
4. 顺序
    从小到大
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} S
 * @return {number}
 */
var findTargetSumWays = function(nums, S) {
    let len = nums.length;
    let arr = []
    arr[0] = {}
    if(nums[0] == 0){
        arr[0][0] = 2;
    }else{
        let sum = nums[0];
        let subt = -nums[0]
        arr[0][sum] = 1;
        arr[0][subt] = 1;
    }
    for(let i = 1; i < len;i++){
        arr[i] = {};
        for(let key in arr[i-1]){
            let sum = parseInt(key) + nums[i];
            let subt = parseInt(key) - nums[i];
            let last = arr[i-1][key];
            if(arr[i][sum] == undefined){
                arr[i][sum] = last;
            }else{
                arr[i][sum] += last
            }
            if(arr[i][subt] == undefined){
                arr[i][subt] = last;
            }else{
                arr[i][subt] += last;
            }
        }
    } 
    return arr[len-1][S] ?  arr[len-1][S] : 0;
};
```