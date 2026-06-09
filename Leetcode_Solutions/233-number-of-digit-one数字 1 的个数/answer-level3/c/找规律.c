### 解题思路
统计出每一的位上1出现的个数，累加起来就是1出现的总个数。
num = 31456
现在统计百位上1出现的次数。
将num分成两部分（根据百位），a = 314，b=56。
此时a的个位是4（即num的百位是4），此时该为出现1的次数为：31*100次。
假设a的个位数是x，
当x > 1时，百位出现1的次数：(a / 10 + 1) * 100
当x = 1时，百位出现1的次数：(a / 10 ) * 100 + b + 1 （0~b）
当x = 0时，百位出现1的次数：(a / 10 ) * 100 
根据规律，可以分为两类，一类x >= 2；一类0 <= x < 2，用一个表达式写出：
(a+8) / 10 * 100 ，再将x = 1的特殊情况写入表达式：(a+8) / 10 * 100 + (a % 10 == 1 ) * (b + 1)

### 代码

```c
int countDigitOne(int n){
    int a,b,count=0;
    long i;
    if(n==0) return 0;
    for(i=1;i<=n;i=i*10){
        a=n/i;
        b=n%i;
        count=(count+(a+8)/10*i+(a%10==1)*(b+1));
    }
    return count;
}


```
## 改进后的！!
```
int countDigitOne(int n){
    int count=0;
    long l=0,cur=0,h=0,num=1;
    while(n/num !=0){
        l=n%num;
        cur=(n/num)%10;
        h=n/(num*10);
        if(cur<2){
            count += h*num;
            if(cur==1){
                count += l+1;
            }
        }else{
            count += (h+1)*num;
        }
        num=num*10;
    }
    return count;
}
```
