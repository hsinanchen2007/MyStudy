### 解题思路
在小于10的数中只有1和7是快乐数


### 代码

```c
bool isHappy(int n){
        while(1){
            if(n<10){
                if(n==1||n==7)return true;
                else return false;
            }
            int sum=0;
            while(n!=0){
                    sum=sum+(n%10)*(n%10);
                    n=n/10;
            }//while
            n=sum;
        }
       
}

//在小于10的数中只由1和7是快乐数
```