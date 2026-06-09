### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了92.46%的用户
内存消耗 :9.6 MB, 在所有 C++ 提交中击败了97.92%的用户

我采用的是递归是思路。
首先初始的字符串的n个"()"的组合，比如n==3，则初始字符串是"()()()"
首先我们用一个向量arr保存右括号的位置，我的思路是，逐个右括号向右移，当所有右括号都在右半边时，那么就结束了。
PS:由于数组不能值传递，所以arr的数据类型我采用向量表示。
以n==3举例，arr数组元素变化是这样的
1，3，5
2，3，5
1，4，5
2，4，5
3，4，5

### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n<=0)
            return res;
        if(n==1)
        {
            res.push_back("()");
            return res;
        }
        string tmp="";
        for(int i=0;i<n;i++)
            tmp.append("()");
        vector<int> arr;
        for(int i=0;i<n;i++)
            arr.push_back(2*i+1);//arr保存右括号的位置
        f(n-2,arr,n-1,res);
        return res;
    }
    void f(int num,vector<int> arr,int end,vector<string> &res)//num是表示当前遍历到的第（num+1）个右括号在arr向量中的下标是num
    {
        while(arr[num]<arr[num+1])//如果两个右括号的位置没有重叠的
        {
            if(num==0)//当递归到最左（第一个）的右括号，则push_back字符串
            {
                int p=0,index=0;
                string r="";
                while(p<=end)
                {
                    if(index==arr[p])
                    {
                        r.push_back(')');
                        p++;
                    }   
                    else 
                    {
                        r.push_back('(');
                    } 
                    index++;
                }
                res.push_back(r);
            }
            else //还没有递归到最左（第一个）的右括号
            {
                f(num-1,arr,end,res);//递归调用前一个右括号
            }
            arr[num]++;//右括号右移
        }
    }
};
```