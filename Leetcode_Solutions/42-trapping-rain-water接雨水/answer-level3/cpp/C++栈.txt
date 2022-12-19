### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<3) return 0;
        int rain=0;

        stack<int> st;

        for(int i=0; i<height.size(); ++i)
        {
            if(st.empty() || height[i]<=height[st.top()])
            {
                st.push(i);
            }
            else
            {
                while(height[i]>height[st.top()])
                {
                    int tmp=height[st.top()];
                    st.pop();
                    if(st.empty()) break;
                    int shorter_h=min(height[st.top()],height[i]);
                    int h=shorter_h-tmp;
                    rain+=h*(i-st.top()-1);
                    
                }
                st.push(i);
            }
        }

        return rain;
    }

    // int calculate_rain(vector<int>& height, int start, int end)
    // {
    //     int sum=0;
    //     int shorter=min(height[start],height[end]);
    //     for(int i=start+1; i<end; ++i)
    //     {
    //         sum+=(shorter-height[i])>0?(shorter-height[i]):0;
    //     }
    //     return sum;
    // }
};
```