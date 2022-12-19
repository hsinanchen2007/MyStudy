### 解题思路
[滑动窗口和利用数组桶代替hashmap](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-cshi-xian-/)是能够理解的，但是一直理解不到位的地方是**“仅当s[start,end) 中存在s[end]时更新start”**这句话。
在数次解答错误的代码中我对*这句话*的理解是：`if(hash[s[end]]!=-1){...}`，但是这种方式的问题是：
在hash中不是-1的元素**不一定**就在[start,end)中。比如"abcab..."这样的输入，当start=0,end=3时，start接下来将会跳过b、c，到达最后一个b的位置，接下来end也会指向b(end++),但是此时虽然hash[s['b']]!=0,但此时的start不应该执行if又到达start=1。
这里很细节啊！


一个基础知识的回忆：[数组和指针绝不等价，数组是另外一种类型](http://c.biancheng.net/view/vip_2018.html)

int *arr;    (1)  arr=(int *)malloc(sizeof(int)*10);
int arr[10];    (2)
两个arr的长度是有去别的，第一个是4字节或8字节(具体要看地址总线)；第二个是40字节，即4字节x10。
两者的memset也有区别
(1): memset(arr,-1,sizeof(int)*10);
(2): memset(arr,-1,sizeof(arr));

*较为本质的区别是*：int arr[10]; 和int *arr; 
1. 不是一个类型的；
2. 第一个arr是指针常量，第二个arr是指针变量。

### 代码

```c
int lengthOfLongestSubstring(char * s){
    if(strlen(s)==1) return 1;
    int maxLength=0,i,j,start,end;
    int hash[128];
    memset(hash,-1,sizeof(hash));
    start=0;
    end=0;
    while(s[end]!='\0'){
        // 仅当s[start,end) 中存在s[end]时更新start
        if(hash[s[end]]>=start){
            start=hash[s[end]];
            start++;
        }
        hash[s[end]]=end;
        end++;
        int length=end-start;
        if(maxLength<length) maxLength=length;
        // printf("start=%d\tend=%d\n",start,end);
    }
    return maxLength;
    

}
```