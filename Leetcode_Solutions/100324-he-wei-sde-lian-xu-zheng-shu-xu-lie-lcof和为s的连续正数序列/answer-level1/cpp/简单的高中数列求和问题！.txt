### 解题思路
解：
 1)设首项为a1,公差为1，项数为n，则n项的和为：
 sum = (首项+末项)*项数/2 = (a1+(a1+n-1))*n/2

 2)满足上述方程均为所求的结果，对式子变形：
 a1 = (2*sum/n - n + 1) / 2 (注意，分母的2不能放到括号里面，sum/n可能出现小数)

 3)对n进行for循环，最小的n=2，理论上最大的n应当满足首项a1=1，即2*sum = nXn + n
  所以退出循环的条件为 nXn + n <= 2*sum

核心代码如下：
```
vector<vector<int>> result;
vector<int> temp;
    for(int n=2;n*n+n<=2*target;n++){
        float t = (2.0*target/n-n+1)/2;
        cout<<t<<endl;
        if(int(t)==t){
            int sum = 0;
            int i = t;
            while(sum!=target){
                temp.emplace_back(i);
                sum += i;
                i++;
            }
            result.insert(result.begin(),temp);
            temp.clear();
        }
    }
```

  

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> result;
        vector<int> temp;
        for(int n=2;n*n+n<=2*target;n++){
            float t = (2.0*target/n-n+1)/2;
            cout<<t<<endl;
            if(int(t)==t){
                int sum = 0;
                int i = t;
                while(sum!=target){
                    temp.emplace_back(i);
                    sum += i;
                    i++;
                }
                result.insert(result.begin(),temp);
                temp.clear();
            }
        }
        return result;
    }
};
```