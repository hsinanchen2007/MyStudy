变量有点多，我自己都不得不写点注释记一下每个变量代表啥……
```
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res=0;
        int t1=-1;//水果1种类
        int t2=tree[0];//水果2种类
        int z=0;//最后一个切换点
        int p=0;//当前窗口起点
        int n=tree.size();

        for(int i=1;i<n;++i)
        {
            if(tree[i]==t2)
            {

            }
            else if(t1==tree[i]||t1==-1)
            {
                t1=t2;
                t2=tree[i];
                z=i;
            }
            else
            {
                res=max(res,i-p);
                t1=t2;
                t2=tree[i];
                p=z;
                z=i;
            }
        }
        res=max(res,n-p);

        return res;
    }
};
```
