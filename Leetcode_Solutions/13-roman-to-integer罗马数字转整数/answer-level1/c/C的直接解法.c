### 解题思路
根据罗马数转换的定义：
若第一个数大于第二个数，则直接将第一个数加入sum
若第一个数小于第二个数，则将第二个数减去第一个数的值加入sum

本解答，使用很不划算的switch函数来调用函数，并且还使用了重复的计算，
其他方法有散列表和定义一个结构，之类的。用来存罗马数字与数字互换的信息

### 代码

```c
/*
定义七种字符表示的含义，之后根据输入，依次判断，
若i大于i+1，则直接取该值加入sum中
若i小于i+1，则使用i+1的值减去i的值加入sum中
*/
int getnum(char a){
    switch(a){
        case 'I':
            return 1;
            //break;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int romanToInt(char * s){
    int i,a,b,n,sum=0;
    while(s[i]){
        i++;
        n++;
    }//为什么每次不能直接用s[i]来作为判断，而非要加上数s的个数的这段代码。

    for(i=0;i<n-1;i++){
        a=getnum(s[i]);
        b=getnum(s[i+1]);
        if(a==0 || b==0)
            return 0;
        if(a>=b)
            sum+=a;
        else{
            sum+=(b-a);
            if(i<n-1)
                i++;
            else
                break;
        }
    }

    if(i<n){
        a=getnum(s[i]);
        sum+=a;
    }

    return sum;
}

```