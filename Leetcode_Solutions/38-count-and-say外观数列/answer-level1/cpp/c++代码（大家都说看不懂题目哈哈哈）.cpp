### 解题思路
此处撰写解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.6 MB, 在所有 C++ 提交中击败了80.78%的用户
### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
	    int i,j,count=1;
        string a1,a2;
        a1="1";
        for(i=0;i<n-1;i++)
        {
            int l1=a1.size();
            for(j=0;j<l1;j++)
            {
                if(a1[j]==a1[j+1])
                    count++;
                else
                {
            	    a2+=count+'0';
            	    a2+=a1[j];
                    count=1;
                }
            }
            a1=a2;
            a2="";
        }
        return a1;
    }
};
```