
```
#include<cmath>
class Solution {
public:
    void cal_rc(int k,int& k_row,int& k_col)  //计算k所在的行和列
    {

        if(k==1||k==2||k==3)
        {
            k_row=1;
            if(k==1)
            {
                k_col=1;
                return;
            }
            else if(k==2)
            {
                k_col=2;
                return;
            }
                
            else
            {
                k_col=3;
                return;
            }
                
        }
        else if(k==4||k==5||k==6)
        {
            k_row=2;
            if(k==4)
            {
                k_col=1;
                return;
            }
            else if(k==5)
            {
                k_col=2;
                return;
            }
            else
            {
                k_col=3;
                return;
            }
                      
        }
        else if(k==7||k==8||k==9)
        {
            k_row=3;
            if(k==7)
            {
                k_col=1;
                return;
            }
            else if(k==8)
            {
                k_col=2;
                return;
            }
            else
            {
                k_col=3;
                return;
            }
                      
        }
    }
    
    
    
    bool isValid(int k,int m,vector<int> &used)  //上一个是k，下一个是m，是否合法
    {
        if(used[m]==1)  //若这个位置被选了，则一定不合法，外围排除了自身
            return 0;
        
        //这个位置没有被选，下面继续分析 以两个数的行差和列差为基础
        int k_r;
        int k_c;
        int m_r;
        int m_c;
        cal_rc(k,k_r,k_c);  //k的行和列 从1开始
        cal_rc(m,m_r,m_c);  //m的行和列
        //计算行差和列差
        //计算行差和列差 不可能全为0
        int r_diff = abs(k_r-m_r);
        int c_diff = abs(k_c-m_c);
        //(行差，列差) (0,1) (1,0) (1,1) (1,2) (2,1)  可以发现，如果行差或者列差中有1,那么必定合法
        if(r_diff==1 || c_diff==1) 
            return 1;
        //行差列差均为2，表示两个数在对角，看中间的那个数即可,固定是第5号元素
        else if(r_diff==2 && c_diff==2)
        {
            if(used[5]==1)
                return 1;
            else
                return 0;
        }
        //仅余两种情况(2,0) (0,2) 这两种情况：两个元素同列，两个元素同行
        else
        {
            if(used[(k+m)/2]==1)
                return 1;
            else
                return 0;
        }
          
    }
    
    
    
    
    int dfs(int k,int length,vector<int> &used) //从k出发，长度为length的可行方案数
    {

        
        if(length==1)
            return 1;   //从k出发，长度为1的可行方案数为1，为自身
        
        used[k]=1;     //k设为被选
        int num = 0;   //从k出发，长度为length的可行方案数
        for(int m=1;m<=9;m++)       //依次看下一个位置是否可以去
            if(isValid(k,m,used))   //若下一个位置为m是合法的
                num += dfs(m,length-1,used);
        used[k]=0;
        return num;
    }
    
    
    
    
    
    int countPatterns(int length)
    {
        vector<int> used(10,0);
        int num = 0;                   //长度为length的可行方案数
        for(int k=1;k<=9;k++)          //依次计算从k出发，长度为length的可行方案数
            num+=dfs(k,length,used);   //
        return num;  //长度为length的可行方案数
    }
    
    

    int numberOfPatterns(int m, int n) {
        int result=0;
        for(int length=m;length<=n;length++)
        {
            result += countPatterns(length);  //长度为length的可行方案数
        }
        return result;
    }
};
```
