### 解题思路


### 代码

```c
void reverseString(char* S,int sSize){
    int left = 0, right = sSize-1;
    while(left<right){
        char t = S[left];
        S[left++] = S[right];
        S[right--] = t; 
    }
}
```