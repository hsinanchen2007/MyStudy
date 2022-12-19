1.前缀和+窗口滑动
2.前缀和+正向单调递增栈 +反向单调栈

1.前缀和+窗口滑动：
1）计算前缀和（要在前面补0）
2）设置滑窗left和right，因此前缀和已知，所以left和right之间的差值已知
注意presum[iright] - presum[ileft]计算的是left+1~right的和，而不是left~right的和
3）已知L和M，分别设置滑窗，然后加和，获得最大值

```cpp
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int> &A, int L, int M)
    {
        vector<int> presum = vector<int>(A.size()+1, 0);
        int maxvalue = 0;

        for (int i = 1; i < presum.size(); i++) {
			presum[i] = presum[i - 1] + A[i-1];
        }

        for (int i = 0; i + L < presum.size(); i++) {
            int ileft = i;
            int iright = i + L;
            int iSum = presum[iright] - presum[ileft];

            for (int j = 0; j + M < presum.size(); j++) {
                int jleft = j;
                int jright = j + M;

                if (jleft >= iright || jright <= ileft) {
                    int jSum = presum[jright] - presum[jleft];
                    maxvalue = max(maxvalue, iSum + jSum);
                }
            }
        }

        return maxvalue;
    }
};
```
2.前缀和+正向最大值 +反向最大值
由于方法1为了求最大值，存在很多无效加和。实际上方法1只是为了找到L窗口左右两边的M窗口的最大值；
因此我们提前计算一遍i左边窗口M的最大值LeftMMAX，i右边的窗口M最大值RightMMAX，最终取L+MAX(RightMMAX,LeftMMAX)
注意：这里面边界条件不是很好想，虽然效率高，但是没必要弄得这么难想。
```
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int> &A, int L, int M)
    {
        vector<int> presum = vector<int>(A.size() + 1, 0);
        vector<int> leftMax = vector<int>(A.size() + 1, 0);
        vector<int> rightMax = vector<int>(A.size() + 1, 0);
        int maxvalue = 0;

        for (int i = 1; i < presum.size(); i++) {
            presum[i] = presum[i - 1] + A[i - 1];
        }

        int leftmaxvalue = 0;
        for (int i = M; i < presum.size(); i++) {
            leftmaxvalue = max(leftmaxvalue, presum[i] - presum[i - M]);
            leftMax[i] = leftmaxvalue;
        }

        int rightmaxvalue = 0;
        for (int i = presum.size() - 1 - M; i >= 0; i--) {
            rightmaxvalue = max(rightmaxvalue, presum[i + M] - presum[i]);
            rightMax[i] = rightmaxvalue;
        }

        for (int i = 0; i + L < presum.size(); i++) {
            int ileft = i;
            int iright = i + L;
            int iSum = presum[iright] - presum[ileft];

            maxvalue = max(maxvalue,iSum + leftMax[ileft]);
            maxvalue = max(maxvalue,iSum + rightMax[iright]);
            int a =0;
        }

        return maxvalue;
    }
};
```






