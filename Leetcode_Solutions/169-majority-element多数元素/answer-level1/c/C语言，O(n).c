![批注 2020-03-13 132956.png](https://pic.leetcode-cn.com/074f0eed781a2aeb3786fcb1f58702f41937ae1213404473940806203902ba10-%E6%89%B9%E6%B3%A8%202020-03-13%20132956.png)

```
int majorityElement(int* nums, int numsSize){
    int cnt=1,tag=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        if(cnt==0){
            tag=nums[i];
            cnt=1;
        }
        else if(nums[i]==tag){
            cnt++;
        }
        else cnt--;
    }
    return tag;
}
```
