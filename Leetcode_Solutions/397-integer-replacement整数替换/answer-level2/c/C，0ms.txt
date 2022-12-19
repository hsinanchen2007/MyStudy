### 解题思路
如果是偶数，直接/2；
如果是奇数：如果+1能被4整除则+1；否则-1.特殊情况是3

### 代码

```c
int integerReplacement(int n){
    int i=0;
    long temp=n;
    while(1!=temp){
        if(temp%2==0){
            temp/=2;
            i++;
        }
        else if(3==temp){            
            temp=2;
            i++;
        }
        else{
            if((temp+1)%4==0){
                temp+=1;;
                i++;
            }
            else{
                temp-=1;
                i++;
            }
        }
    }
    return i;
}
```