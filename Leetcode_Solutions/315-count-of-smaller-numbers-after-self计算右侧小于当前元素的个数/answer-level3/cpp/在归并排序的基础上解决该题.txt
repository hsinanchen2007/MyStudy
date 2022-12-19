参考精选题解归并排序写的C++版
```

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        //归并算法,nums不能动，动loc和rorder
        vector<int> loc;//索引
        vector<int> rorder;//逆序数
        MergeSort(nums,loc,rorder);
        
        return rorder;
    }
private:
    void MergeSort(const vector<int>& nums, vector<int>& loc, vector<int>& rorder)
    {
        for (int i=0; i < nums.size(); i++)
        {
            loc.push_back(i);
            rorder.push_back(0);
        }

        vector<int> tmpArray(nums.size(), 0);
        MSort(nums, tmpArray, loc, rorder, 0, nums.size() - 1);
    }

    void MSort(const vector<int>& nums, vector<int>& tmp, vector<int>& loc, vector<int>& rorder, int Left, int Right)
    {
        int Mid;
        if (Left < Right)
        {
            Mid = (Right + Left) / 2;
            MSort(nums, tmp, loc, rorder, Left, Mid);
            MSort(nums, tmp, loc, rorder, Mid + 1, Right);
            Merge(nums, tmp, loc, rorder, Left, Mid + 1, Right);
        }
    }

    void Merge( const vector<int>& Nums, vector<int>& TmpArray, vector<int>& Loc, vector<int>& Rorder, int Lpos, int Rpos, int RightEnd)
    {
        //归并前计算逆序数组
        int p1 = Lpos,p2 = Rpos;
        while (p1 < Rpos)
        {   //真实位置需要从Loc映射,Rorder和Nums
            while (p2 <= RightEnd&&Nums[Loc[p2]] < Nums[Loc[p1]]){p2++;}
            Rorder[Loc[p1++]] += p2 - Rpos;
        }

        //归并主体部分
        int i, LeftEnd, NumElements, TmpPos;
        LeftEnd = Rpos - 1;
        TmpPos = Lpos;
        NumElements = RightEnd - Lpos + 1;

        while (Lpos <= LeftEnd && Rpos <= RightEnd)
            if (Nums[Loc[Lpos]] <= Nums[Loc[Rpos]])
                TmpArray[TmpPos++] = Loc[Lpos++];    
            else
                TmpArray[TmpPos++] = Loc[Rpos++];
                
        //复制剩余元素到tmp数组
        while (Lpos <= LeftEnd)
            TmpArray[TmpPos++] = Loc[Lpos++];
           
        while (Rpos <= RightEnd)
            TmpArray[TmpPos++] = Loc[Rpos++];
           
        for (i = 0; i < NumElements; i++, RightEnd--)
            Loc[RightEnd] = TmpArray[RightEnd];
          
    }
};
```
