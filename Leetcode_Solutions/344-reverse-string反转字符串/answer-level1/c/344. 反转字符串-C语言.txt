### 解题思路
本质就是前后值进行交换。
方法一：传统的数组操作法；
方法二：双指针操作法。
方法三：异或交换值法。


结果：
![image.png](https://pic.leetcode-cn.com/9a030274e2e7702fc3a0c1c8079eb9333e18af29cd8d0df1bac928b5363f3167-image.png)


### 代码

```c
//方法一：传统的数组操作法
void reverseString(char* s, int sSize){
    char cTemp = 0;
    for(int i=0; i<sSize/2; i++)
    {
        cTemp = s[i];
        s[i] = s[sSize-1-i];
        s[sSize-1-i] = cTemp;
    }
}

//方法二：双指针操作法
void reverseString(char* s, int sSize){
    char cTemp = 0;
    char *pcLeft = s;
    char *pcRight = &s[sSize-1];
    while(pcLeft < pcRight)
    {
        cTemp = *pcLeft;
        *pcLeft = *pcRight;
        *pcRight = cTemp;
        pcLeft++;
        pcRight--;
    }
}

//方法三：异或交换值法
void reverseString(char* s, int sSize){
    char* pcLeft = NULL;
    char* pcRight = NULL;
    pcLeft = s;
    pcRight = &s[sSize-1];

    while(pcLeft < pcRight)
    {
        *pcLeft = *pcLeft ^ *pcRight;
        *pcRight = *pcRight ^ *pcLeft;
        *pcLeft = *pcLeft ^ *pcRight;

        pcLeft++;
        pcRight--;
    }

}
```