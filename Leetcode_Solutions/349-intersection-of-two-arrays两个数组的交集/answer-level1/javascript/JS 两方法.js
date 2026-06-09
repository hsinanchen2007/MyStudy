逻辑很简单，leetcode测试数组一般很多很长，哈希一下，可以节省循环次数,又能满足题目要求
然后找共同的数字
```javascript []
var intersection2 = function(nums1, nums2) {
    var hash1 = new Set(nums1);
    var hash2 = new Set(nums2);
    var res=[];
    for(var i of hash1){
        if(hash2.has(i)){
            res.push(i);
        }
    }
    return res;
};
```
![Screen Shot 2019-09-12 at 11.22.05 PM.png](https://pic.leetcode-cn.com/7dab97699ad60ce6c737fe13aa17fe511c9bcdb3b0b6b2c84b12eacffa633316-Screen%20Shot%202019-09-12%20at%2011.22.05%20PM.png)



2，这是不想用Set了,用filter找共同数字的时候，顺便去重

```javascript []
var intersection = function(nums1, nums2) {
    var hash1 = new Set(nums1);
    return nums2.filter(function(num,index,self){
            return hash1.has(num)&&(self.indexOf(num)==index);
        });
};
```
![Screen Shot 2019-09-12 at 11.20.12 PM.png](https://pic.leetcode-cn.com/c18d6ded03799fb7230286a9bda5bcc78ef262f7b0772821d5230454fc858e4d-Screen%20Shot%202019-09-12%20at%2011.20.12%20PM.png)


