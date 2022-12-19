错误解法：本来一开始想这题应该是把最接近的石头碰完就行了，然后想先排序，拿最大的两个碰完之后，剩余的塞回去，再排序，再取最大的两个碰，如此循环剩0或1个石头，输出数值。但是发现有个测试用例过不去[31, 26, 33, 21, 40]. 这种思路出来的是9，但是结果却是5. 正确顺序是先用40和26碰剩余14，然后33碰21余12、31碰14余17，最后12碰17余5。

后面经提醒，这个也是个背包问题，背包的目标值是所有石头重量的一半。那直接套路解就行了。

```
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        
        for (int s : stones) {
            sum += s;
        }
        int target = sum/2;
        vector<int> dp = vector<int>(target + 1, 0);
        long size = stones.size();
        for (int i = 0; i<size; i++) {
            int s = stones[i];
            for (int j=target; j>=s; j--) {
                dp[j] = max(dp[j], dp[j-s] + s);
            }
        }
        return sum - 2 *dp.back();;
    }
};
```