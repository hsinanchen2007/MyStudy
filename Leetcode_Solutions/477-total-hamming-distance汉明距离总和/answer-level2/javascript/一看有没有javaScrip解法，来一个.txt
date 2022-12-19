公布一个javaScript解法，不谢？
首先我们从一个两位数上升到n位数，选取需要两两进行求汉明距离最后求和，然后便利得到我们需要的汉明距离和，此方法的复杂度较高O(N^2);
```javascript []
var totalHammingDistance = function(nums) {
    let count = 0;
    if(nums.length < 0) return 0;
    for(let i = 0;i< nums.length -1;i ++){
        for(let j = i + 1;j < nums.length;j ++){
            let num = nums[i] ^ nums[j]
            while(num){
                num = num & (num  -1);
                count ++;
            }
        }
    }
    return count 
};
```
![image.png](https://pic.leetcode-cn.com/25a327062c1d6c9af7592945c9bd88e66ccb0ac093d339af1978ffa12c75b6db-image.png)



优化如下：采用纵向思维，上面的时从横向每个数出发，来进行循环，复杂度过大超时，下来我们纵向的考虑一下，32位进制码，然后可以利用（汉明距离的总和，等于每一个二进制位上的汉明距离的总和。所以两两之间的汉明距离的总和，转换为针对每个bit位置的两两之间汉明距离的总和。对于固定位置的bit，如每1个bit，两两之间的汉明距离的总和实际上为：1的个数*0的个数。）此方法的算法复杂度为O(n)
```javascript []
var totalHammingDistance = function(nums) {
    let count = 0;
    for(let i = 0;i< 32;i ++){
        let sumOne = 0;
        for(j = 0;j < nums.length;j ++){
            sumOne += nums[j] & 1;
            nums[j] >>= 1;
        }
        count += sumOne *(nums.length - sumOne);
    }
    return count;
};
```
![image.png](https://pic.leetcode-cn.com/1283755eff09a25c083ff4f0dbcf1441d00038e99a0dddee09450fe3fc3c8b7d-image.png)
