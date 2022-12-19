### 解题思路
1. 设置两个找零盒, 一个放五元的一个放十元的
2. 由于5元的找零能力更强, 于是优先消耗十元找零
3. 如果支付的是五元, 直接存入找零盒count_5
4. 如果支付的是十元, count_5--, count_10++
5. 如果支付的是二十元, 优先count_10--,count_5--, 其次考虑count_5-=3
6. 若全部找零方式都无法使用(某个必需的找零盒为空), 则返回False

### 代码

```c
bool lemonadeChange(int* bills, int billsSize){
    int count_5 = 0;
    int count_10 = 0;
    
    for (int i=0; i<billsSize; i++){
        if (bills[i] == 5){
            count_5++;
        }
        else if (bills[i] == 10){
            if (count_5 != 0){
                count_5--;
                count_10++;
            }else{
                return false;
            }
        }else{
            if (count_10 != 0 && count_5 != 0){
                count_5--;
                count_10--;
            }
            else if(count_5 >= 3){
                count_5 -= 3;
            }else{
                return false;
            }
        }
    }
    return true;
}
```