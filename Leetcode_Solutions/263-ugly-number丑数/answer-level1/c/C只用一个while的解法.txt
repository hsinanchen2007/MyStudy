### 解题思路
![捕获.JPG](https://pic.leetcode-cn.com/e834e8f187625b4a9a6782d8dfbc2998cabe8520fbb2e89cab801545a8bb237e-%E6%8D%95%E8%8E%B7.JPG)

是否可以用一次while循环就解决？可以通过设置一个数组实现

### 代码

```c
bool isUgly(int num){
    int t[3]={2,3,5};
    int flag=1;
    int i=0;
    while(num && flag){
        if(num%t[i]==0){
            num=num/t[i];
        }
        else{
            if(i==2){
                flag=0;
            }
            else{
                i++;
            }
        }
    }
    if(num!=1)
        return false;
    return true;

}
```