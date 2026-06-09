### 解题思路
$\LaTeX{}$:优化的$bfs$
&emsp;我们知道一共有$3$种情况

$$\left\{\begin{array}{l}
i \rightarrow i - 1 &①\\
i \rightarrow i + 1 &②\\
i^{\curvearrowright}loc(have\; same\;vlaue)&③
\end{array}\right.$$

&emsp;但是直接一步步来就会超时，因为其中有很多连续重复的$eg:7,7,7,7\cdots 23,23,23$类似这种，实际上这种**连续重复的都可以看为是一个**，这个需要你稍微仔细考虑下。
因为我也是个小白，所以我的方法挺笨的：
- 第一步$\Rrightarrow$初始化1：重点是初始化一个$int\rightarrow vector<int>$的映射，用来存储位置相同的值的$index$
- 第二步$\Rrightarrow$预处理：我们把**连续重复**的剔除，并记录相同$value$的索引
- 第三步$\Rrightarrow$初始化2：初始化一个$visit$数组用于记录是否访问，以及初始化一个队列进行$bfs$
- 第四步$\Rrightarrow$进行$bfs$：
$$\left\{\begin{array}{l}
i \rightarrow i - 1 &数组不会越界且未访问&①\\
i \rightarrow i + 1 & 同上&②\\
i^{\curvearrowright}loc(have\; same\;vlaue)&遍历你的map[arr[i]]入队vlaue相同且未访问&③
\end{array}\right.$$
&emsp;**值得注意的是在第四部中,每次都得确定循环的次数，而循环的次数就等于队列的长度:**
&emsp;比如我这一步有两个新位置入队，则下一次我必须循环两次因为我得模拟这两个新位置分别对下一次探索的过程，这也是为什么代码中$lop = Q.size()$
&emsp;我认为是动态规划，但是很不幸太菜了没写出来 $TAT$
### 代码


```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
        // initialize 1
        int ans = 0, c = 0, lop = 0; // ans -> answer, c -> count, lop -> the number of loop
        vector<int> v; // the new vector without the serial number 
        map<int, vector<int>> m; // the map to record the same value index
        m.clear(); // clear the map
        
        // pretreatment
        for (int i = 0; i < arr.size(); ++ i){
            if (i && i != 1 && arr[i] == arr[i - 1]) continue; // 首先i != 0 很容易理解，但是会出现初始位置和之后位置相同的情况比如7,7,7,11 这时候我们不能认为他们相同了
            else{
                v.push_back(arr[i]); // push arr[i]
                m[arr[i]].push_back(c); // push the same value;
                ++ c; // 因为跳过了一些数会导致索引的变化所以用c来计数
            }
        }
        
        // initialize 2
        queue<int> Q;
        vector<bool> vis (v.size()+1, false);
        Q.push(0); vis[0] = true;
        
        // bfs
        while(!Q.empty()){
            lop = Q.size(); // determine the number of loop
            for(int j = 0; j < lop; ++ j){
                int tmp = Q.front(); Q.pop();
                if(tmp == v.size() - 1) return ans; // find the destination, over
                
                if(tmp > 0 && !vis[tmp - 1]){ // tmp -= 1
                    Q.push(tmp - 1);
                    vis[tmp - 1] = true;
                }
                if(tmp < v.size() - 1 && !vis[tmp + 1]){ // tmp += 1
                    Q.push(tmp + 1);
                    vis[tmp + 1] = true;
                }
                for(int i = 0; i < m[v[tmp]].size(); ++ i){ // note that it is m[v[tmp]] rather than m[tmp]
                    if(!vis[m[v[tmp]][i]]) { // go the same value location
                        Q.push(m[v[tmp]][i]);
                        vis[m[v[tmp]][i]] = true;
                    }
                }
            }
            ++ ans; // next step;
        }
        
        return ans;
    }
};
```