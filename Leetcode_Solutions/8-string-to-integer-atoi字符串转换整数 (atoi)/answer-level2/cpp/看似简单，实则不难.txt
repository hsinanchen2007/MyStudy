### 解题思路
~~才发现int和char之间的转换是差了48的~~，而且INT_MAX和INT_MIN的判断每一步都要做，因为系统给你的数可能很离谱，怎么都溢出
- 不是int和char之间的转换差了48，是string类型的对象中的某个元素当做char调用的时候直接赋值给int是比表面上的数大48
- 比如string a=42  int b=a[0] cout<<b;  不会输出4，而是52。52=4+48.
![image.png](https://pic.leetcode-cn.com/358b72980dab17e71f42f79c3c201a2f8486ae1a3196e3b334c56cb029b70335-image.png)

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
       long ans=0,k=1,j=str.size();
       
       for(int i=0;i<str.size();i++)
       {
           
           if(str[i]==' ') continue;
           
           if(str[i]=='+') 
           {
               j=i;
               break;
           }
           if(str[i]=='-')
           {
               j=i;
               k=-1;
               break;
           }
           if(str[i]>='0'&&str[i]<='9') 
           {
               j=i-1;
               break;
           }
           else return 0;
       } 
       for(int i=j+1;i<str.size();i++)
       {
           if(str[i]>'9'||str[i]<'0') break;
           else{
               
               ans*=10;
               ans+=str[i]-48;
               if(ans*k>INT_MAX) return INT_MAX;
               if(ans*k<INT_MIN) return INT_MIN;
           }
       }
       ans*=k;
       
       return ans;
    }
};
```