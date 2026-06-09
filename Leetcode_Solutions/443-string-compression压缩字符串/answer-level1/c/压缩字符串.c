### 解题思路
处理好细节就行

### 代码

```c
int compress(char* chars, int charsSize){
    int i,j,k,c;
    i=j=k=0;
    while(i<charsSize){
        chars[k]=chars[i];
        while(j<charsSize&&chars[i]==chars[j])j++;
        int temp=j-i;           //字符chars[i]出现的次数
        c=log10(temp)+1;        //字符chars[i]出现的次数的位数
        if(temp!=1){
            k=k+c;
            while(temp){
                chars[k--]=temp%10+'0';//逆序赋值
                temp/=10;
            }
            k=k+c;          //重新定位k
        }
        k++;
        if(j==charsSize)break;
        else i=j;
    }
    return k;
}
```