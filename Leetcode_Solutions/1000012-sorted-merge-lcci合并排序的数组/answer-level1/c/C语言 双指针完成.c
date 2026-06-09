### 解题思路
  此处撰写解题思路

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i = m-1;
    int j = n-1;
    while(ASize--){
        if(i < 0) *(A+ASize) = *(B+j--);
        else if(j < 0) *(A+ASize) = *(A+i--);
        else *(A+ASize) = (*(A+i)>*(B+j)?*(A+i--):*(B+j--));
    }
}
```