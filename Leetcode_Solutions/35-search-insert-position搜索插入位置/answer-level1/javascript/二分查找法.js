### 1.利用js数组方法
```
var searchInsert = function(nums, target) {
    let j=nums.indexOf(target);
    if(j!=-1)return j;


    for(let i = 0 ; i < nums.length; i++){
        if(nums[i]>target)return i;
    }
    return nums.length;
}
```
### 2.[参照大神题解](https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/)
设置左右中三个指针，虽说我也想到了这种思路，但是直接利用一直length除2，判断是否存在该值还行，若要添加某值就不行了。