### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/56eaa0381121371d61d3b7757fd7a9a4bab7b20413431592d7411b15c150b816-image.png)

### 代码

```c
bool lemonadeChange(int* bills, int billsSize){
    int cnt5=0,cnt10=0,cnt20=0,i;
    for(i=0;i<billsSize;i++){
        if(bills[i]==5) cnt5++;
        else if(bills[i]==10){
            if(cnt5>0) cnt5--,cnt10++;
            else return false;
        }
        else{
            if(cnt10>0&&cnt5>0) cnt5--,cnt10--,cnt20++;
            else if(cnt5>=3) cnt5-=3,cnt20++;
            else return false;
        }
    }

    return true;
}
```