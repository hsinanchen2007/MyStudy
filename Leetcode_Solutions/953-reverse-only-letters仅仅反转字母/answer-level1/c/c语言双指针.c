### 解题思路
左右指针，和快排思想差不多。

### 代码

```c
char * reverseOnlyLetters(char * S){
    int i=0;
    int j=strlen(S)-1;
    while(i<j)
    {
        while(i<j&&!(S[j]>=65&&S[j]<=90||S[j]>=97&&S[j]<=122))
        {
            j--;
        }
        while(i<j&&!(S[i]>=65&&S[i]<=90||S[i]>=97&&S[i]<=122))
        {
            i++;
        }
        int temp=S[i];
        S[i]=S[j];
        S[j]=temp;
        i++;
        j--;
    }
    return S;
}
```