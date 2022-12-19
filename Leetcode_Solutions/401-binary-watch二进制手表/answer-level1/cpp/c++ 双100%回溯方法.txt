### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        int time[10] = {1, 2, 4, 8, 16, 32, 1, 2, 4, 8};
        bool visited[10] = {false, false, false, false, false, false, false, false, false};
        vector<string> ret;
        dfs(time, visited, ret, 0, 0, num);
        return ret;
    }

    void dfs(int time[], bool visited[], vector<string> &ret, int h, int m, int n, int t=0){ 
        if (n==0){
            string ts = to_string(h);
            if (m<10){
                ts += (":0"+to_string(m));
            }
            else {
                ts += (":"+to_string(m));
            }
            ret.push_back(ts);
        }
        else{
            for(int i=t; i<10; i++){
                if(!visited[i]){
                    visited[i] = true;
                    if (i>=6 && h+time[i] < 12){
                        dfs(time, visited, ret, h+time[i], m, n-1, i+1);
                    }
                    if(i<6 && m+time[i] < 60){
                        dfs(time, visited, ret, h, m+time[i], n-1, i+1);
                    }
                    visited[i] = false;
                }
            }
        }
    }
};
```

![image.png](https://pic.leetcode-cn.com/d5895f45de138e138413b0c4e05f2a28b59f3846b1ce7dc838aae02c299fde31-image.png)
