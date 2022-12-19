### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        vector<int> arr={1};  //n=1情况
        vector<int> arra;
        while(n>1)
        {
            int count=0;//计数
            for(int i=0;i<arr.size();i++)
            {
                count++;
                //判断数字发生变化或到达末尾
                if(i==arr.size()-1 || (i<arr.size()-1 && arr[i+1]!=arr[i]))/
                {
                    arra.push_back(count); //添加该数字的个数
                    arra.push_back(arr[i]); //添加该数字
                    count=0;
                }
            }
            arr=arra; //迭代
            arra.clear();
            n--;
        }
        //int数组->string
        string sum;
        for(int i=0;i<arr.size();i++)
        {
            sum+=std::to_string(arr[i]);
        }
        return sum;
    }
};
```