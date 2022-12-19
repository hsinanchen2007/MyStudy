暴力破解，起始索引在位置0，然后索引每向右移动一位，对比一次左右的值。若相等，返回该索引，若不相等，修改左右数组，以此类推。

注释相对完整清晰。
```
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        int lsum = 0;
        int rsum = 0;
        int ans = -1; //若不存在中心索引，返回初始值 -1
        for(int i = 1; i<size; ++i) rsum += nums[i]; //先得到索引后边元素的和
        for(int j = 0; j <size; ++j) //索引从位置0开始向右移动
        {
            if(lsum == rsum) //若左右相等，返回该值，跳出循环
            {
                ans = j;
                break;
            }
            if(j < size - 1) //左边加上nums[j]，右侧减去[j+1],此时，候补索引值为j+1
            {
                lsum += nums[j];
                rsum -= nums[j+1];
                cout << lsum << "  " <<rsum << endl;
            }
        }
        return ans;
    }
};
```