
```
var smallerNumbersThanCurrent = function(nums) {
   var data= nums.map(function(item,index){
        return nums.filter(function(subItem,subIndex){
            return subItem<item
        }).length
    })
    return data
};
```
