### 解题思路
![image.png](https://pic.leetcode-cn.com/573b69b89f13829a2a48da11e6a28bacf7057c343428ca4d84633188f4944d56-image.png)

石头重量是正数，且<=1000, 那么自己构造一个以重量当做index的数组完全可以，这样就避免了排序。
从大到小遍历一遍即可，新重量再放入数组。数组记录的是每种重量的石头数量。

### 代码

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()<=0)
            return 0;
        if(stones.size() == 1)
            return stones[0];
        int arr[1001] = {0};
        for(int i=0;i < stones.size(); i++){
            arr[stones[i]]++;
        }
        int j = 1000;
        int j_next;
        while(j >= 0){
            arr[j] %= 2;
            if(arr[j] == 0){
                j--;
                continue;
            }
            else{
                j_next = j-1;
                while(j_next >=0 && arr[j_next] == 0)
                    j_next--;
                if(j_next < 0)
                    break;
                else{
                    arr[j-j_next]++;
                    arr[j_next]--;
                    j--;
                }
            }
        }
        if(j < 0)
            return 0;
        else
            return j;
    }
};
```