### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int>result;
        result.push_back(1); //头给它置为1
        int a=1;  //头元素
        int flag=1;
        int temp=k;  //记一个临时结点
        int N =n;
        while(k>0)
        {
            a=a+k*flag;
            result.push_back(a);
            flag=-flag;
            k--;
            n--;
        }
        if(n-1>0)
        {
            for(int i=temp+1;i<N;i++)
            {
                result.push_back(i+1);
            }
        }
        return result;
    }
};
```参考的数学模型，比如（1,2，3,4,5,6）,k=4，我们只需要依次每个元素放1+4,1+4-3,1+4-3+2,1+4-3+2-1即（1,5,2,4,3）,然后剩余元素补上即可