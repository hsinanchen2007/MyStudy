### 解题思路
![Snipaste_2020-03-10_15-36-49.png](https://pic.leetcode-cn.com/936a8f2cd90fb0eb57a0598f561c9c872c242a2e91c6ad36bcc11175edb6e0dc-Snipaste_2020-03-10_15-36-49.png)
分别写出计算1个数和判断素数的子函数，然后一次遍历【L,R】内所有数。

### 代码

```c
bool isPrime(int n){
    if(n==2||n==3){
        return true;
    }else if(n==1||n%2==0){
        return false;
    }else{
        for(int i=3;i*i<=n;i+=2){
            if(n%i==0) return false;
        }
        return true;
    }
}
int countOnes(int n){
    int sum=0;
    while(n!=0){
        if(n%2==1) sum++;
        n/=2;
    }
    return sum;
}
int countPrimeSetBits(int L, int R){
    int sum=0;
    int i;
    for(i=L;i<=R;i++){
        if(isPrime(countOnes(i))){
            sum++;
        } 
    }
    return sum;
}
/*
int Binary( int num ){
    int sum= 0;
    while(num>0){
        if(num%2==1 ){
            sum++;
        }
        num/=2;
    }
    return sum;
}

int isPrime( int num ){

    if(num==2){
        return 1;
    }
    if(num==1||num%2==0){
        return 0;
    }
    for( int i=3;i*i<=num;i+=2){
        if(num %i==0){
            return 0;
        }
    }
    return 1;
}

int countPrimeSetBits( int L , int R ){
    int count = 0;

    for( int i = L ; i <= R ; i++ ){

        if( isPrime( Binary( i ) ) ){

            count++;

        }

    }

    return count;

}*/

```