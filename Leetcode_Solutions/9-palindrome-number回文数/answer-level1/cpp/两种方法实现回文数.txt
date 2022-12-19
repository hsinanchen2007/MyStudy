1.
将每一个数取出来同时构成新的数，将最后得到的数和最初输入的数比较。
注意：这里可能超出int的限制，所以采用long int。
```
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        if(x==0)return true;
       long int sum=0;
       int num=x;
        for(;x!=0;x/=10)
        {
            sum=sum*10+x%10;
        }
        if(sum==num)return true;
        return false;
    }
};


```
2.将每个数取出后单独存在数组中，再从两端比较数字是否相等。

```
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        if(x==0)return true;
        int num[12],i,count=0;
        for(i=1;x!=0;i++){
            num[i]=x%10;
            x/=10;
        }
        int m=--i;bool flag=true;
        for(int j=1;j!=i/2+1;j++){
            
            if(num[j]!=num[m]){
                flag= false;
                break;}
            m--;
        } return flag;
}
    };


```
