```
class Solution {
public:
    int trap(vector<int>& height) {
        // 1 - 如果后面比前面高，则计算它们中间的储水量
        // 2 - 如果后面没有比前面高的，找出后面最高的那一个，计算他们中间的储水量

        if(height.empty()) return 0;

        int ret = 0;
        int pos = 0, len = height.size();
        // 寻找第一个非0位置
        for (; pos < len; pos++) {
            if (height[pos] != 0) {
                break;
            }
        }

        while(pos < len-1) {
            // 如果下一个的高度更高，则从下一个开始
            if (height[pos+1] >= height[pos]) {
                pos = pos + 1;
                continue;
            }

            int curPos = pos;       // 记录当前位置
        pos = pos + 1;
                continue;
            }

            int curPos = pos;       // 记录当前位置
            int tmpTotalStore = 0;  // 记录curPos到Pos间的柱子高度和
            int mHeight = 0;        // 此次处理中最高的高度
            int mHPos = curPos;     // 此次处理中最高高度的位置
            int tmpHeightStore = 0; // 记录mHPos到Pos间的柱子高度和
            for (pos++; pos < len; pos++) {
                if (mHeight <= height[pos]) {
                    mHeight = height[pos];
                    mHPos = pos;
                    tmpHeightStore = tmpTotalStore;
                }

                if (height[pos] >= height[curPos]) {
                    ret += (pos-curPos-1)*height[curPos];
                    ret -= tmpTotalStore;
                    break;
                }
                tmpTotalStore += height[pos];
            }

            if (pos == len) {
                if (mHeight != 0) {
                    ret += (mHPos - curPos - 1) * mHeight;
                    ret -= tmpHeightStore;
                    pos = mHPos;
                }
            }
        }

        return ret;
    }
};
```