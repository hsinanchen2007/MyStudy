我们一步一个脚印走，步长规律1,1,2,2,3,3,4,4....其中东和南的步长相同，西和北的步长相同，只要逐一判断是否在规定区域内就行了~
```
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        /*已经过的个数*/
        int num = 1;
        
        vector<vector<int>> p;
        vector<int> temp(2);
        temp[0] = r0;
        temp[1] = c0;
        p.push_back(temp);
        
        /*移动步长*/
        int step = 1;
        
        while(num < R * C)
        {
            /*朝东走*/
            int n = 1;
            while(n <= step)
            {
                c0++;
                if(Judge(r0, c0, R, C))
                {
                    temp[0] = r0;
                    temp[1] = c0;
                    p.push_back(temp);
                    num++;
                }
                n++;
            }
        
            /*朝南走*/
            n = 1;
            while(n <= step)
            {
                r0++;
                if(Judge(r0, c0, R, C))
                {
                    temp[0] = r0;
                    temp[1] = c0;
                    p.push_back(temp);
                    num++;
                }
                n++;
            }
        
            /*步长加1*/
            step++;
        
            /*朝西走*/
            n = 1;
            while(n <= step)
            {
                c0--;
                if(Judge(r0, c0, R, C))
                {
                    temp[0] = r0;
                    temp[1] = c0;
                    p.push_back(temp);
                    num++;
                }
                n++;
            }
        
            /*朝北走*/
            n = 1;
            while(n <= step)
            {
                r0--;
                if(Judge(r0, c0, R, C))
                {
                    temp[0] = r0;
                    temp[1] = c0;
                    p.push_back(temp);
                    num++;
                }
                n++;
            }
        
            /*步长加1*/
            step++;
        }
        return p;
    }
    
    /*判断是否在规定区域内*/
    bool Judge(int x, int y, int r, int c)
    {
        return x >= 0 && y >= 0 && x < r && y < c ? true : false;
    }
};
```
