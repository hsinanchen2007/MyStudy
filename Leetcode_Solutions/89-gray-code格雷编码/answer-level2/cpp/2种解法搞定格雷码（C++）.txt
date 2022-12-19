两种方法：
1、搞清楚格雷编码的生成过程
2、镜面反射法

```C++
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> rslts;
        int ntmp = pow(2, n);
        for(int i=0;i<ntmp;i++)
        {
            rslts.push_back(i ^ i>>1);
        }

        return rslts;
    }
};
```

```C++
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> rslts;

        rslts.push_back(0);
 
        for(int i=1; i <= n; i++)
        {
            //int tmp = pow(2, i-1);
            int tmp = 1 << (i - 1);
            for(int j = rslts.size() - 1; j >= 0; j--)
            {
                rslts.push_back(rslts[j] + tmp);
            }
        }

        return rslts;
    }
};
*/
```
