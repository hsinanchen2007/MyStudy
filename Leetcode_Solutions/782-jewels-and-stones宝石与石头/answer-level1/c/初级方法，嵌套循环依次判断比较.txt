### 解题思路
双层循环，S中的元素依次与J中的元素比较
时间复杂度：O(strlen(J)*strlen(S))
空间复杂度：定义了三个变量 count，i，j O(3)
### 代码

```c
int numJewelsInStones(char * J, char * S){
    int count=0;
    for(int i=0;i<strlen(J);i++)
        for(int j=0;j<strlen(S);j++)    //可以改进，从S中第一次出现J中元素的位置开始比较节省时间复杂度
        {
            if(S[j]==J[i])
            count=count+1;
        }
        return count;
}
```