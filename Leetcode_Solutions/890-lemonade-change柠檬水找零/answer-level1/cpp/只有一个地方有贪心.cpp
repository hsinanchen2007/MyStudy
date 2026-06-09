题目很简单，看起来不像是贪心，不过里面有一点可以体现那么一丁点贪心，就是当来一个20元，应该优先找10元+5元的选择，而不是找3个5元，例子就是下面的：bills = [5,5,5,5,10,20,10]
```
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int packet[3] = {0, 0, 0}; /* 分别记录钱包5元、10元、20元的张数 */
        
        for (auto bi:bills) {
            if (5 == bi) { 
                packet[0]++; /* 如果是5块，不用找零钱，直接收下即可 */
            } 
            else if (10 == bi) {
                if (packet[0]>=1) { /* 如果是10块,如果有至少一个5块,就可以找零，如果没有，直接失败 */
                    packet[1]++;
                    packet[0]--;
                } else {
                    return false;
                }  
            } 
            else { /* 如果是20块，有两种找零方案：1个10+1个5; 3个5块,且应该优先找10块,返例：[5,5,5,5,10,20,10] */
                if (packet[0]>= 1 && packet[1]>= 1) {
                    packet[0]--;
                    packet[1]--;
                    packet[2]++;
                } else if (packet[0]>= 3) {
                    packet[0]-=3;
                    packet[2]++;
                } else {
                    return false;    
                } 
            }
        }
        return true;  
    }
};
```

```

