### 解题思路
每一个点，统计和它相同斜率的其他点

### 代码

```cpp
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 3) {
            return points.size();
        }

        int result = 0;
        for (int i = 0; i < points.size(); ++i) {
            int duplicate = 0;
            int curMax = 0;
            unordered_map<string, int> oneline;

            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    duplicate += 1;
                    continue;
                }

                int diffX = points[j][0] - points[i][0];
                int diffY = points[j][1] - points[i][1];

                int temp = gcd(diffX, diffY);
                string key = to_string(diffX / temp) + "/" + to_string(diffY / temp);

                oneline[key]++;
                curMax = max(curMax, oneline[key]);
            }

            result = max(result, curMax + duplicate + 1);
        }

        return result;
    }
private:
    int gcd(int a, int b)
    {
        if (b == 0) {
            return a;
        }

        return gcd(b, a % b);
    }
};

```