### 解题思路
此处撰写解题思路
第一次一次通过...慢慢来
先按序存入数组，前后指针对比看，一旦不同返回false，最后返回true
### 代码

```c
bool isPalindrome(int x){
    if(x<0)
        return false;
    if(x<10)
        return true;

    
    int  nums[30];
    int i=0;
    int p=x;
    while(p!=0)
    {
        int pop =p%10;
        nums[i++] = pop;
        p/=10;
    }
    //nums[i]为空，之前有数。
    //两个指针，依次往中间靠拢，比对是否相同。
    int j;
    for( j=0,--i;  j<i;   j++,i--)
    {
        if(nums[j]!=nums[i]) 
            return false;
    }
    return true;

}
```