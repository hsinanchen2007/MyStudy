**仅供参考**
![image.png](https://pic.leetcode-cn.com/f9514adc18d6c236335f4c14167aeb96c0f14703fbed007c9834bec28e39a5a1-image.png)

```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;//定义步数，把后面的元素往前面复制
        for(int i=0;i<nums.size();i++)
        {
            nums[i-k]=nums[i];
            if(nums[i]==val)k++;
        }
        return nums.size()-k;
    }
};
```

