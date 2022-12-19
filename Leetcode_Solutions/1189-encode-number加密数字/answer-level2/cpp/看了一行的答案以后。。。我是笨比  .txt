除了+1转二进制还可以把编码看成是完全二叉树左0右1 
```
class Solution {
public:
    string encode(int num) {
        string ret;
        pair<int,int> ans = search_pos(num);
        int pos_h = num - ans.first;
        itob(pos_h,ans.second,ret);
        return ret;
    }
    void itob(int x,int layer,string& ret)
    {
        int flag = 0;
        while(x!=0)
        {
            flag = x%2;
            x = x/2;
            if(flag)
                ret.insert(0,"1");
            else
                ret.insert(0,"0");
        }
        for(int j =ret.size();j<layer;j++)
        {
            ret.insert(0,"0");
        }
    }
    pair<int,int> search_pos(int value)
    {
        int layer = 0;
        int tmp = 0;
        int layer_value = 0;
        while(1)
        {
            tmp = layer_value*2+1;
            if(value>=layer_value&&value<tmp)
            {
                break;
            }
            layer_value = tmp;
            layer ++;
        }
        pair<int,int> ret;
        ret.first = layer_value;
        ret.second = layer;
        return ret;
    }
};
```
