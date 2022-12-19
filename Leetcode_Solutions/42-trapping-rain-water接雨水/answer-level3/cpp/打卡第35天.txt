官方第二种方法
```
class Solution {
public:
    int trap(vector<int>& height) {
        
        int result = 0;
        int s = height.size();
        if(s==0) return
        vector<int> max_left(s,0), max_right(s,0);
         max_left[0] = height[0];
        for(int i=1;i<s;i++){
            max_left[i] = max(height[i],max_left[i-1]);
        }
        max_right[s-1] = height[s-1];
        for(int i=s-2;i>=0;i--){
            max_right[i] = max(max_right[i+1],height[i]);
        }
        for(int i = 0;i<s;i++){
            result += (min(max_left[i],max_right[i]) - height[i]);
        }


        return result;
    
    }
};
```
