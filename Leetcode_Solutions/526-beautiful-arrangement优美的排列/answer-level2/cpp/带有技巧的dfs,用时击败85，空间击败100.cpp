### 解题思路
最开始dfs的第一步从最后面位置开始找，减少dfs的起点数
![image.png](https://pic.leetcode-cn.com/2397231535149af9086803d79f2dd745ff98d834d44fedbca7362181a750d99b-image.png)

### 代码

```cpp
class Solution {
public:
    int count=0;
    int len;
    int vis[16];
    int countArrangement(int N) {
        len=N;
        //从最后一个e位置开始会少走很多路径
        for(int i=N;i>=1;i--){//放在最后一个位置上的数
            if(N%i==0){
                vis[i]=1;
                dfs(i,N);
                vis[i]=0;
            }
        }
        return count;
    }

    void dfs(int n,int i){
        //cout<<"数:"<<n<<" 位置:"<<i<<endl;
        if(n%i!=0&&i%n!=0) return ;
        if(i==1) {count++;}
        i--;//当前位置
        for(int j=len;j>=1;j--){//当前遍历待选的数
            if(vis[j]==0&&(j%i==0||i%j==0)){
                vis[j]=1;
                dfs(j,i);
                vis[j]=0;
            }
        }
    }
};
```