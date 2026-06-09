### 解题思路
此处撰写解题思路

### 代码

```c
char nextGreatestLetter(char* letters, int lettersSize, char target){
    int i=0;
    if(target>=letters[lettersSize-1])
        return letters[0];
    while(letters[i]<=target){
        i++;
    }
    return letters[i];
}
```