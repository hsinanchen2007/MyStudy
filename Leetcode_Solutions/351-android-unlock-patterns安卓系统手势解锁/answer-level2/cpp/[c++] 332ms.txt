### 1、采用dfs深度遍历即可。
### 2、求出经过N个点的手势的数量，计算从m到n个点的手势数目和即可。
### 3、最关键的一点是如何判断从点x到下一个点y的判断，详细参考代码如下：
```
        /*if point y has been visited*/
       if(used[y]){
            return false;
        }
        /*如果点x与点y为对角线上的两个点，且对角线中间的点未被访问过，则点x不能到达点y*/
        if(!used[5]&& x + y == 10){
            return false;
        }
        /*如果点x与点y为同一行上的两个点，且行中间的点未被访问过，则点x不能到达点y*/
        if(!used[min(x,y)+1]&&abs(x-y) == 2 && (x-1)/3 == (y-1)/3){
            return false;
        }
       /*如果点x与点y为同一列上的两个点，且列中间的点未被访问过，则点x不能到达点y*/
        if(!used[min(x,y)+3]&&abs(x-y) == 6 && (x-1)%3 == (y-1)%3){
            return false;
        }
```


```
class Solution {
public:
    bool isValid(int x,int y,vector<bool> & used){
        if(used[y]){
            return false;
        }
        /*sllash*/
        if(!used[5]&& x + y == 10){
            return false;
        }
        /*row*/
        if(!used[min(x,y)+1]&&abs(x-y) == 2 && (x-1)/3 == (y-1)/3){
            return false;
        }
        /*colum*/
        if(!used[min(x,y)+3]&&abs(x-y) == 6 && (x-1)%3 == (y-1)%3){
            return false;
        }
        
        return true;
    }
    
    int dfs(int x,vector<bool>  & used,int count){
        int res = 0;
        
        if(count < 0){
            return 0;
        }else if(count == 0){
            return 1;
        }
        
        for(int i = 1;i <= 9; ++i){
            if(!used[i]&&isValid(x,i,used)){
                used[i] = true;
                res += dfs(i,used,count-1);
                used[i] = false;
            }
        }
        
        return res;
    }
    
    int countPatterns(int m){
        int ans = 0;
        vector<bool> used(10,false);
        if(m <= 0){ return 0;}
        
        for(int i = 1;i <= 9; ++i){
            used[i] = true;
            ans += dfs(i,used,m-1);
            used[i] = false;
        }
        
        return ans;
    }
    
    int numberOfPatterns(int m, int n) {
       int ans = 0;
       for(int i = m;i <= n; ++i){
           ans += countPatterns(i);
       }
       return ans;
    }
};
```