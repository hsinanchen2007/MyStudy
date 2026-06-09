### 解题思路
此处撰写解题思路
虽然题目里面的测试数据最多两位数，但是还是考虑最多四位的情况，使用test[4]数组进行存储
另外使用start,end双指针来进行判断
### 代码

```c
int compress(char* chars, int charsSize){
    int start=0,end=0;
    int flag=0;
    int count=0;
    int test[4]={0};
    for(start=0;start<charsSize;){
        while(end<charsSize&&chars[start]==chars[end]){
            end++;
        }
        chars[flag++]=chars[start];
        count=0;
        count=end-start;
        // printf("%d",count);
        if(count>1){
            int i=0;
            while(count){
                test[i++]=count%10;
                count/=10;
            }
            i--;
            for(;i>=0;i--){
                chars[flag++]=test[i]+'0';
            }
        }
        start=end;
    }
    return flag;
}
```