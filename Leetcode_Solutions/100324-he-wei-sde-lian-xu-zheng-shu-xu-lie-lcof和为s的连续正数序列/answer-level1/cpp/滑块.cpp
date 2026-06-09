### 解题思路
利用滑块平移慢慢匹配

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) 
    {
        vector<vector<int>> result;
        vector<int> _result;
        int MAX= 0;   //最大连续可能数字个数
        int sum= 0;  
        int j;   

        for(MAX=1;sum<target;MAX++)     //得到最大滑块
        {
            sum+=MAX;
        }

        for(int i=MAX; i>=1; i--)      //滑块大小
        {           
            j=1;                        //滑块元素
            sum=0;                     
            while(sum<target)           //滑块和与target比较
            {
                sum=get_sum(j,j+i);
                j++;
            }
            if(sum==target)             //匹配成功
            {
                j-=1;
                for(int k=j;k<=(i+j);k++)
                {
                    _result.push_back(k);
                }
                result.push_back(_result);
                for(int k=j;k<=(i+j);k++)
                {
                    _result.pop_back();
                }
            }                 
        }
        return result;
    }
    
private:
    int get_sum(int a, int b)
    {
        int sum=0;
        for(int i=a; i<=b; i++)
        {
            sum+=i;
        }
        return sum;
    }

};
```