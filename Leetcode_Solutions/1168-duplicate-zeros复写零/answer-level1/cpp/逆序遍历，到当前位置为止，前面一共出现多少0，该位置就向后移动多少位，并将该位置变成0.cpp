```
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        // 方法1：双重循环
        // for(int i=arr.size()-2;i>=0;i--)
        // {
        //     if(arr[i]==0)
        //     {
        //         for(int j=arr.size()-2;j>i;j--)
        //         {
        //             arr[j+1] = arr[j];
        //         }
        //         arr[i+1] = 0;
        //     }
        // }
        
        //方法2：单重循环
        vector<int> zeros; // 到当前位置为止，前面一共出现多少0
        int count = 0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)
                count++;
            zeros.push_back(count);
        }
        
        // 逆序遍历，到当前位置为止，前面一共出现多少0，该位置就向后移动多少位，并将该位置变成0
        for(int i=arr.size()-1;i>=0;i--)
        {
            count = zeros[i];
            if(count > 0)
            {
                if(i + count < arr.size())
                {
                    arr[i+count] = arr[i];
                }
                arr[i] = 0;
            }
        }
        
    }
};
```