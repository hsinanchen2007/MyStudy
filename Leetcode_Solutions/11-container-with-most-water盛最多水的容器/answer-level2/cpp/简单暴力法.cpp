class Solution {


public:
    int maxArea(vector<int>& height) {
    int max_are = 0 ;

    int s;

    for(int i=0 ;i<height.size()-1;i++){
        for (int j=i+1 ;j<height.size();j++){
            if (height[i] >= height[j])
            {
                s = height[j]*(j-i);
                
                
            }
            else
            {
                s = height[i]*(j-i);
            }
            max_are = s > max_are ?s:max_are;

           

        }
        
        
    }
    return max_are;
    }

   
};