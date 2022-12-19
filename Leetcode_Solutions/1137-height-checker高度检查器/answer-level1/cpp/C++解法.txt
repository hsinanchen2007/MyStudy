class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> tmp=heights;
        sort(heights.begin(),heights.end());
        int count=0;
        for(int i=0;i<tmp.size();i++)
        {
            if(heights[i]!=tmp[i])
                count++;
        }
        return count;
        
    }
};
C++，执行用时8ms,内存消耗8.4ms，直接用sort 函数在排序后比较对应元素的位置。