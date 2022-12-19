看了答案的思路，自己写的
![image.png](https://pic.leetcode-cn.com/795724db64c800729df41fa6615960f3dece6ae185f4351afa5e953e341deaf2-image.png)

```
int majorityElement(int* nums, int numsSize){
    int count = 1,candidate = nums[0];
    for(int i = 1; i<numsSize; i++) {//这里int i = 0;++i就是错的（实例：[6,5,5]）why？？？for循环先执行体函数，再执行++i！！！所以会错
        if(nums[i]==candidate||0==count) {//从第二个元素开始，如果和上一个相等||count==0 -> 就把当前值赋值给candidate，且count++。如果不等，且count！=0，count--；最后count一定大于0，candidate里存放的就是要求的众数！！！
            candidate = nums[i];
            count++;}
        else count--;
    }
    return candidate;
}
```
