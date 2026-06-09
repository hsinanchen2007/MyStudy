### 解题思路
![Snipaste_2020-03-12_17-43-01.png](https://pic.leetcode-cn.com/1475a30da93a861acfe72ecd0000966ea7aacbd95bb121b68bdd0cf89c202773-Snipaste_2020-03-12_17-43-01.png)
首先第一张必须为5元。然后分别统计5元和10元的数量，每次找零优先用10元的。

### 代码

```c
bool lemonadeChange(int* bills, int billsSize){
    if(billsSize==0) return true;
    if(bills[0]!=5) return false;//首张必须为5
    int cout5=1,count10=0;
    int i;
    int sum=count10*10+cout5*5;
    for(i=1;i<billsSize;i++){
        if(bills[i]==5){//5元不需找零
            cout5++;
            sum+=5;
        }else if(bills[i]==10){//10元只能用5元找
            if(cout5==0){
                return false;
            }else{
                cout5--;
                count10++;
                sum+=5;
            }
        }else if(bills[i]==20){//20元
            if(cout5==0||sum<15){//20元找零至少用一张5元，且5元和10元总和不能少于15
                return false;
            }else if(count10==0&&cout5<3){//只用5元找则至少需3张
                return false;
            }else{
                if(count10>0){//有10元用10元找
                    count10--;
                    cout5--;
                }else{
                    cout5-=3;
                }
                sum-=15;//可找零的钞票总和少了15
            }
        }
    }
    return true;
}
```