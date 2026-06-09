从后向前,相加对应位的数,并加上前两位运算得到的进位
若其中有一个数已经用完了,则用0来代替运算
如果最后还有进位,则在头部插入1
代码如下
```cpp
    string addStrings(string num1, string num2) {
        int m=num1.size();
        int n=num2.size();
        int i=m-1;
        int j=n-1;
        int k=max(m,n);
        int carry=0;
        string ans(k,'0');
        while(i>=0||j>=0){
            int n1=i>=0?num1[i]-'0':0;
            int n2=j>=0?num2[j]-'0':0;
            int sum=n1+n2+carry;
            ans[--k]=sum%10+'0';
            carry=sum/10;
            i-=1;
            j-=1;
        }
        if(carry)
            ans="1"+ans;
        return ans;
    }
```