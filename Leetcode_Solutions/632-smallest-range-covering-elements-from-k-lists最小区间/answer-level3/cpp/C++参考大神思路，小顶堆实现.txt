```

class Ele {
public:
    Ele(int val, int arrayId, int pos) : value(val), arrayIdx(arrayId), posIdx(pos)
    {

    }

    int GetVal() const
    {
        return value;
    }

    int GetArrayIdx() const
    {
        return arrayIdx;
    }

    int GetPosIdx() const
    {
        return posIdx;
    }
private:
    int value;
    int arrayIdx;
    int posIdx;
};

// 小顶堆
bool operator < (const Ele &a, const Ele&b)
{
    return a.GetVal() > b.GetVal();
}

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Ele> elePri;
        int maxVal = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            int curVal = nums[i].front();
            if (curVal > maxVal) {
                maxVal = curVal;
            }
            elePri.push({ curVal, i, 0});
        }

        int leftV = -100001;
        int rightV = 100001;
        while (true) {
            int curL = elePri.top().GetVal();
            int arrIdx = elePri.top().GetArrayIdx();
            int posIdx = elePri.top().GetPosIdx();
            int curR = maxVal;
            if ((curR - curL) < (rightV - leftV)) {
                leftV = curL;
                rightV = curR;
            }
            posIdx++;
            if (posIdx >= nums[arrIdx].size()) {
                break;
            }
            elePri.pop();
            int curVal = nums[arrIdx][posIdx];
            if (curVal > maxVal) {
                maxVal = curVal;
            }
            elePri.push({ curVal, arrIdx, posIdx });
        }
        return { leftV, rightV };
    }
};

```


