### 解题思路
1）设置行标记位，表示(0,0), (0, 10), (0, 20), ... 是否可达
2）行遍历，分别从行标记位统计之后可达的位置数
3）如果行标记位为false，则停止当前行的遍历

![image.png](https://pic.leetcode-cn.com/eb4821ae1f99919d49beefe9e411f24f3e79c3890af1916e868cc555f1ef8f99-image.png)

### 代码

```cpp
# define PR pair<int, int>

class Solution {
public:
    int movingCount(int m, int n, int k) {
        return walk(m, n, k);
    }

    int walk(int m, int n, int k){
        vector<bool> valid(101, false);
        int res = 0;
        int y = 8;
        int i = 0;
        while(true){
            if(i%10 == 0){
                y -= 8;
                if(i >= n){
                    break;
                }
                if(y <= k){
                    valid[i] = true;
                }
            }else{
                y++;
            }
            if(y <= k){
                i++;
            }else{
                break;
            }
        }

        int j = 0;
        int x = 8;
        while(j < m){
            if(valid[0] == false){
                break;
            }
            if(j %10 == 0){
                x -= 8;
            }else{
                x++;
            }
            int tmp = 0;
            for(int i = 0; i < n; i += 10){
                int y = i/10;
                if(valid[i] == true){
                    if(k >= x + y){
                        if(k >= x + y + 9){
                            tmp += min(10, n - i);
                        }else{
                            tmp += min(k - x - y + 1, n - i);
                        }
                    }else{
                        valid[i] = false;
                        break;
                    }
                }
            }
            // cout<<"row = "<<j<<", cnt = "<<tmp<<endl;
            res += tmp;
            j++;
        }
        return res;
    }
};
```