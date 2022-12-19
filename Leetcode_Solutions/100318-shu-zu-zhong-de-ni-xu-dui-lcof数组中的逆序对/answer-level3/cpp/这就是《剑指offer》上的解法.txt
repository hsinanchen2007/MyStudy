
[参考链接](https://blog.csdn.net/ft_sunshine/article/details/103243034)
```
typedef long long LL;

class Solution {
public:
    int reversePairs(vector<int> mData) {
        int length = mData.size();
        if(length == 0)
            return 0;
        
        vector<int> mCopy(mData);  // 拷贝
        
        return amountOfInversePairs(mData, mCopy, 0, length-1);
    }
    
    LL amountOfInversePairs(vector<int> &mData, vector<int> &mCopy, int mStart, int mEnd){
        if(mStart == mEnd){
            mCopy[mStart] = mData[mStart];
            return 0;
        }
        
        LL halfLength = (mEnd - mStart) / 2;
        LL left = amountOfInversePairs(mCopy, mData, mStart, mStart + halfLength);  // 重要！（参数顺序）
        LL right = amountOfInversePairs(mCopy, mData, mStart + halfLength + 1, mEnd);
        
        LL i = mStart + halfLength;
        LL j = mEnd;
        LL indexOfmCopy = mEnd;
        LL mCount = 0;
        while(i >= mStart && j >= mStart + halfLength + 1){
            if(mData[i] > mData[j]){
                mCount += j-mStart-halfLength;
                mCopy[indexOfmCopy--] = mData[i--];
            }else{
                mCopy[indexOfmCopy--] = mData[j--];
            }
        }
        
        while(i >= mStart)
            mCopy[indexOfmCopy--] = mData[i--];
        while(j >= mStart + halfLength + 1)
            mCopy[indexOfmCopy--] = mData[j--];
        
        return left + right + mCount;
    }
    
};
```
