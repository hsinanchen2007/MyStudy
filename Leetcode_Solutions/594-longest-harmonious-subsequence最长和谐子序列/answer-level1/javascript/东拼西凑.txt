### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
  var findLHS = function (nums) {
//空数组返回0
         if(nums.length==0){
            return 0
        }

        var ans = []
        
        for (let i = 0; i < nums.length; i++) {
            //相减等于0的个数            
            var tem0 = 0
            //相减等于1的个数
            var tem1 = 0
            //相减等于-1的个数
            var temfu1 = 0
            var tem=0
            for (let j = 0; j < nums.length;j++) {  
                if (nums[i] - nums[j] == -1 ) {
                    temfu1++   
                }
                else if(nums[i] - nums[j] == 1){
                    tem1++
                }
                else if(nums[i] - nums[j] == 0){
                    tem0++
                }
                tem=Math.max(temfu1,tem1)
                //若数组中元素全部相同，则为0
                if(tem>0){
                ans[i] = tem+tem0
                }
                else{
                    ans[i]=0
                }
            }
        }
        return(Math.max.apply(null,ans))
    };
```