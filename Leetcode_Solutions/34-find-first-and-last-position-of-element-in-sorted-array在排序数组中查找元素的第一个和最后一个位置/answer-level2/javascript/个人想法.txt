function search(nums,target) {
            var first  = null,
            last = null,
            flag1 = true
            flag2 = true
            for(var i = 0,j = nums.length-1;i <nums.length,j >= 0;i++,j--) {
                if(flag1) {
                    if(nums[i] === target){
                        first = i;
                        flag1 = false
                    }        
                }
                if(flag2) {
                    if(nums[j] === target) {
                        last = j
                        flag2 = false
                }}
                if(flag1 === false &&flag2 === false) return [first,last];
            }
            return [-1,-1]
        }
思路大概就是左右同时开始找，左边找到保存到first，右边找到保存到last,通过flag1和flag2去判断是否都找到了，
如都找到返回结果，其他返回[-1,-1]