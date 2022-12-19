![image.png](https://pic.leetcode-cn.com/30e10ac920c10f13143a3c793ecebaeff9b385dad1dadebcd0895f249daaed41-image.png)
解题思路：正反各遍历一次，记录上一个C到S[i]的距离，两次遍历取最小即可。
```
    vector<int> shortestToChar(string S, char C) {
        int n = S.size();
        vector<int> res(n,n);
        int lastC = -n;
        for(int i=0;i<n;i++){
            if(S[i]==C)lastC = i;
            res[i] = min(res[i],i-lastC);
        }

        for(int i=lastC-1;i>=0;i--){
            if(S[i]==C)lastC = i;
            res[i] = min(res[i],lastC-i);
        }

        return res;
    }
```
