### 解题思路
采用暴力破解的方法，遍历1到N的每一个数字，判断是否是好数；
判断方法就是：
1.如果数字中存在3，4，7那肯定不是好数； //代码中用n==0来判断
2.不存在3，4，7且存在2，5，6，9那肯定是好数；//代码中用flag来判断
3.如果3，4，7，2，5，6，9都不存在的话，那么肯定不是好数
# 执行效果
执行用时 :4 ms, 在所有 C++ 提交中击败了79.63%的用户
内存消耗 :5.9 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int rotatedDigits(int N) {
        int ans=0;
        for(int i=1;i<=N;i++)
        {
            bool flag=false;
            int n=i; //我们会对n进行改动，所以不要动i
            while(n)
            {
                int res=n%10;
                if(res==3 || res==4 || res==7)break;
                if(res==2 || res==5 || res==6 || res==9)flag=true;
                n=n/10;
            }
            if(flag&&n==0)ans++;
        }
        return ans;
    }
};
```