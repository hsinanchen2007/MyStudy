### 解题思路
此处撰写解题思路

### 代码

```c
bool isUnique(char* astr){

bool rel=true;
if(strlen(astr)==0){
    rel=true;
}else
{
    int len = strlen(astr);
    int arr[len];
    int zimu[26]={0};
    int i=0;
  //  zimu = malloc(sizeof(int)*26);
    while(i<len){
        arr[i] = astr[i]-'a';
        
        zimu[arr[i]]++;
        i++;
    }
    int k=0;
    while(k<26)
    {
        if(zimu[k]>1)
        {rel = false;
        break;
        }
        k++;
    }
}
return rel;
}
```