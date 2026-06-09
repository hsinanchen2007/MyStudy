### 解题思路
1）使用快排算法排序数组；
2）统计各数字出来的次数，不连续的时候要插入0；
3）使用O(n)算法遍历统计结果。

### 代码

```cpp
class Solution {
public:

    bool valid(vector<int> &lst, int W){
        lst.push_back(0);
        int sz = lst.size();
        int pre = 0;
        vector<int> deltas(sz, 0);
        for(int i = 0; i < sz; i++){
            pre += deltas[i];
            if(pre < lst[i]){
                int delta = lst[i] - pre;
                pre = lst[i];
                if(i + W < sz){
                    deltas[i+W] -= delta;
                }
            }else if(pre > lst[i]){
                return false;
            }
        }
        return true;
    }

    bool isNStraightHand(vector<int>& hand, int W) {
        int sz = hand.size();
        if(sz%W){
            return false;
        }else{
            sort(hand.begin(), hand.end());
            vector<int> lst;
            int i = 0, j = 0;
            while(i < sz){
                while(j < sz && hand[i] == hand[j]){
                    j++;
                }
                lst.push_back(j - i);
                if(j >= sz){
                    break;
                }else if(hand[j] != hand[j-1] + 1){
                    lst.push_back(0);
                }
                i = j;
            }
            // print(lst);
            return valid(lst, W);
        }
    }

    void print(vector<int> &lst){
        for(int val : lst){
            cout<<val<<", ";
        }
        cout<<endl;
    }
};
```