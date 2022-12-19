```
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    let length = nums.length;
    if(length == 0){
        return 0;
    }

    if(length == 1){
        return nums[0];
    }

    //线性考虑 [0, n – 2] 和 [1, n – 1]，然后求二者的最大值
    let numstwo = nums.slice(1);
    console.log(numstwo)
    let lengthtwo = numstwo.length;
    let tempone = new Array(length),temptwo = new Array(lengthtwo);
    tempone[0] = 0;
    tempone[1] = nums[0];
    temptwo[0] = 0;
    temptwo[1] = numstwo[0];

    for(let i=2;i<length;i++){
        tempone[i] = Math.max(tempone[i-1],tempone[i-2]+nums[i-1]);
    }

    for(let i=2;i<=lengthtwo;i++){
        temptwo[i] = Math.max(temptwo[i-1],temptwo[i-2]+numstwo[i-1]);
    }

    console.log(tempone,temptwo);
    return Math.max(temptwo.pop(),tempone.pop());
};
```
