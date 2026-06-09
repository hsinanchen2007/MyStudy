### 解题思路
从2开始依次找出所有满足条件的等差数列项数，然后计算出首项

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target){
        int n=2; //等差数列项数，从2开始
        vector<vector<int>> results;
        while(n*(n+1)<=2*target)
        {
            if((2*target-n*(n-1))%(2*n)==0)
            {
                int a=(2*target-n*(n-1))/(2*n); //根据项目n计算出首项a
                vector<int> result(n);
                for(int i=0;i<n;++i)
                {
                    result[i]=a;
                    a++;
                }
                //在首部插入数组
                results.insert(results.begin(),result);
            }                
            n++;
        }
        return results;
    }
};
```