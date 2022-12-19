### 解题思路
第一易错点：找零分为两种：5和10，唯一需要分析一下的就是20的找零：5和10需要相互补足，
用10补5是显然的，但是用5来补10的情况容易被疏漏掉
### 代码

```c
bool lemonadeChange(int* bills, int billsSize){
    int res_5 = 0;
    int res_10 = 0;
    bool is_change = true;
    for(int i = 0; i < billsSize; i++){
        if(bills[i] == 5){
            res_5++;
        }else if(bills[i] == 10){
            res_10++;
            res_5--;
        }else if(bills[i] == 20){
            if(res_10 > 0){
                res_10--;
                res_5--;    
            }else{
                res_5-=3;
            }
            
        }
        if((res_5<0)||(res_10<0)){
            is_change = false;
            break;
        }
    }
    return is_change;
}
```