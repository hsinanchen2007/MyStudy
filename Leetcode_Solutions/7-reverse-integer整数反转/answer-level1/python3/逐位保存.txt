### 解题思路
此处撰写解题思路
本题有两种方法：
1.转化为string然后进行反向输出；
2.采用除以10取余，逐位输出。

代码思路：
首先考虑负数情况，取绝对值，并逐位保存；注意判断条件，取余>=0且除以十大于0.1；
然后考虑边界情况即可。
### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        ans = 0;
        flag = 0;
        
        if x<0:
            x = x*(-1);
            flag=1;
            
            
        while((x%10>=0 )&(x/10>=0.1)):
            
            ans = ans*10+int(x%10);
            x = x/10;     
        if flag==1:
            ans = -ans;        


        if (ans<=(1<<31)-1) & (ans>= -(1<<31) ) :
            return ans;
        else:
            return 0;
```