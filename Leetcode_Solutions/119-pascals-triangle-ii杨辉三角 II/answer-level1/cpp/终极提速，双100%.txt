根据杨辉三角的计算特点，可以用一行数据来存储，直接在这行数据上计算得到下一行
在这里的计算，如果从左向右，需要临时变量来存储前一个元素
所以这里采用的从右向左计算，可以避免使用临时变量（优化一）
杨辉三角每一行是对称的，所以只需要求解一半的值即可（优化二）
这两个优化一起上，稳定双100%!
![image.png](https://pic.leetcode-cn.com/4faa72eb89b93b7b8cbe4bfc00cfbba6b238ee4577df27a760212e09488e85c0-image.png)

```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for(int i=0;i<=rowIndex;i++){
            res.push_back(1);
            int mid = (i+1)>>1;
            for(int j=i-1;j>=mid;j--)
                res[j] += res[j-1];
            for(int k=1;k<mid;k++)
                res[k] = res[i-k];
        }

        return res;
    }
};
```

