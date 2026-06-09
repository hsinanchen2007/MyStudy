![QQ图片20191031155519.png](https://pic.leetcode-cn.com/0465d7a490001ff055a5cba7c5b8e4de6b19d17554c85b31fe1cb50594a29adb-QQ%E5%9B%BE%E7%89%8720191031155519.png)


```
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        vector<int> pos(n);
        for(int i=0;i<n;++i)
        {
            pos[row[i]]=i;
        }

        int res=0;
        for(int i=0;i<n;i+=2)
        {
            int tofind= (row[i] & 1)?row[i]-1:row[i]+1;
            if(row[i+1]==tofind)continue;
            swap(row[i+1],row[pos[tofind]]);
            swap(pos[tofind],pos[row[pos[tofind]]]);
            ++res;
        }
        
        return res;
    }
};
```
