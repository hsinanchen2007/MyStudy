### 解题思路
比赛的时候没时间做了。。。。
BFS的题，一层一层遍历，位数越多，组成的数组越大；
从数字1到9遍历，先搜索的结果肯定大于后搜索的结果；
最后再将剩余的数组按照9到0的顺序输出。

结构体写的有点丑。。

### 代码

```cpp
class Solution {
public:
    struct node {
        int digits[10];
        node () {
            for (int i = 0; i < 10; i++) {
                digits[i] = 0;
            }
        }
        void decrease(int i) {
            digits[i]--;
        }
        void add(int i) {
            digits[i]++;
        }
        int getValue(int i) {
            return digits[i];
        }
        void SetNode(node& iNode) {
            for (int i = 0; i < 10; i++) {
                digits[i] = iNode.getValue(i);
            }
        }
        int getCount() {
            int ans = 0;
            for (int i = 0; i < 10; i ++) {
                ans += (digits[i] * i);
            }
            return ans;
        }
    };
    string largestMultipleOfThree(vector<int>& digits) {
        node startNode;
        for (auto item : digits) {
            startNode.add(item);
        }
        queue<node> bfsQueue;
        bfsQueue.push(startNode);
        node ansNode;
        bool flag = true;
        while(! bfsQueue.empty() && flag) {
            int queueLength = bfsQueue.size();
            for (int i = 0; i < queueLength; i++) {
                node currentNode = bfsQueue.front();
                bfsQueue.pop();
                if ((currentNode.getCount()%3 == 0)) {
                    ansNode.SetNode(currentNode);
                    flag = false;
                    break;
                }
                for (int i = 1; i < 10; i++) {
                    if (currentNode.getValue(i) > 0) {
                        node temp;
                        temp.SetNode(currentNode);
                        temp.decrease(i);
                        bfsQueue.push(temp);
                    }
                }
            }
        }
        string ans("");
        for (int i = 9; i >= 0; i--) {
            while (ansNode.getValue(i) > 0) {
                ans.push_back('0' + i);
                ansNode.decrease(i);
            }
        }
		while(ans.size() > 1 && ans[0] == '0') {
			ans.erase(ans.begin());
		}
        return ans;
    }
};
```