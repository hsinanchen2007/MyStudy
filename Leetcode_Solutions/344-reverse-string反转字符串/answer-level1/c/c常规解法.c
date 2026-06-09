### 解题思路
左右变量同时遍历数组。然后交换位置，实现反转。

### 代码

```c
void reverseString(char* s, int sSize){
    int left=0;
    int right=sSize-1;
    while(left<right)
    {
        int temp=s[left];
        s[left]=s[right];
        s[right]=temp;
        left++;
        right--;
    }
}
```