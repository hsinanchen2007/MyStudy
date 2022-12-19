### 解题思路
两者长度不等返回false
长度皆为0返回true
记录下B中有几个字符与A[0]相等，用sum来记录，表示允许失配的次数，用count来记录匹配的字符数
count==len1时返回true

失配时若sum==1则返回false,否则i重置为0，j循环返回，并寻找下一个满足B[j]==A[0]的位置，

### 代码

```c
bool rotateString(char * A, char * B){
    int len1=strlen(A),len2=strlen(B);
    if(len1!=len2){
        return false;
    }
    if(len1==0&&len2==0){
        return true;
    }
    int sum=0,i=0,j=0,count=0;
    while(j<len2){
        sum+=(A[0]==B[j]);
        j++;
    }
    if(sum==0){
        return false;
    }
    j=0;
    while(j<len2&&B[j]!=A[0]){
        j=(j+1)%len2;
    }
    while(i<len1){
        if(A[i]==B[j]){
            i++;
            j=(j+1)%len2;
            count++;
            if(count==len1){
                return true;
            }
        }else{
            if(sum==1){
                return false;
            }
            sum--;
            j=(j-count+1)%len2;
            count=0;
            i=0;

            while(B[j]!=A[0]){
                j=(j+1)%len2;
            }
        }
    }
    return count==len2;
}
```