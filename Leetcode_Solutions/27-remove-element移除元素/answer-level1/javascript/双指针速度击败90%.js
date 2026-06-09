慢指针i，快指针j，以j来检查nums，最后返回i。

```
    var removeElement = function(nums, val) {
        var i=0,j=0;
        for(j;j<nums.length;j++){
            if(nums[j]!=val){
            nums[i]=nums[j];
            i++;
          }
        }
        return i;
    };
```
