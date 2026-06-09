```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex + 1, 1);
        //从第2行开始遍历
        for(int i = 2; i <= rowIndex; i++)
        {
            for( int j = 1; j < i; j++)  //这里从大到小，要不然会新数会覆盖旧数
                v[j] = v[j-1] + v[j];
        }
        return v;
    }
};
```
