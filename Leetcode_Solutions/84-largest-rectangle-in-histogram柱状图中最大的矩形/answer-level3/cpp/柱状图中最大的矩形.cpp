class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0)
            return 0;
        int start = 0;
        int end = heights.size()-1;
        return maxarea(heights, start, end);        
    }

    int maxarea(vector<int>& heights, int start, int end)
    {
        if(start == end)
            return heights[start];
        int min_height = INT_MAX;
        int mid_index = start;
        for(int i = start; i<=end; i++)
        {
            if(heights[i] <= min_height)
            {
                min_height = heights[i];
                mid_index = i;
            }
        }
        int area1 = min_height*(end-start+1);
        int area2 = INT_MIN;
        int area3 = INT_MIN;
        if(mid_index > start)
        {
            area2 = maxarea(heights, start, mid_index-1);
        }

        if(mid_index < end)
        {
            area3 = maxarea(heights, mid_index+1, end);
        }

        return max(max(area1, area2), area3);

    }
};