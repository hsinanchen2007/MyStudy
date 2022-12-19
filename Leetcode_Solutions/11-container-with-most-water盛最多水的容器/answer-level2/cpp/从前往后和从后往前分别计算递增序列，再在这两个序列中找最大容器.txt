```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx = 0;
        int i = 0;
        int j = height.size()-1;
        vector<int> left;
        vector<int> right;

        for(i=0; i<height.size(); i++)
        {
            if(left.empty() || height[i]>height[left.back()])
            {
                left.push_back(i);
            }
        }
        for(j=height.size()-1; j>=0; j--)
        {
            if(right.empty() || height[j]>height[right.back()])
            {
                right.push_back(j);
            }
        }
        for(i=0; i<left.size(); i++)
        {
            for(j=0; j<right.size(); j++)
            {
                mx = max(mx, (right[j]-left[i])*min(height[right[j]], height[left[i]]));
            }
        }
        return mx;
    }
};
```
```

class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx = 0;
        int i = 0;
        int j = height.size()-1;
        while(i<j)
        {
            mx = max(mx, (j-i)*min(height[i], height[j]));
            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return mx;
    }
};
```
