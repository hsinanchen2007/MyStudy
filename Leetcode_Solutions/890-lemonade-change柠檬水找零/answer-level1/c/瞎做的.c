### 解题思路
没有思路，干就完事儿了。

### 代码

```c

//盲猜贪心算法
bool lemonadeChange(int* bills, int billsSize){
int count5=0;
int count10=0;
int i=0;
bool flag=true;
for(i;i<billsSize;i++){
    if(bills[i]==5){
        count5++;
    }else if(bills[i]==10){
        count10++;
    if(count5>=1){
        count5--;
    }else{
flag=false;
break;
    }
    
    }else if(bills[i]==20){
        if(count10>=1){
            count10--;
        if(count5>=1){
            count5--;
        }else{
            flag=false;
            break;
        }
        }else if(count5>=3){
count5-=3;
        }else{
            flag=false;
            break;
        }


    }

}

return flag;

}
```